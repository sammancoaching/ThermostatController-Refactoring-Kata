//
// Created by Fran on 01/09/2023.
//

//Implements
#include "ThermostatController.h"

//Uses
#include "HVAC.h"

void regulate_temperature()
{
    float desired_temperature = HVAC_get_desired_temperature();
    float current_temperature = HVAC_get_current_temperature();
    if(current_temperature < desired_temperature)
    {
        HVAC_set_heater(true);
        HVAC_set_cooler(false);
    }
    else if (current_temperature > desired_temperature)
    {
        HVAC_set_heater(false);
        HVAC_set_cooler(true);
    }
    else
    {
        HVAC_set_heater(false);
        HVAC_set_cooler(false);
    }
}


