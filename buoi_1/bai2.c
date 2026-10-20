#include "bai_tap.h"
FanResult evaluate_fan(size_t count, const uint8_t temperatures[])
{
    FanResult res = {FAN_OFF, 0u, 0u};
    for (size_t i = 0; i < count; i++)
    {
        FanState prev = res.final_state;
        if (temperatures[i] >= 70u)
        {
            res.final_state = FAN_ON;
        }
        else if (temperatures[i] <= 50u)
        {
            res.final_state = FAN_OFF;
        }
        if (prev != res.final_state)
        {
            res.transition_count++;
        }
        if (res.final_state == FAN_ON)
        {
            res.on_count++;
        }
    }
    return res;
}