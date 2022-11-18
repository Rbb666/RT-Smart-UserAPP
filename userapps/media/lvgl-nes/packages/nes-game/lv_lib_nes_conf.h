/**
 * @file lv_lib_nes_conf.h
 * Configuration file for v8.2.0
 *
 */
/*
 * COPY THIS FILE AS lv_lib_nes_conf.h
 */

/* clang-format off */
#if 1 /*Set it to "1" to enable the content*/

#ifndef LV_LIB_NES_CONF_H
#define LV_LIB_NES_CONF_H

#include "lv_conf.h"

/*******************
 * GENERAL SETTING
 *******************/

/*********************
 * USAGE
 *********************/

/* Simplified Pinyin input method */
#if LV_USE_KEYBOARD
    /* Requires LV_USE_KEYBOARD = 1 */
    #define LV_USE_NES_PINYIN_IME                    0
#endif

#if LV_USE_NES_PINYIN_IME
    #define RT_PINYIN_IME_ZH_CN_PIN_YIN_DICT     1
    #define RT_PINYIN_IME_CAND_TEXT_NUM          10

    /*test*/
    #define RT_PINYIN_IME_SIMPLE_TEST            1
#endif


/* Page manager */
#define LV_USE_NES_PAGE_MANAGER                      0
#if LV_USE_NES_PAGE_MANAGER
    /*Switch pages and delete old pages at the same time. */
    /*1: DELETE , 0:DELETE NO*/
    #define RT_PAGE_MANAGER_SW_DEL_PAGE          0

    /*1: use custom animation , 0:Use built-in animation*/
    #define RT_PAGE_MANAGER_COSTOM_ANIMARION     0
        
	/* Page switcher snapshot*/
	#if LV_USE_SNAPSHOT
        /* Requires LV_USE_SNAPSHOT = 1 */
        #define PAGE_SWITCHER_SNAPSHOT                  0 /*TODO*/
    #endif

    #define RT_PAGE_MANAGER_BACK_BTN_SIZE        (LV_DPI_DEF/2)

    /*test*/
    #define RT_PAGE_MANAGER_SIMPLE_TEST          1
#endif


/* sketchpad */
#if LV_USE_CANVAS
    /* Requires LV_USE_CANVAS = 1 */
    #define LV_USE_NES_SKETCHPAD                     0
#endif
#if LV_USE_NES_SKETCHPAD
    /* set sketchpad default size */
    #define SKETCHPAD_DEFAULT_WIDTH                     1024    /*LV_HOR_RES*/
    #define SKETCHPAD_DEFAULT_HEIGHT                    600     /*LV_VER_RES*/

    /*test*/
    #define RT_SKETCHPAD_SIMPLE_TEST             1
#endif


/*Calculator*/
#define LV_USE_NES_CALC                              0
#if LV_USE_NES_CALC
    /*Calculation expression*/
    #define RT_CALC_EXPR_LEN                      (128) /*Maximum allowed length of expression*/
    #define RT_CALC_MAX_NUM_LEN                   (5)   /*Maximum length of operands allowed*/

    /*test*/
    #define RT_CALC_SIMPLE_TEST                  1
#endif

/*GAME*/
/*Memory game*/
#define LV_USE_NES_MEMORY_GAME                       0
#if LV_USE_NES_MEMORY_GAME
    /*Initial values of rows and columns.*/
    /*Recommended row == column*/
    #define  RT_MEMORY_GAME_DEFAULT_ROW          4
    #define  RT_MEMORY_GAME_DEFAULT_COL          4

    /*test*/
    #define  RT_MEMORY_GAME_SIMPLE_TEST          1
#endif   

/*2048 game*/
#define LV_USE_NES_2048                              0
#if LV_USE_NES_2048
    /* Matrix size*/
    /*Do not modify*/
    #define  RT_2048_MATRIX_SIZE                 4

    /*test*/
    #define  RT_2048_SIMPLE_TEST                 1
#endif

/*File explorer*/
#define LV_USE_NES_FILE_EXPLORER             1
#if LV_USE_NES_FILE_EXPLORER
    /*Maximum length of path*/
    #define RT_FILE_EXPLORER_PATH_MAX_LEN        (128)
    /*Quick access bar, 1:use, 0:not use*/
    #define RT_FILE_EXPLORER_QUICK_ACCESS        0
    /*test*/
    #define  RT_FILE_EXPLORER_SIMPLE_TEST        1
#endif  

/***Game simulator***/
/*NES*/
#if LV_USE_IMG
    #define LV_USE_NES_NES                   1
#endif
#if LV_USE_NES_NES
    /*platform*/
    #define RT_NES_PLATFORM_POSIX                0
    #define RT_NES_PLATFORM_FREERTOS             0
    #define RT_NES_PLATFORM_RTTHREAD             1
    
    /*test*/
#if LV_USE_NES_FILE_EXPLORER
    #define RT_NES_SIMPLE_TEST                   1
#endif

#endif

#endif /*LV_LIB_NES_H*/

#endif /*End of "Content enable"*/

