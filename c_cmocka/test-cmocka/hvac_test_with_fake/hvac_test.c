#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include "cmocka.h"

#include "hvac_fake.h"

#include "ThermostatController.h"

void __wrap_HVAC_set_cooler(bool active)
{
    HVAC_fake_set_cooler(active);
}

void __wrap_HVAC_set_heater(bool active)
{
    HVAC_fake_set_heater(active);
}

float __wrap_HVAC_get_desired_temperature()
{
    return HVAC_fake_get_desired_temperature();
}

float __wrap_HVAC_get_current_temperature()
{
    return HVAC_fake_get_current_temperature();
}

static int setup(void** state)
{
    HVAC_fake_init();
    return 0;
}

static void test_regulate_temperature_too_cold(void **state)
{
    HVAC_fake_set_desired_temperature(23);
    HVAC_fake_set_current_temperature(20);

    regulate_temperature();

    assert_int_equal(true, HVAC_fake_get_heater());
    assert_int_equal(false,HVAC_fake_get_cooler());
}
static void test_regulate_temperature_too_hot(void **state)
{
    HVAC_fake_set_desired_temperature(23);
    HVAC_fake_set_current_temperature(27);

    regulate_temperature();

    assert_int_equal(false, HVAC_fake_get_heater());
    assert_int_equal(true, HVAC_fake_get_cooler());
}

static void test_regulate_temperature_ok(void **state)
{
    HVAC_fake_set_desired_temperature(23);
    HVAC_fake_set_current_temperature(23);

    regulate_temperature();

    assert_int_equal(false, HVAC_fake_get_heater());
    assert_int_equal(false, HVAC_fake_get_cooler());
}

int main(void) {
    const struct CMUnitTest tests[] =
            {
            cmocka_unit_test_setup(test_regulate_temperature_too_cold, setup),
            cmocka_unit_test_setup(test_regulate_temperature_too_hot, setup),
            cmocka_unit_test_setup(test_regulate_temperature_ok, setup),
            };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
