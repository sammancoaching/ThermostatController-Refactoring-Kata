project(hvac_test C)

add_cmocka_test(hvac_test_stub
        SOURCES hvac_test.c
        LINK_LIBRARIES src cmocka-static)
add_cmocka_test_environment(add_test)

set_property(TARGET
        hvac_test_stub
        PROPERTY
        LINK_FLAGS
        "${DEFAULT_LINK_FLAGS} -Wl,--wrap=HVAC_get_desired_temperature,--wrap=HVAC_get_current_temperature,--wrap=HVAC_set_heater,--wrap=HVAC_set_cooler")
