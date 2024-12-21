#include "tests/s21_test_part5.h"
#include "tests/s21_test_sprintf.h"
#include "tests/s21_test_string.h"

int main(void) {
  int no_failed = 0;

  no_failed |= test_string();
  no_failed |= test_sprintf();
  no_failed |= test_part5();

  return (no_failed == 0) ? 0 : 1;
}
