#include "s21_test_part5.h"

START_TEST(test_s21_to_upper_basic) {
  char *result = s21_to_upper("hello, world!");
  ck_assert_str_eq(result, "HELLO, WORLD!");
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_mixed_case) {
  char *result = s21_to_upper("HeLLo, WoRLd!");
  ck_assert_str_eq(result, "HELLO, WORLD!");
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_all_upper) {
  char *result = s21_to_upper("HELLO, WORLD!");
  ck_assert_str_eq(result, "HELLO, WORLD!");
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_empty_string) {
  char *result = s21_to_upper("");
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_numbers) {
  char *result = s21_to_upper("12345");
  ck_assert_str_eq(result, "12345");
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_special_characters) {
  char *result = s21_to_upper("!@#$%^&*()");
  ck_assert_str_eq(result, "!@#$%^&*()");
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_null) {
  char *result = s21_to_upper(NULL);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(test_s21_to_lower_basic) {
  char *result = s21_to_lower("HELLO, WORLD!");
  ck_assert_str_eq(result, "hello, world!");
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_mixed_case) {
  char *result = s21_to_lower("HeLLo, WoRLd!");
  ck_assert_str_eq(result, "hello, world!");
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_all_lower) {
  char *result = s21_to_lower("hello, world!");
  ck_assert_str_eq(result, "hello, world!");
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_empty_string) {
  char *result = s21_to_lower("");
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_numbers) {
  char *result = s21_to_lower("12345");
  ck_assert_str_eq(result, "12345");
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_special_characters) {
  char *result = s21_to_lower("!@#$%^&*()");
  ck_assert_str_eq(result, "!@#$%^&*()");
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_null) {
  char *result = s21_to_lower(NULL);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(test_s21_insert_basic) {
  char *result = s21_insert("Hello, world!", "INSERT", 7);
  ck_assert_str_eq(result, "Hello, INSERTworld!");
  free(result);
}
END_TEST

START_TEST(test_s21_insert_start) {
  char *result = s21_insert("Hello, world!", "START_", 0);
  ck_assert_str_eq(result, "START_Hello, world!");
  free(result);
}
END_TEST

START_TEST(test_s21_insert_end) {
  char *result = s21_insert("Hello, world!", "_END", 13);
  ck_assert_str_eq(result, "Hello, world!_END");
  free(result);
}
END_TEST

START_TEST(test_s21_insert_empty_source) {
  char *result = s21_insert("", "INSERT", 0);
  ck_assert_str_eq(result, "INSERT");
  free(result);
}
END_TEST

START_TEST(test_s21_insert_empty_insert) {
  char *result = s21_insert("Hello, world!", "", 5);
  ck_assert_str_eq(result, "Hello, world!");
  free(result);
}
END_TEST

START_TEST(test_s21_insert_null_source) {
  char *result = s21_insert(NULL, "INSERT", 5);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(test_s21_insert_null_insert) {
  char *result = s21_insert("Hello, world!", NULL, 5);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(test_s21_insert_out_of_bounds) {
  char *result = s21_insert("Hello, world!", "OUT", 20);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(test_s21_insert_at_middle) {
  char *result = s21_insert("123456789", "INSERT", 4);
  ck_assert_str_eq(result, "1234INSERT56789");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_basic) {
  char *result = s21_trim("  Hello, world!  ", " ");
  ck_assert_str_eq(result, "Hello, world!");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_empty_trim_chars) {
  char *result = s21_trim("  Hello, world!  ", "");
  ck_assert_str_eq(result, "  Hello, world!  ");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_empty_string) {
  char *result = s21_trim("", " ");
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_no_trim_chars) {
  char *result = s21_trim("Hello, world!", NULL);
  ck_assert_str_eq(result, "Hello, world!");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_no_trimming_needed) {
  char *result = s21_trim("Hello, world!", " ");
  ck_assert_str_eq(result, "Hello, world!");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_trimming_multiple_chars) {
  char *result = s21_trim("aa--Hello--aa", "a-");
  ck_assert_str_eq(result, "Hello");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_only_trim_chars) {
  char *result = s21_trim("aaaa", "a");
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_null_src) {
  char *result = s21_trim(NULL, " ");
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(test_s21_trim_null_trim_chars) {
  char *result = s21_trim("Hello, world!", NULL);
  ck_assert_str_eq(result, "Hello, world!");
  free(result);
}
END_TEST

Suite *s21_part5_suite(void) {
  Suite *s = suite_create("s21_part5");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_to_upper_basic);
  tcase_add_test(tc_core, test_s21_to_upper_mixed_case);
  tcase_add_test(tc_core, test_s21_to_upper_all_upper);
  tcase_add_test(tc_core, test_s21_to_upper_empty_string);
  tcase_add_test(tc_core, test_s21_to_upper_numbers);
  tcase_add_test(tc_core, test_s21_to_upper_special_characters);
  tcase_add_test(tc_core, test_s21_to_upper_null);

  tcase_add_test(tc_core, test_s21_to_lower_basic);
  tcase_add_test(tc_core, test_s21_to_lower_mixed_case);
  tcase_add_test(tc_core, test_s21_to_lower_all_lower);
  tcase_add_test(tc_core, test_s21_to_lower_empty_string);
  tcase_add_test(tc_core, test_s21_to_lower_numbers);
  tcase_add_test(tc_core, test_s21_to_lower_special_characters);
  tcase_add_test(tc_core, test_s21_to_lower_null);

  tcase_add_test(tc_core, test_s21_insert_basic);
  tcase_add_test(tc_core, test_s21_insert_start);
  tcase_add_test(tc_core, test_s21_insert_end);
  tcase_add_test(tc_core, test_s21_insert_empty_source);
  tcase_add_test(tc_core, test_s21_insert_empty_insert);
  tcase_add_test(tc_core, test_s21_insert_null_source);
  tcase_add_test(tc_core, test_s21_insert_null_insert);
  tcase_add_test(tc_core, test_s21_insert_out_of_bounds);
  tcase_add_test(tc_core, test_s21_insert_at_middle);

  tcase_add_test(tc_core, test_s21_trim_basic);
  tcase_add_test(tc_core, test_s21_trim_empty_trim_chars);
  tcase_add_test(tc_core, test_s21_trim_empty_string);
  tcase_add_test(tc_core, test_s21_trim_no_trim_chars);
  tcase_add_test(tc_core, test_s21_trim_no_trimming_needed);
  tcase_add_test(tc_core, test_s21_trim_trimming_multiple_chars);
  tcase_add_test(tc_core, test_s21_trim_only_trim_chars);
  tcase_add_test(tc_core, test_s21_trim_null_src);
  tcase_add_test(tc_core, test_s21_trim_null_trim_chars);

  suite_add_tcase(s, tc_core);
  return s;
}

int test_part5(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_part5_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_VERBOSE);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}