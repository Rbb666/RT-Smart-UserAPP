/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author        Notes
 * 2022-10-21     Rbb666        first-commit
 */

#include <lvgl.h>
#include <rtthread.h>

#include "nes_simple_test.h"

#define DBG_TAG "LVGL"
#define DBG_LVL DBG_INFO
#include <rtdbg.h>

extern void lv_port_disp_init(void);
extern void lv_port_indev_init(void);
extern void lv_user_gui_init(void);

void lv_user_gui_init(void)
{
    /* display demo; you may replace with your LVGL application at here */
    extern void lv_demo_music(void);
    lv_demo_music();
}

#if LV_USE_LOG
static void lv_rt_log(const char *buf)
{
    LOG_I(buf);
}
#endif /* LV_USE_LOG */

int main(void)
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

    return 0;
}
