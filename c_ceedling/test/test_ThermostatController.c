#include "processor_selection.h"
#include "unity.h"
#include "unity_config.h"

#include <stdbool.h>
#include <string.h>

//Subject Under Test
#include "ThermostatController.h"

//Test doubles for Dependant Component
#include "mock_HVAC.h"

static void Given_ConfiguredTemperature_Is(float temp);
static void Given_CurrentTemperature_Is(float temp);

typedef enum
{
    ON,
    OFF,
    UNKNOWN
}ACTIVATION_STATUS;

static ACTIVATION_STATUS heater_status;
static void HVAC_set_heater_Spy(bool active, int numcalls);

static ACTIVATION_STATUS cooler_status;
static void HVAC_set_cooler_Spy(bool active, int numcalls);

void setUp(void)
{
    heater_status = UNKNOWN;
    cooler_status = UNKNOWN;
    HVAC_set_heater_StubWithCallback(&HVAC_set_heater_Spy);
    HVAC_set_cooler_StubWithCallback(&HVAC_set_cooler_Spy);
}

void tearDown(void)
{
}

void test_ThermostatController_Temperature_Below_Configured_Must_Heat(void)
{
    //ARRANGE
    Given_ConfiguredTemperature_Is(25);
    Given_CurrentTemperature_Is(24);

    //ACT
    regulate_temperature();

    //ASSERT
    TEST_ASSERT_EQUAL(ON, heater_status);
    TEST_ASSERT_EQUAL(OFF, cooler_status);
}

void test_ThermostatController_Temperature_Above_Configured_Must_Cool(void)
{
    //ARRANGE
    Given_ConfiguredTemperature_Is(25);
    Given_CurrentTemperature_Is(26);

    //ACT
    regulate_temperature();

    //ASSERT
    TEST_ASSERT_EQUAL(OFF, heater_status);
    TEST_ASSERT_EQUAL(ON, cooler_status);
}

void test_ThermostatController_Temperature_Equal_To_Configured_Do_Nothing(void)
{
    //ARRANGE
    Given_ConfiguredTemperature_Is(25);
    Given_CurrentTemperature_Is(25);

    //ACT
    regulate_temperature();

    //ASSERT
    TEST_ASSERT_EQUAL(OFF, heater_status);
    TEST_ASSERT_EQUAL(OFF, cooler_status);
}


static void Given_ConfiguredTemperature_Is(float configured_temperature)
{
    HVAC_get_desired_temperature_ExpectAndReturn(configured_temperature);
}
static void Given_CurrentTemperature_Is(float actual_temperature)
{
    HVAC_get_current_temperature_ExpectAndReturn(actual_temperature);
}

static void HVAC_set_heater_Spy(bool active, int numcalls)
{
    if(active)
        heater_status = ON;
    else
        heater_status = OFF;
}
static void HVAC_set_cooler_Spy(bool active, int numcalls)
{
    if(active)
        cooler_status = ON;
    else
        cooler_status = OFF;
}