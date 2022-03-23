//
// Created by sungaoran on 2022/3/20.
//

#ifndef PLANTSIO_IVY_CONFIG_H
#define PLANTSIO_IVY_CONFIG_H

#define BT_VALUE_INPUT_NAME     "index"
#define BT_ANIM_NAME            "anim"
#define BT_VALUE_TARGET_NAME    "target"
#define BT_CONDITION_NAME       "condition"
#include "string"

namespace BT {
    /* note for reference and type check only (for now) */
    /* todo generate enum selection on UI */
    typedef enum {
        invalid = -1,
        blank_tick = 0,
        idle_routine = 1,       /* 空闲 */
        touch_left = 2,         /* 触摸左侧 */
        touch_right = 3,        /* 触摸右侧 */
        touch_hug = 4,          /* 触摸两侧 */
        touch_plant = 5,        /* 触摸植物 */
        pot_change = 6,         /* 盆状态改变 */
        knock = 7,              /* 轻敲 */
        thump = 8,              /* 重击 */
        charging_change = 9     /* 充电状态变更 */
    } event_t;

    typedef enum {
        has_plant = 1,          /* 植物存在 */
        has_water = 2,          /* 水存在 */
        charging = 3,           /* 充电中 */
        touching_left = 4,      /* 触摸左侧中 */
        touching_right = 5,     /* 触摸右侧中 */
        touching_plant = 6,     /* 触摸植物中 */
        hugging = 7,            /* 抱住中 */
    } condition_t;

    typedef enum {
        temp = 1,               /* 温度 */
        humidity = 2,           /* 湿度 */
        light = 3,              /* 光照 */
        water_level = 4,        /* 水位 */
        battery = 5,            /* 电量 */
        soil_moisture = 6,      /* 土壤湿度 */
    } value_t;

    /* get Ivy conditions */
    bool get_condition(condition_t condition);

    /* get Ivy properties or params */
    bool get_value(value_t index, double &value);

    /* get the nam of the currently playing animation */
    std::string get_current_anim_name();
}

#endif //PLANTSIO_IVY_CONFIG_H
