/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-10-29     Rbb666       The first version
 */

#ifndef LV_PORT_H__
#define LV_PORT_H__

#include <rtthread.h>

/**
 * graphic device information structure
 */
struct rt_device_graphic_info
{
    rt_uint8_t pixel_format;   /**< graphic format */
    rt_uint8_t bits_per_pixel; /**< bits per pixel */
    rt_uint16_t pitch;         /**< bytes per line */

    rt_uint16_t width;  /**< width of graphic device */
    rt_uint16_t height; /**< height of graphic device */

    rt_uint8_t *framebuffer; /**< frame buffer */
    rt_uint32_t smem_len;    /**< allocated frame buffer size */
};

/**
 * rectangle information structure
 */
struct rt_device_rect_info
{
    rt_uint16_t x;      /**< x coordinate */
    rt_uint16_t y;      /**< y coordinate */
    rt_uint16_t width;  /**< width */
    rt_uint16_t height; /**< height */
};

struct fb_fix_screeninfo
{
    char id[16];
    unsigned long smem_start;
    uint32_t smem_len;

    uint32_t line_length;
};

struct rt_touch_data
{
    rt_uint8_t event;         /* The touch event of the data */
    rt_uint8_t track_id;      /* Track id of point */
    rt_uint8_t width;         /* Point of width */
    rt_uint16_t x_coordinate; /* Point of x coordinate */
    rt_uint16_t y_coordinate; /* Point of y coordinate */
    rt_tick_t timestamp;      /* The timestamp when the data was received */
};

#endif
