#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include "cmocka.h"

#include "HVAC.h"

#include "ThermostatController.h"


void __wrap_HVAC_set_cooler(bool active)
{
    function_called();
    check_expected(active);
}

void __wrap_HVAC_set_heater(bool active)
{
    function_called();
    check_expected(active);
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
    expect_function_call(__wrap_HVAC_set_heater);
    expect_function_call(__wrap_HVAC_set_cooler);
    will_return(__wrap_HVAC_get_desired_temperature, 23);
    will_return(__wrap_HVAC_get_current_temperature, 20);
    expect_value(__wrap_HVAC_set_heater, active, true);
    expect_value(__wrap_HVAC_set_cooler, active, false);

    bool result = regulate_temperature();

    assert_true(result);
}
static void test_regulate_temperature_too_hot(void **state)
{
    expect_function_call(__wrap_HVAC_set_heater);
    expect_function_call(__wrap_HVAC_set_cooler);
    will_return(__wrap_HVAC_get_desired_temperature, 23);
    will_return(__wrap_HVAC_get_current_temperature, 27);
    expect_value(__wrap_HVAC_set_heater, active, false);
    expect_value(__wrap_HVAC_set_cooler, active, true);

    bool result = regulate_temperature();

    assert_true(result);
}

static void test_regulate_temperature_ok(void **state)
{
    expect_function_call(__wrap_HVAC_set_heater);
    expect_function_call(__wrap_HVAC_set_cooler);
    will_return(__wrap_HVAC_get_desired_temperature, 23);
    will_return(__wrap_HVAC_get_current_temperature, 23);
    expect_value(__wrap_HVAC_set_heater, active, false);
    expect_value(__wrap_HVAC_set_cooler, active, false);

    bool result = regulate_temperature();

    assert_true(result);
}

int main(void) {
    const struct CMUnitTest tests[] =
            {
            cmocka_unit_test(test_regulate_temperature_too_cold),
            cmocka_unit_test(test_regulate_temperature_too_hot),
            cmocka_unit_test(test_regulate_temperature_ok),
            };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
