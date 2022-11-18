/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-10-29     Rbb666       The first version
 */

#include <lvgl.h>
#include <stdbool.h>
#include <rtdevice.h>

#include "lv_port.h"

#define RT_TOUCH_EVENT_MOVE (3) /* Touch move event */

#define POINT_NUMBER 1

static rt_device_t ts; /* Touch device handle, Touchscreen */
static struct rt_touch_data *read_data;

static rt_int16_t last_x = 0;
static rt_int16_t last_y = 0;

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

    rt_thread_mdelay(2);

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

lv_indev_t *touch_indev;

void lv_port_indev_init(void)
{
    ts = rt_device_find("touch");
    RT_ASSERT(ts != RT_NULL);

    rt_device_open(ts, RT_DEVICE_FLAG_INT_RX);

    read_data = (struct rt_touch_data *)rt_calloc(POINT_NUMBER, sizeof(struct rt_touch_data) * POINT_NUMBER);

    static lv_indev_drv_t indev_drv;        /* Descriptor of a input device driver */
    lv_indev_drv_init(&indev_drv);          /* Basic initialization */
    indev_drv.type = LV_INDEV_TYPE_POINTER; /* Touch pad is a pointer-like device */
    indev_drv.read_cb = touchpad_read;      /* Set your driver function */

    /* Register the driver in LVGL and save the created input device object */
    touch_indev = lv_indev_drv_register(&indev_drv);  
}
