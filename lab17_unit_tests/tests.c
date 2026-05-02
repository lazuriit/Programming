#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "math.h"

static void test_sum(void **state) {
    assert_int_equal(sum(15, 4), 19);
}
static void test_difference(void **state) {
    assert_int_equal(difference(15, 4), 11);
}
static void test_multiplication(void **state) {
    assert_int_equal(multiplication(15, 4), 60);
}
static void test_real_division(void **state) {
    assert_float_equal(real_division(15, 4), 3.75f, 0.001f);
}
static void test_remainder_of_division(void **state) {
    assert_int_equal(remainder_of_division(15, 4), 3);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_sum),
        cmocka_unit_test(test_difference),
        cmocka_unit_test(test_multiplication),
        cmocka_unit_test(test_real_division),
        cmocka_unit_test(test_remainder_of_division),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
