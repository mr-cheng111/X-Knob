#ifndef __PLAGROUND_VIEW_H
#define __PLAGROUND_VIEW_H
#include "Arduino.h"
#include "app/app.h"
#include "../Page.h"


typedef struct {
    int32_t xkonb_value;
    int32_t motor_pos;
    int32_t angle_offset;
    SuperDialMotion konb_direction;
    bool is_ble_connected;
}PlaygroundInfo;

namespace Page
{

class PlaygroundView
{
public:
    virtual void Create(lv_obj_t* root);
    void Delete();
    virtual void UpdateView(PlaygroundInfo *info);
    virtual void SetPlaygroundMode(int16_t mode);
    void UpdateBackgroundView(PlaygroundInfo *info); 
    int16_t app;


public:
    struct
    {
        lv_obj_t* meter;
        lv_meter_scale_t* scale_pot;   // 圆点的刻度
        lv_obj_t* lable_value;
        lv_meter_indicator_t* nd_img_circle;
        lv_meter_scale_t* scale_arc;   // arc 的刻度
        lv_meter_indicator_t* arc;
        lv_group_t* group;
    } ui;

    struct
    {
        lv_style_t meter;
        lv_style_t ticks;
    } style;

private:
    void OnOffView(void);
    void BoundZeroView(void);
};

}

#endif // !__VIEW_H
