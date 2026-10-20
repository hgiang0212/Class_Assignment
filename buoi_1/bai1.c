#include "bai_tap.h"

#define enable_position 0u
#define enable_mask ((uint8_t)(0x01u << enable_position))
#define mode_position 1u
#define mode_mask ((uint8_t)(0x03u << mode_position))

uint8_t update_control(uint8_t reg, uint8_t enable, uint8_t mode)
{
    uint8_t new_reg = (uint8_t)(reg & (uint8_t)~(enable_mask | mode_mask));
    new_reg |= (uint8_t)((enable << enable_position) & enable_mask);
    new_reg |= (uint8_t)((mode << mode_position) & mode_mask);

    return new_reg;
}