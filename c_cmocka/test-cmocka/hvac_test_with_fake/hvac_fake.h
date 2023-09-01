#ifndef THERMOSTATCONTROLLER_HVAC_FAKE_H
#define THERMOSTATCONTROLLER_HVAC_FAKE_H

#include <stdbool.h>


float HVAC_fake_get_desired_temperature();
float HVAC_fake_get_current_temperature();
void HVAC_fake_set_heater(bool active);
void HVAC_fake_set_cooler(bool active);

void HVAC_fake_init();
bool HVAC_fake_get_heater();
bool HVAC_fake_get_cooler();
void HVAC_fake_set_desired_temperature(float value);
void HVAC_fake_set_current_temperature(float value);

#endif //THERMOSTATCONTROLLER_HVAC_FAKE_H
