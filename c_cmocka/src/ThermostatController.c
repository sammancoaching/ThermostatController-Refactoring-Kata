//
// Created by Fran on 01/09/2023.
//

//Implements
#include "ThermostatController.h"

//Uses
#include "HVAC.h"

bool regulate_temperature()
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
        // exercise - see instructionsadd
        // replace these two lines with the commented out lines below
        HVAC_set_heater(false);
        HVAC_set_cooler(true);

//        HVAC_set_heater(false);
//        if (HVAC_get_current_temperature() < 24) {
//            HVAC_set_cooler(false);
//            return false;
//        }  else {
//            HVAC_set_cooler(true);
//        }
    }
    else
    {
        HVAC_set_heater(false);
        HVAC_set_cooler(false);
    }
    return true;
}


