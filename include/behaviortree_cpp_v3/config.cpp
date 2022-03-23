//
// Created by Gordon on 2022/3/23.
//


#include "config.h"

#ifdef Ivy

#include "Engine/Public.h"
#include "Body/Skin.h"

#endif

namespace BT {
    bool get_condition(condition_t condition) {
#ifdef Ivy
        bool ret = false;
        bool reverse = false;
        if (condition < 0) {
            reverse = true;
            condition = (condition_t) (-(int) condition);   /* reverse condition */
        }
        switch (condition) {
            case has_plant:
                ret = Prop::get<bool>(Prop::has_pot);
                break;
            case has_water:
                ret = (Prop::get<int>(Prop::water_level) > 0);
                break;
            case charging:
                ret = Prop::get<bool>(Prop::charging);
                break;
            case touching_left:
                ret = Skin::instance().touching_left();
                break;
            case touching_right:
                ret = Skin::instance().touching_right();
                break;
            case touching_plant:
                ret = Skin::instance().touching_plant();
                break;
            case hugging:
                ret = Skin::instance().hugging();
                break;
        }
        if (reverse) {
            return !ret;
        } else {
            return ret;
        }
#else
        return true;
#endif
    }
    bool get_value(value_t index, double &value) {
#ifdef Ivy
        switch (index) {
            case temp:
                value = Prop::get<double>(Prop::temperature);
                break;
            case humidity:
                value = Prop::get<double>(Prop::humidity);
                break;
            case light:
                value = Prop::get<double>(Prop::ambient_light);
                break;
            case water_level:
                value = Prop::get<double>(Prop::water_level);
                break;
            case battery:
                value = Prop::get<double>(Prop::battery_percent);
                break;
            case soil_moisture:
                value = Prop::get<double>(Prop::soil_moisture);
                break;
            default:
                return false;
        }
#endif
        return true;
    }
}