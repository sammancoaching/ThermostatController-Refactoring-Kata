#include "hvac_fake.h"

static float fake_current_temperature;
static float fake_desired_temperature;
static bool fake_cooler_active;
static bool fake_heater_active;

float HVAC_fake_get_desired_temperature()
{
    return fake_desired_temperature;
}
float HVAC_fake_get_current_temperature()
{
    return fake_current_temperature;
}
void HVAC_fake_set_heater(bool active)
{
    fake_heater_active = active;
}
void HVAC_fake_set_cooler(bool active)
{
    fake_cooler_active = active;
}

void HVAC_fake_init()
{
    fake_desired_temperature = 23;
    fake_current_temperature = 23;
    fake_cooler_active = false;
    fake_heater_active = false;
}

bool HVAC_fake_get_heater()
{
    return fake_heater_active;
}
bool HVAC_fake_get_cooler()
{
    return fake_cooler_active;
}

void HVAC_fake_set_desired_temperature(float value)
{
    fake_desired_temperature = value;
}
void HVAC_fake_set_current_temperature(float value)
{
    fake_current_temperature = value;
}

