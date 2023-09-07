#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include "cmocka.h"

#include "HVAC.h"

#include "ThermostatController.h"

bool cooler_active;
bool heater_active;

void __wrap_HVAC_set_cooler(bool active)
{
    cooler_active = active;
}

void __wrap_HVAC_set_heater(bool active)
{
    heater_active = active;
}

float __wrap_HVAC_get_desired_temperature()
{
    return mock_type(float);
}

float __wrap_HVAC_get_current_temperature()
{
    return mock_type(float);
}

static void test_regulate_temperature_too_cold(void **state)
{
    will_return_maybe(__wrap_HVAC_get_desired_temperature, 23);
    will_return_maybe(__wrap_HVAC_get_current_temperature, 20);

    bool result = regulate_temperature();

    assert_true(result);
}

static void test_regulate_temperature_too_hot(void **state)
{
    will_return_maybe(__wrap_HVAC_get_desired_temperature, 23);
    will_return_maybe(__wrap_HVAC_get_current_temperature, 27);

    bool result = regulate_temperature();

    assert_true(result);
}

static void test_regulate_temperature_ok(void **state)
{
    will_return_maybe(__wrap_HVAC_get_desired_temperature, 23);
    will_return_maybe(__wrap_HVAC_get_current_temperature, 23);

    bool result = regulate_temperature();

    assert_true(result);
}

static void test_regulate_temperature_legal_limit(void **state)
{
    will_return_maybe(__wrap_HVAC_get_desired_temperature, 20);
    will_return_maybe(__wrap_HVAC_get_current_temperature, 23);

    bool result = regulate_temperature();

    assert_false(result);
}

int main(void) {
    const struct CMUnitTest tests[] =
            {
            cmocka_unit_test(test_regulate_temperature_too_cold),
            cmocka_unit_test(test_regulate_temperature_too_hot),
            cmocka_unit_test(test_regulate_temperature_ok),
            cmocka_unit_test(test_regulate_temperature_legal_limit),
            };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
