#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include "cmocka.h"

#include "HVAC.h"

static void test_something(void **state)
{
    assert_int_equal(42, 4);
}

int main(void) {
    const struct CMUnitTest tests[] =
            {
            cmocka_unit_test(test_something),
            };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
