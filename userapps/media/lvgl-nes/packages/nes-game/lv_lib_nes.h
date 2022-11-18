/**
 * @file lv_lib_nes.h
 *
 */

#ifndef LV_LIB_NES_H
#define LV_LIB_NES_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "lvgl.h"
#endif

#if defined(LV_LIB_NES_CONF_PATH)
#define __LV_TO_STR_AUX(x) #x
#define __LV_TO_STR(x) __LV_TO_STR_AUX(x)
#include __LV_TO_STR(LV_LIB_NES_CONF_PATH)
#undef __LV_TO_STR_AUX
#undef __LV_TO_STR
#elif defined(ESP_PLATFORM)
#include "lv_lib_nes_conf_internal.h"
#elif defined(LV_LIB_NES_CONF_INCLUDE_SIMPLE)
#include "lv_lib_nes_conf.h"
#else
#include "lv_lib_nes_conf.h"
#endif

/*Game simulator*/
/*nes*/
#include "src/nes/nes.h"
#include "test/nes_test/nes_simple_test.h"

/*********************
 *      DEFINES
 *********************/
/*Test  lvgl version*/
#if LV_VERSION_CHECK(8, 2, 0) == 0
#error "nes-lvgl: Wrong lvgl version"
#endif

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/


/**********************
 *      MACROS
 **********************/


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_LIB_NES_H*/
