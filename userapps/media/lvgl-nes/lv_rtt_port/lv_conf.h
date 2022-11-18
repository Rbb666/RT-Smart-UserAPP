/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author        Notes
 * 2021-10-18     Meco Man      First version
 */

#ifndef LV_CONF_H
#define LV_CONF_H

#define LV_COLOR_DEPTH      32
#define LV_USE_PERF_MONITOR 1
#define LV_DPI_DEF          89  /*480x272*/
#define LV_DISP_DEF_REFR_PERIOD 20  /*[ms]*/
#define LV_USE_LOG      1

#define LV_USE_FILE_EXPLORER    1
#if LV_USE_FILE_EXPLORER
    /*Maximum length of path*/
    #define LV_FILE_EXPLORER_PATH_MAX_LEN        (128)
    /*Quick access bar, 1:use, 0:not use*/
    /*Requires: lv_list*/
    #define LV_FILE_EXPLORER_QUICK_ACCESS        0
#endif

#define LV_USE_FS_STDIO 1
#if LV_USE_FS_STDIO
    #define LV_FS_STDIO_LETTER '/'     /*Set an upper cased letter on which the drive will accessible (e.g. 'A')*/
    #define LV_FS_STDIO_PATH "/"         /*Set the working directory. File/directory paths will be appended to it.*/
    #define LV_FS_STDIO_CACHE_SIZE  0   /*>0 to cache this number of bytes in lv_fs_read()*/
#endif

/* music player demo */
#define LV_USE_DEMO_RTT_MUSIC       0
#define LV_DEMO_RTT_MUSIC_LARGE     0
#define LV_DEMO_RTT_MUSIC_AUTO_PLAY 0
#define LV_FONT_MONTSERRAT_12       1
#define LV_FONT_MONTSERRAT_16       1
#define LV_COLOR_SCREEN_TRANSP      1

#endif