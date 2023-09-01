project(hvac_test C)

add_cmocka_test(hvac_test
        SOURCES hvac_test.c
        LINK_LIBRARIES src cmocka-static)
add_cmocka_test_environment(add_test)
