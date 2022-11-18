/**
 * @file simple_test.h
 *
 */

#ifndef NES_SIMPLE_TEST_H
#define NES_SIMPLE_TEST_H

#ifdef __cplusplus
extern "C" {
#endif


/*********************
 *      INCLUDES
 *********************/
#include "../../lv_lib_nes.h"

#if RT_NES_SIMPLE_TEST != 0

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
enum {
    LV_MENU_ITEM_BUILDER_VARIANT_1,
    LV_MENU_ITEM_BUILDER_VARIANT_2
};
typedef uint8_t lv_menu_builder_variant_t;

/***********************
 * GLOBAL VARIABLES
 ***********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void nes_simple_test(void);

/*=====================
 * Setter functions
 *====================*/

/*=====================
 * Getter functions
 *====================*/

/*=====================
 * Other functions
 *====================*/

/**********************
 *      MACROS
 **********************/

#endif  /*RT_NES_SIMPLE_TEST*/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*RT_NES_SIMPLE_TEST_H*/
