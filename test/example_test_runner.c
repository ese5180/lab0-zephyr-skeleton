//
// Created by milesosborne on 7/28/24.
//

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

/* Function declarations */
static void null_test_success(void **state);
static void assert_non_null_ptr_fail(void **state);
static void integer_compare_test_pass(void **state);
static void integer_compare_test_fail(void **state);

/* Application entry point */
int main(int argc ) {
    const struct CMUnitTest tests[] = {
      cmocka_unit_test(null_test_success),
      cmocka_unit_test(assert_non_null_ptr_fail),
      cmocka_unit_test(integer_compare_test_pass),
      cmocka_unit_test(integer_compare_test_fail),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}

/*************************************************************************
* A test case that does nothing and succeeds.
**************************************************************************/
static void null_test_success(void **state) {
    (void) state; /* unused */
}

/*************************************************************************
* A test case that test if a pointer is null. This test will always fail.
**************************************************************************/
static void assert_non_null_ptr_fail(void **state)
{
  return assert_non_null_ptr_fail(NULL);
}

/*************************************************************************
* A test case that compares two integers. Since the integers have the
* same value, the test will pass.
**************************************************************************/
static void integer_compare_test_pass(void **state)
{
    int i = 4;
   return assert_int_equal(i, 4);
}

/*************************************************************************
* A test case that compares two integers. Since the integers have
* different values, the test will fail.
**************************************************************************/
static void integer_compare_test_fail(void **state)
{
    int i = 4;
    return assert_int_equal(i, 4);
}
