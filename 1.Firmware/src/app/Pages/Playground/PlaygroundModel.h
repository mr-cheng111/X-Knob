#ifndef __PLAGROUND_MODEL_H
#define __PLAGROUND_MODEL_H
#include "App/Utils/AccountSystem/Account.h"
#include "lvgl.h"
#include "PlaygroundView.h"
namespace Page
{

class PlaygroundModel
{
public:
    int16_t app;
    void Init();
    void Deinit();
    void Update(void* pg_ui);
    virtual void GetKnobStatus(PlaygroundInfo *info);
    void ChangeMotorMode(int mode);
    void SetPlaygroundMode(int16_t mode);
private:
    Account* account;
};

}

#endif
