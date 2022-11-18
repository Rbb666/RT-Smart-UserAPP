/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: MIT
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-10-18     Meco Man     the first version
 * 2022-05-10     Meco Man     improve rt-thread initialization process
 */

#ifdef __RTTHREAD__

#include <lvgl.h>
#include <rtthread.h>

#define DBG_TAG "LVGL"
#define DBG_LVL DBG_INFO
#include <rtdbg.h>

#ifndef PKG_LVGL_THREAD_STACK_SIZE
#define PKG_LVGL_THREAD_STACK_SIZE 8192
#endif /* PKG_LVGL_THREAD_STACK_SIZE */

#ifndef PKG_LVGL_THREAD_PRIO
#define PKG_LVGL_THREAD_PRIO (RT_THREAD_PRIORITY_MAX * 2 / 3)
#endif /* PKG_LVGL_THREAD_PRIO */

extern void lv_port_disp_init(void);
extern void lv_port_indev_init(void);
extern void lv_user_gui_init(void);

#if LV_USE_LOG
static void lv_rt_log(const char *buf)
{
    LOG_I(buf);
}
#endif /* LV_USE_LOG */

static void lvgl_thread_entry(void *parameter)
{
#if LV_USE_LOG
    lv_log_register_print_cb(lv_rt_log);
#endif /* LV_USE_LOG */
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();
    lv_user_gui_init();

    /* handle the tasks of LVGL */
    while (1)
    {
        lv_task_handler();
        rt_thread_mdelay(LV_DISP_DEF_REFR_PERIOD);
    }
}

int lvgl_thread_init(void)
{
    rt_thread_t thread = NULL;

    thread = rt_thread_create("LVGL", lvgl_thread_entry, NULL, PKG_LVGL_THREAD_STACK_SIZE, PKG_LVGL_THREAD_PRIO, 10);
    if (thread == NULL)
    {
        return -1;
    }
    rt_thread_startup(thread);

    return 0;
}
#endif /*__RTTHREAD__*/
