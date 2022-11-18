## 开发流程

## 1、RT-Smart 环境搭建

下载 RT-Smart 用户态应用代码：

```
git clone https://github.com/RT-Thread/userapps.git
```

进入到 userapps 目录，克隆 RT-Thread rt-smart 分支

```
git clone -b rt-smart https://gitee.com/rtthread/rt-thread.git
```

> 更详细环境配置请移步到—> [RT-Thread-优雅の在D1S上运行RT-Smart](https://club.rt-thread.org/ask/article/c0609a2215117c31.html)

## 2、配置工具链

在 userapps/tools 目录下运行 get_toolchain.py 的脚本，会下载对应的工具链并展开到 userapps/tools/gun_gcc 目录。后面的工具链名称可以是 arm | riscv64。

这里以 D1s 为例，D1s 是 RISCV-64 架构的，所以输入下面的命令：

```shell
python3 get_toolchain.py riscv64
```

在 userapps 目录下，运行 smart-env.sh 配置工具链路径，目前支持的参数可以是 arm | riscv64

```shell
source smart-env.sh riscv64
```

## 3、获取 lvgl 主线代码

进入到 **userapps** 目录，新建 **media** 文件夹来存放 lvgl 相关的代码，克隆 lvgl 主线代码到本地

```shell
git clone https://github.com/lvgl/lvgl.git
```

## 4、内核驱动实现

**显示部分：**

这部分我们可以参考 qemu-vexpress-a9 中 [drv_clcd.c](https://gitee.com/rtthread/rt-thread/blob/rt-smart/bsp/qemu-vexpress-a9/drivers/drv_clcd.c) 的实现方法。在用户态，要是想获取并操作 lcd，驱动至少需要实现：**drv_clcd_init + drv_clcd_control** 两个 ops 函数。

在 **drv_clcd_control** 中，我们需要对以下几种 cmd 进行处理：

* **RTGRAPHIC_CTRL_RECT_UPDATE**：通知更新图形设备
* **RTGRAPHIC_CTRL_GET_INFO**：获取 LCD 的基本信息，包括像素像素格式，分辨率等
* **FBIOGET_FSCREENINFO**：获取 FrameBuffer 设备的固定参数信息。固定参数信息使用 struct fb_fix_screeninfo 结构体来描述
* **FBIOGET_VSCREENINFO**：获取 LCD 的可变参数信息，包括屏幕的像素，尺寸等信息

**触摸部分：**

用户态要是想获取触摸芯片的坐标，底层驱动至少需要实现 touch_ops 的：probe + init + read_point，即探测，初始化，读取触摸设备的函数。

## 5、用户态接口对接

用户态目录结构如下，需要在 `media/lvgl/` 目录下新建名为 `lv_rtt_port` 、`packages` 等文件夹。

```
lvgl
├── lv_rtt_port
│   ├── SConscript
│   ├── lv_conf.h
│   ├── lv_port_disp.c
│   └── lv_port_indev.c
├── packages
│   ├── LVGL-latest
│   ├── lv_music_demo-latest
│   └── SConscript
├── SConscript
├── SConstruct
├── pkg_config.h
```

* `lv_rtt_port` 是移植的关键部分对接程序，包括了显示，触摸接口，主要需要我们自己编写。

* `LVGL-latest` 从 `https://github.com/lvgl/lvgl`上获取最新代码，不需要修改。
* lv_music_demo-latest 是 lvgl 的 音乐播放器 demo，从 `https://github.com/RT-Thread-packages/lv_demo_music.git` 获取最新代码，不需要修改。
* lv_conf.h 文件由 `lvgl`目录中的 `lvgl_conf_template.h` 修改而来。配置如下，具体可以按照自己的屏幕参数修改。

```c
#define LV_COLOR_16_SWAP    1
#define LV_COLOR_DEPTH      32
#define LV_USE_PERF_MONITOR 1

/* music player demo */
#define LV_USE_DEMO_RTT_MUSIC       1
#define LV_DEMO_RTT_MUSIC_AUTO_PLAY 1
#define LV_FONT_MONTSERRAT_12       1
#define LV_FONT_MONTSERRAT_16       1
#define LV_COLOR_SCREEN_TRANSP      1
```

### 5.1、显示接口

核心是在 `lv_rtt_port` 中，而具体需要关注的文件就是 `lv_port_disp.c` 文件，触摸我们可以先不急着加，先将显示接口对接上。

在 `RT-Thread` 中，主要通过 `rt_device_xxx` 来操作 LCD 设备，首先通过 rt_device_find 函数查找 lcd 设备，找到设备后可以通过 device 句柄来操作 lcd 设备。 

```c
/* LCD Device Init */
device = rt_device_find("lcd");
RT_ASSERT(device != RT_NULL);

if (rt_device_open(device, RT_DEVICE_OFLAG_RDWR) != RT_EOK)
{
    rt_kprintf("open lcd devce fail\n");
    return;
}

rt_device_control(device, RTGRAPHIC_CTRL_GET_INFO, &info);
rt_device_control(device, FBIOGET_FSCREENINFO, &fb_info);
```

用户态只要获取到 framebuffer 就可以进行对 lcd 进行操作了。值得注意的是，在用户态我们不能直接使用 `RTGRAPHIC_CTRL_GET_INFO` 返回的 framebuffer 变量，而是需要使用 `FBIOGET_FSCREENINFO` 得到 smem_start （地址空间的起始地址），因为分配地址空间的起始地址与长度将会被填充到 fb_fix_screeninfo 结构的 smem_start 和 smem_len 的两个变量中。

于是，我们就可以通过向 smem_start 地址中填充颜色数据的方式让 lcd 显示各种颜色了。 

### 5.2、触摸接口

触摸接口需要关注的文件是 `lv_port_indev.c` 文件，主要通过 `rt_device_find` 查找 touch 设备，找到设备后可以通过 device 句柄来操作 touch 设备。

```c
#define POINT_NUMBER 1

static rt_device_t ts;
static struct rt_touch_data *read_data;

ts = rt_device_find("touch");
rt_device_open(ts, RT_DEVICE_FLAG_INT_RX);
read_data = (struct rt_touch_data *)rt_calloc(POINT_NUMBER, sizeof(struct rt_touch_data) * POINT_NUMBER);
```

获取坐标函数在调用 `rt_device_read` 函数后，入参 read_data 中就保存了坐标信息，然后传递给 LVGL 的 lv_indev_data_t 结构体中即可。

```c
static bool touchpad_is_pressed(void)
{
    if (POINT_NUMBER == rt_device_read(ts, 0, read_data, POINT_NUMBER))
    {
        if (read_data->event == RT_TOUCH_EVENT_MOVE)
        {
            /* swap x and y */
            rt_uint16_t tmp_x = read_data->x_coordinate;
            rt_uint16_t tmp_y = read_data->y_coordinate;

            /* restore data */
            last_x = tmp_x;
            last_y = tmp_y;

            return true;
        }
    }
    return false;
}

static void touchpad_get_xy(rt_int16_t *x, rt_int16_t *y)
{
    *x = last_x;
    *y = last_y;
}

static void touchpad_read(lv_indev_drv_t *indev, lv_indev_data_t *data)
{
    if (touchpad_is_pressed())
    {
        data->state = LV_INDEV_STATE_PRESSED;
        touchpad_get_xy(&data->point.x, &data->point.y);
    }
    else
    {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}
```

## 6、真机效果

这里以柿饼派M7为例，将编译出来的用户态可执行文件打包，使用 xfel 工具烧录到板子上的 EMMC 中。在串口终端输入可执行文件名称来启动用户态程序。

![](https://oss-club.rt-thread.org/uploads/20221117/a1d8c457ed4ab664f0fa9de4dfa1aa23.png)

---

最终效果如下，在屏幕分辨率为 480*272，RGB565 32位色深下，lvgl 在用户态中的帧率整体保持在 60fps，满足了使用需求。![](https://oss-club.rt-thread.org/uploads/20221117/21dcdb590899c601cb094ecaa3e6f9d2.png.webp)

> 