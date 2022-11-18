/**
 * @file nes.h
 *
 */

#ifndef RT_NES_H
#define RT_NES_H

#ifdef __cplusplus
extern "C" {
#endif


/*********************
 *      INCLUDES
 *********************/
#include "../../lv_lib_nes.h"

#if LV_USE_NES_NES != 0

#if RT_NES_PLATFORM_POSIX
    #include <pthread.h>
#elif RT_NES_PLATFORM_FREERTOS
    /* Scheduler include files. */
    #include "FreeRTOSConfig.h"
    #include "FreeRTOS.h"
    #include "task.h"
#elif RT_NES_PLATFORM_RTTHREAD
    /* Scheduler include files. */
    #include <rtthread.h>
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
#if RT_NES_PLATFORM_POSIX
    typedef pthread_mutex_t nes_mutex_t;
#elif RT_NES_PLATFORM_FREERTOS
    typedef SemaphoreHandle_t nes_mutex_t
#elif RT_NES_PLATFORM_RTTHREAD
    typedef rt_mutex_t nes_mutex_t;
#endif

typedef enum {
    RT_NES_KEY_A,
    RT_NES_KEY_B,
    RT_NES_KEY_START,
    RT_NES_KEY_SELECT,
    RT_NES_KEY_UP,
    RT_NES_KEY_DOWN,
    RT_NES_KEY_LEFT,
    RT_NES_KEY_RIGHT,
    RT_NES_KEY_MENU,
    RT_NES_KEY_CLEAN
} nes_key_t;

typedef enum {
    RT_NES_KEY_STATE_PRESSED,
    RT_NES_KEY_STATE_RELEASED,
} nes_key_state_t;

typedef enum {
    RT_NES_STATE_NORMAL,
    RT_NES_STATE_RESET,
    RT_NES_STATE_NEW_GAME,
    RT_NES_STATE_PAUSE,
    RT_NES_STATE_SAVE,
    RT_NES_STATE_MENU,
} nes_state_t;

/*Data of canvas*/
typedef struct {
    lv_obj_t obj;
    lv_obj_t * canvas;
    lv_draw_img_dsc_t img_rect_dsc;
    lv_img_dsc_t * dsc;
    lv_obj_t * img;
    void * nes_pixels;
    char * cur_fn;
    uint32_t speed;
    nes_mutex_t mutex;
    nes_state_t state;
} nes_t;

extern const lv_obj_class_t nes_class;

/***********************
 * GLOBAL VARIABLES
 ***********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
lv_obj_t * nes_create(lv_obj_t * parent);

/*=====================
 * Setter functions
 *====================*/
void nes_set_state(lv_obj_t * obj, nes_state_t state);

void nes_set_zoom(lv_obj_t * obj, uint16_t zoom);

void nes_set_speed(lv_obj_t * obj, uint32_t speed);

void nes_set_fn(lv_obj_t * obj, char * fn);

void nes_set_key(lv_obj_t * obj, nes_key_t key, nes_key_state_t state);

void nes_set_lock(lv_obj_t * obj);

void nes_set_unlock(lv_obj_t * obj);

/*=====================
 * Getter functions
 *====================*/

uint32_t nes_get_speed(lv_obj_t * obj);

char * nes_get_fn(lv_obj_t * obj);

nes_state_t nes_get_state(lv_obj_t * obj);

nes_mutex_t nes_get_mutex(lv_obj_t * obj);

/*=====================
 * Other functions
 *====================*/

void nes_menu(void);

void nes_run(void * obj);

void nes_flush(void);

/**********************
 *      MACROS
 **********************/


#endif  /*LV_USE_NES_NES*/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*RT_NES_H*/
