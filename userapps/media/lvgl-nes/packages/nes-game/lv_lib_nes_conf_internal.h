/**
 * GENERATED FILE, DO NOT EDIT IT!
 * @file lv_lib_nes_conf_internal.h
 * Make sure all the defines of lv_lib_nes_conf.h have a default value
**/

#ifndef LV_LIB_NES_CONF_INTERNAL_H
#define LV_LIB_NES_CONF_INTERNAL_H


/*RT_PINYIN_IME*/
#ifndef LV_USE_NES_PINYIN_IME
#  ifdef CONFIG_LV_USE_NES_PINYIN_IME
#    define LV_USE_NES_PINYIN_IME CONFIG_LV_USE_NES_PINYIN_IME
#  else
#    define LV_USE_NES_PINYIN_IME          0
#  endif
#endif

#ifndef RT_PINYIN_IME_CAND_TEXT_NUM
#  ifdef CONFIG_RT_PINYIN_IME_CAND_TEXT_NUM
#    define RT_PINYIN_IME_CAND_TEXT_NUM CONFIG_RT_PINYIN_IME_CAND_TEXT_NUM
#  else
#    define RT_PINYIN_IME_CAND_TEXT_NUM          10
#  endif
#endif

#ifndef LV_USE_NES_PINYIN_IME
#  ifdef CONFIG_LV_USE_NES_PINYIN_IME
#    define LV_USE_NES_PINYIN_IME CONFIG_LV_USE_NES_PINYIN_IME
#  else
#    define LV_USE_NES_PINYIN_IME          0
#  endif
#endif

#ifndef LV_USE_NES_PINYIN_IME
#  ifdef CONFIG_LV_USE_NES_PINYIN_IME
#    define LV_USE_NES_PINYIN_IME CONFIG_LV_USE_NES_PINYIN_IME
#  else
#    define LV_USE_NES_PINYIN_IME          0
#  endif
#endif

/*RT_PAGE_MANAGER*/
#ifndef LV_USE_NES_PAGE_MANAGER
#  ifdef CONFIG_LV_USE_NES_PAGE_MANAGER
#    define LV_USE_NES_PAGE_MANAGER CONFIG_LV_USE_NES_PAGE_MANAGER
#  else
#    define LV_USE_NES_PAGE_MANAGER          0
#  endif
#endif

#ifndef RT_PAGE_MANAGER_SW_DEL_PAGE
#  ifdef CONFIG_RT_PAGE_MANAGER_SW_DEL_PAGE
#    define RT_PAGE_MANAGER_SW_DEL_PAGE CONFIG_RT_PAGE_MANAGER_SW_DEL_PAGE
#  else
#    define RT_PAGE_MANAGER_SW_DEL_PAGE          0
#  endif
#endif

#ifndef PAGE_SWITCHER_SNAPSHOT
#  ifdef CONFIG_PAGE_SWITCHER_SNAPSHOT
#    define PAGE_SWITCHER_SNAPSHOT CONFIG_PAGE_SWITCHER_SNAPSHOT
#  else
#    define PAGE_SWITCHER_SNAPSHOT          0
#  endif
#endif

#ifndef RT_PAGE_MANAGER_BACK_BTN_SIZE
#  ifdef CONFIG_RT_PAGE_MANAGER_BACK_BTN_SIZE
#    define RT_PAGE_MANAGER_BACK_BTN_SIZE CONFIG_RT_PAGE_MANAGER_BACK_BTN_SIZE
#  else
#    define RT_PAGE_MANAGER_BACK_BTN_SIZE          (LV_DPI_DEF/2)
#  endif
#endif

#ifndef RT_PAGE_MANAGER_SIMPLE_TEST
#  ifdef CONFIG_RT_PAGE_MANAGER_SIMPLE_TEST
#    define RT_PAGE_MANAGER_SIMPLE_TEST CONFIG_RT_PAGE_MANAGER_SIMPLE_TEST
#  else
#    define RT_PAGE_MANAGER_SIMPLE_TEST          0
#  endif
#endif


/*RT_SKETCHPAD*/
#ifndef LV_USE_NES_SKETCHPAD
#  ifdef CONFIG_LV_USE_NES_SKETCHPAD
#    define LV_USE_NES_SKETCHPAD CONFIG_LV_USE_NES_SKETCHPAD
#  else
#    define LV_USE_NES_SKETCHPAD          0
#  endif
#endif

#ifndef SKETCHPAD_DEFAULT_WIDTH
#  ifdef CONFIG_SKETCHPAD_DEFAULT_WIDTH
#    define SKETCHPAD_DEFAULT_WIDTH CONFIG_SKETCHPAD_DEFAULT_WIDTH
#  else
#    define SKETCHPAD_DEFAULT_WIDTH          0
#  endif
#endif

#ifndef SKETCHPAD_DEFAULT_HEIGHT
#  ifdef CONFIG_SKETCHPAD_DEFAULT_HEIGHT
#    define SKETCHPAD_DEFAULT_HEIGHT CONFIG_SKETCHPAD_DEFAULT_HEIGHT
#  else
#    define SKETCHPAD_DEFAULT_HEIGHT          0
#  endif
#endif

#ifndef RT_SKETCHPAD_SIMPLE_TEST
#  ifdef CONFIG_RT_SKETCHPAD_SIMPLE_TEST
#    define RT_SKETCHPAD_SIMPLE_TEST CONFIG_RT_SKETCHPAD_SIMPLE_TEST
#  else
#    define RT_SKETCHPAD_SIMPLE_TEST          0
#  endif
#endif


/*RT_CALC*/
#ifndef LV_USE_NES_CALC
#  ifdef CONFIG_LV_USE_NES_CALC
#    define LV_USE_NES_CALC CONFIG_LV_USE_NES_CALC
#  else
#    define LV_USE_NES_CALC          0
#  endif
#endif

#ifndef RT_CALC_EXPR_LEN
#  ifdef CONFIG_RT_CALC_EXPR_LEN
#    define RT_CALC_EXPR_LEN CONFIG_RT_CALC_EXPR_LEN
#  else
#    define RT_CALC_EXPR_LEN          0
#  endif
#endif

#ifndef RT_CALC_MAX_NUM_LEN
#  ifdef CONFIG_RT_CALC_MAX_NUM_LEN
#    define RT_CALC_MAX_NUM_LEN CONFIG_RT_CALC_MAX_NUM_LEN
#  else
#    define RT_CALC_MAX_NUM_LEN          0
#  endif
#endif

#ifndef RT_CALC_SIMPLE_TEST
#  ifdef CONFIG_RT_CALC_SIMPLE_TEST
#    define RT_CALC_SIMPLE_TEST CONFIG_RT_CALC_SIMPLE_TEST
#  else
#    define RT_CALC_SIMPLE_TEST          0
#  endif
#endif


/*RT_MEMORY_GAME*/
#ifndef LV_USE_NES_MEMORY_GAME
#  ifdef CONFIG_LV_USE_NES_MEMORY_GAME
#    define LV_USE_NES_MEMORY_GAME CONFIG_LV_USE_NES_MEMORY_GAME
#  else
#    define LV_USE_NES_MEMORY_GAME          1
#  endif
#endif

#ifndef RT_MEMORY_GAME_DEFAULT_ROW
#  ifdef CONFIG_RT_MEMORY_GAME_DEFAULT_ROW
#    define RT_MEMORY_GAME_DEFAULT_ROW CONFIG_RT_MEMORY_GAME_DEFAULT_ROW
#  else
#    define RT_MEMORY_GAME_DEFAULT_ROW          0
#  endif
#endif

#ifndef RT_MEMORY_GAME_DEFAULT_COL
#  ifdef CONFIG_RT_MEMORY_GAME_DEFAULT_COL
#    define RT_MEMORY_GAME_DEFAULT_COL CONFIG_RT_MEMORY_GAME_DEFAULT_COL
#  else
#    define RT_MEMORY_GAME_DEFAULT_COL          0
#  endif
#endif

#ifndef RT_MEMORY_GAME_SIMPLE_TEST
#  ifdef CONFIG_RT_MEMORY_GAME_SIMPLE_TEST
#    define RT_MEMORY_GAME_SIMPLE_TEST CONFIG_RT_MEMORY_GAME_SIMPLE_TEST
#  else
#    define RT_MEMORY_GAME_SIMPLE_TEST          0
#  endif
#endif

/*RT_2048*/
#ifndef LV_USE_NES_2048
#  ifdef CONFIG_LV_USE_NES_2048
#    define LV_USE_NES_2048 CONFIG_LV_USE_NES_2048
#  else
#    define LV_USE_NES_2048          1
#  endif
#endif

#ifndef RT_2048_MATRIX_SIZE
#  ifdef CONFIG_RT_2048_MATRIX_SIZE
#    define RT_2048_MATRIX_SIZE CONFIG_RT_2048_MATRIX_SIZE
#  else
#    define RT_2048_MATRIX_SIZE          4
#  endif
#endif


#ifndef RT_2048_SIMPLE_TEST
#  ifdef CONFIG_RT_2048_SIMPLE_TEST
#    define RT_2048_SIMPLE_TEST CONFIG_RT_2048_SIMPLE_TEST
#  else
#    define RT_2048_SIMPLE_TEST          0
#  endif
#endif

/*File explorer*/
#ifndef LV_USE_NES_FILE_EXPLORER
#  ifdef CONFIG_LV_USE_NES_FILE_EXPLORER
#    define LV_USE_NES_FILE_EXPLORER CONFIG_LV_USE_NES_FILE_EXPLORER
#  else
#    define LV_USE_NES_FILE_EXPLORER          0
#  endif
#endif

#ifndef RT_FILE_EXPLORER_PATH_MAX_LEN
#  ifdef CONFIG_RT_FILE_EXPLORER_PATH_MAX_LEN
#    define RT_FILE_EXPLORER_PATH_MAX_LEN CONFIG_RT_FILE_EXPLORER_PATH_MAX_LEN
#  else
#    define RT_FILE_EXPLORER_PATH_MAX_LEN          128
#  endif
#endif

#ifndef RT_FILE_EXPLORER_QUICK_ACCESS
#  ifdef CONFIG_RT_FILE_EXPLORER_QUICK_ACCESS
#    define RT_FILE_EXPLORER_QUICK_ACCESS CONFIG_RT_FILE_EXPLORER_QUICK_ACCESS
#  else
#    define RT_FILE_EXPLORER_QUICK_ACCESS          0
#  endif
#endif

#ifndef RT_FILE_EXPLORER_SIMPLE_TEST
#  ifdef CONFIG_RT_FILE_EXPLORER_SIMPLE_TEST
#    define RT_FILE_EXPLORER_SIMPLE_TEST CONFIG_RT_FILE_EXPLORER_SIMPLE_TEST
#  else
#    define RT_FILE_EXPLORER_SIMPLE_TEST          0
#  endif
#endif

/*RT_NES*/
#ifndef LV_USE_NES_NES
#  ifdef CONFIG_LV_USE_NES_NES
#    define LV_USE_NES_NES CONFIG_LV_USE_NES_NES
#  else
#    define LV_USE_NES_NES          0
#  endif
#endif

#ifndef RT_NES_PLATFORM_POSIX
#  ifdef CONFIG_RT_NES_PLATFORM_POSIX
#    define RT_NES_PLATFORM_POSIX CONFIG_RT_NES_PLATFORM_POSIX
#  else
#    define RT_NES_PLATFORM_POSIX          0
#  endif
#endif

#ifndef RT_NES_PLATFORM_FREERTOS
#  ifdef CONFIG_RT_NES_PLATFORM_FREERTOS
#    define RT_NES_PLATFORM_FREERTOS CONFIG_RT_NES_PLATFORM_FREERTOS
#  else
#    define RT_NES_PLATFORM_FREERTOS          0
#  endif
#endif

#ifndef RT_NES_PLATFORM_RTTHREAD
#  ifdef CONFIG_RT_NES_PLATFORM_RTTHREAD
#    define RT_NES_PLATFORM_RTTHREAD CONFIG_RT_NES_PLATFORM_RTTHREAD
#  else
#    define RT_NES_PLATFORM_RTTHREAD         0
#  endif
#endif


#if LV_USE_NES_FILE_EXPLORER
    #ifndef RT_NES_SIMPLE_TEST
        #ifdef CONFIG_RT_NES_SIMPLE_TEST
            #define RT_NES_SIMPLE_TEST CONFIG_RT_NES_SIMPLE_TEST
        #else
            #define RT_NES_SIMPLE_TEST          0
        #endif
    #endif
#endif

#endif /*LV_LIB_NES_CONF_INTERNAL_H*/