/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-10-18     Rbb666       The first version
 */

#include <lvgl.h>
#include <rtthread.h>

#include "lv_port.h"

#define FBIOGET_FSCREENINFO 0x4602

/*A static or global variable to store the buffers*/
static lv_disp_draw_buf_t disp_buf;

/*Descriptor of a display driver*/
static lv_disp_drv_t disp_drv;

static rt_device_t device;
static struct rt_device_graphic_info info;
static struct fb_fix_screeninfo fb_info;

#define line_length 480 * sizeof(rt_uint32_t) / 4

static void disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
{
    int x1, x2, y1, y2;

    x1 = area->x1;
    x2 = area->x2;
    y1 = area->y1;
    y2 = area->y2;

    /*Truncate the area to the screen*/
    int32_t act_x1 = area->x1 < 0 ? 0 : area->x1;
    int32_t act_y1 = area->y1 < 0 ? 0 : area->y1;
    int32_t act_x2 =
        area->x2 > (int32_t)info.width - 1 ? (int32_t)info.width - 1 : area->x2;
    int32_t act_y2 =
        area->y2 > (int32_t)info.height - 1 ? (int32_t)info.height - 1 : area->y2;

    lv_coord_t w = (act_x2 - act_x1 + 1);

    long int location = 0;

    /* 32 bit per pixel */
    if (info.bits_per_pixel == 32 || info.bits_per_pixel == 24)
    {
        uint32_t *fbp32 = (uint32_t *)fb_info.smem_start;
        uint32_t y;
        for (y = act_y1; y <= act_y2; y++)
        {
            location = act_x1 + y * line_length;

            rt_memcpy(&fbp32[location], (uint32_t *)color_p,
                      (act_x2 - act_x1 + 1) * 4);

            color_p += w;
        }
    }

    struct rt_device_rect_info rect_info;

    rect_info.x = x1;
    rect_info.y = y1;
    rect_info.width = x2 - x1 + 1;
    rect_info.height = y2 - y1 + 1;

    rt_device_control(device, RTGRAPHIC_CTRL_RECT_UPDATE, &rect_info);

    lv_disp_flush_ready(disp_drv);
}

void lv_port_disp_init(void)
{
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

    RT_ASSERT(info.bits_per_pixel == 8 || info.bits_per_pixel == 16 ||
              info.bits_per_pixel == 24 || info.bits_per_pixel == 32);

    static lv_color_t *buf1, *buf2;

    buf1 = (lv_color_t *)rt_malloc(info.width * info.height * sizeof(lv_color_t));
    buf2 = (lv_color_t *)rt_malloc(info.width * info.height * sizeof(lv_color_t));

    if (buf1 == NULL || buf2 == NULL)
    {
        rt_kprintf("malloc draw buffer fail!!\n");
        return;
    }

    /*Initialize `disp_buf` with the buffer(s). With only one buffer use NULL instead buf_2 */
    lv_disp_draw_buf_init(&disp_buf, buf1, buf2, info.width * info.height);

    lv_disp_drv_init(&disp_drv); /*Basic initialization*/

    /*Set the resolution of the display*/
    disp_drv.hor_res = info.width;
    disp_drv.ver_res = info.height;

    /*Set a display buffer*/
    disp_drv.draw_buf = &disp_buf;

    /*Used to copy the buffer's content to the display*/
    disp_drv.flush_cb = disp_flush;

    /*Finally register the driver*/
    lv_disp_drv_register(&disp_drv);
}
