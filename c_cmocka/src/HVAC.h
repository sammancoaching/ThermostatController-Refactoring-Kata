//
// Created by Fran on 01/09/2023.
//

#ifndef HVAC_H
#define HVAC_H

#include <stdbool.h>

float HVAC_get_desired_temperature();
float HVAC_get_current_temperature();
void HVAC_set_heater(bool active);
void HVAC_set_cooler(bool active);

#endif //HVAC_H
