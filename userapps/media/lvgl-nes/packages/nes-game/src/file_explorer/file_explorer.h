/**
 * @file file_explorer.h
 *
 */

#ifndef RT_FILE_EXPLORER_H
#define RT_FILE_EXPLORER_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "../../lv_lib_nes.h"

#if LV_USE_NES_FILE_EXPLORER != 0

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

typedef enum {
    RT_EXPLORER_SORT_KIND,
    RT_EXPLORER_SORT_NAME,
} file_explorer_sort_t;

#if RT_FILE_EXPLORER_QUICK_ACCESS
typedef enum {
    RT_EXPLORER_HOME_DIR,
    RT_EXPLORER_MUSIC_DIR,
    RT_EXPLORER_PICTURES_DIR,
    RT_EXPLORER_VIDEO_DIR,
    RT_EXPLORER_DOCS_DIR,
    RT_EXPLORER_MNT_DIR,
    RT_EXPLORER_FS_DIR,
} file_explorer_dir_t;
#endif

/*Data of canvas*/
typedef struct {
    lv_obj_t obj;
    lv_obj_t * cont;
    lv_obj_t * head_area;
    lv_obj_t * brower_area;
    lv_obj_t * file_list;
    lv_obj_t * quick_access_ctrl_btn;
    lv_obj_t * path_label;
#if RT_FILE_EXPLORER_QUICK_ACCESS
    lv_obj_t * quick_access_area;
    lv_obj_t * list_device;
    lv_obj_t * list_places;
    char * home_dir;
    char * music_dir;
    char * pictures_dir;
    char * video_dir;
    char * docs_dir;
#endif
    char * sel_fp;
    char   cur_path[RT_FILE_EXPLORER_PATH_MAX_LEN];
} file_explorer_t;

/***********************
 * GLOBAL VARIABLES
 ***********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
lv_obj_t * file_explorer_create(lv_obj_t * parent);

/*=====================
 * Setter functions
 *====================*/

#if RT_FILE_EXPLORER_QUICK_ACCESS
/**
 * Set file_explorer
 * @param obj   pointer to a label object
 * @param dir   the dir from 'file_explorer_dir_t' enum.
 */
void file_explorer_set_quick_access_path(lv_obj_t * obj, file_explorer_dir_t dir, char * path);

/**
 * Set file_explorer quick access state
 * @param obj   pointer to a label object
 * @param state true:display, false: hide
 */
void file_explorer_set_quick_access_state(lv_obj_t * obj, bool state);
#endif


/**
 * Set file_explorer sort
 * @param obj   pointer to a label object
 * @param sort  the sort from 'file_explorer_sort_t' enum.
 */
void file_explorer_set_sort(lv_obj_t * obj, file_explorer_sort_t sort);

/*=====================
 * Getter functions
 *====================*/

/**
 * Get file explorer Selected file
 * @param obj   pointer to a file explorer object
 * @return      pointer to the file explorer selected file
 */
char * file_explorer_get_sel_fn(lv_obj_t * obj);

/**
 * Get file explorer cur path
 * @param obj   pointer to a file explorer object
 * @return      pointer to the file explorer cur path
 */
char * file_explorer_get_cur_path(lv_obj_t * obj);

/**
 * Get file explorer head area obj
 * @param obj   pointer to a file explorer object
 * @return      pointer to the file explorer head area obj
 */
lv_obj_t * file_explorer_get_head_area(lv_obj_t * obj);

/**
 * Get file explorer path obj(label)
 * @param obj   pointer to a file explorer object
 * @return      pointer to the file explorer path obj(label)
 */
lv_obj_t * file_explorer_get_path_obj(lv_obj_t * obj);

#if RT_FILE_EXPLORER_QUICK_ACCESS
/**
 * Get file explorer quick access ctrl btn obj(lv_btn)
 * @param obj   pointer to a file explorer object
 * @return      pointer to the file explorer quick access ctrl btn obj(lv_btn)
 */
lv_obj_t * file_explorer_get_quick_access_ctrl_btn(lv_obj_t * obj);

/**
 * Get file explorer places list obj(lv_list)
 * @param obj   pointer to a file explorer object
 * @return      pointer to the file explorer places list obj(lv_list)
 */
lv_obj_t * file_explorer_get_places_list(lv_obj_t * obj);

/**
 * Get file explorer device list obj(lv_list)
 * @param obj   pointer to a file explorer object
 * @return      pointer to the file explorer device list obj(lv_list)
 */
lv_obj_t * file_explorer_get_device_list(lv_obj_t * obj);
#endif

/**
 * Get file explorer file list obj(lv_table)
 * @param obj   pointer to a file explorer object
 * @return      pointer to the file explorer device obj(lv_table)
 */
lv_obj_t * file_explorer_get_file_list(lv_obj_t * obj);


/*=====================
 * Other functions
 *====================*/

/**
 * Open a specified path
 * @param obj   pointer to a file explorer object
 * @param dir   pointer to the path
 */
void file_explorer_open_dir(lv_obj_t * obj, char * dir);

/**********************
 *      MACROS
 **********************/

#endif  /*LV_USE_SKETCHPAD*/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_SKETCHPAD_H*/
