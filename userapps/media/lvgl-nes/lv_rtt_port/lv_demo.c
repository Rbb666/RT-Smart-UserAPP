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

#include "nes_simple_test.h"

void lv_user_gui_init(void)
{
    /* display demo; you may replace with your LVGL application at here */
    // extern void lv_demo_music(void);
    // lv_demo_music();

    extern void file_explorer_simple_test(void);

    // file_explorer_simple_test();
    nes_simple_test();
}

int main(void)
{
    extern int lvgl_thread_init(void);
    lvgl_thread_init();

    return 0;
}
