//
// Created by Fran on 01/09/2023.
//

//Implements
#include "HVAC.h"

#define TEST_HOST 1

#ifdef  TEST_HOST
#include <stdint.h>
uint8_t PORTA;
uint16_t ANA0;
#endif

float HVAC_get_desired_temperature()
{
    return 23;
}
float HVAC_get_current_temperature()
{
    return 3.3 *  ANA0 / 1024;
}
void HVAC_set_heater(bool active)
{
    if(active)
        PORTA = PORTA | 0x01;
    else
        PORTA = PORTA & 0xFE;
}
void HVAC_set_cooler(bool active)
{
    if(active)
        PORTA = PORTA | 0x02;
    else
        PORTA = PORTA & 0xFD;
}