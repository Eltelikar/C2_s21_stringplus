#include "s21_test_string.h"

START_TEST(test_s21_memchr) {
  ck_assert_ptr_eq(s21_memchr("abcdef", 'd', 6), memchr("abcdef", 'd', 6));
  ck_assert_ptr_eq(s21_memchr("abcdef", 'z', 6), memchr("abcdef", 'z', 6));
  ck_assert_ptr_eq(s21_memchr("", 'a', 1), memchr("", 'a', 1));
}
END_TEST

START_TEST(test_s21_memcmp) {
  ck_assert_int_eq(s21_memcmp("abcdef", "abcdef", 6),
                   memcmp("abcdef", "abcdef", 6));
  ck_assert_int_eq(s21_memcmp("abcdef", "abcdeg", 6),
                   memcmp("abcdef", "abcdeg", 6));
  ck_assert_int_eq(s21_memcmp("abcdef", "abcdeg", 3),
                   memcmp("abcdef", "abcdeg", 3));
  ck_assert_int_eq(s21_memcmp("", "", 0), memcmp("", "", 0));
}
END_TEST

START_TEST(test_s21_memcpy) {
  char dest[10] = {0};
  char orig_dest[10] = {0};
  const char *src = "hello";
  s21_memcpy(dest, src, 5);
  memcpy(orig_dest, src, 5);
  ck_assert_mem_eq(dest, orig_dest, sizeof(dest));
}
END_TEST

START_TEST(test_s21_memset) {
  char buffer[10];
  char orig_buffer[10];
  memset(buffer, 0, sizeof(buffer));
  memset(orig_buffer, 0, sizeof(orig_buffer));
  s21_memset(buffer, 'x', 5);
  memset(orig_buffer, 'x', 5);
  ck_assert_mem_eq(buffer, orig_buffer, sizeof(buffer));
}
END_TEST

START_TEST(test_s21_strncat) {
  char dest[20] = "Hello ";
  char orig_dest[20] = "Hello ";
  const char *src = "World!";
  s21_strncat(dest, src, 6);
  strncat(orig_dest, src, 6);
  ck_assert_str_eq(dest, orig_dest);

  s21_strncat(dest, src, 0);
  strncat(orig_dest, src, 0);
  ck_assert_str_eq(dest, orig_dest);
}
END_TEST

START_TEST(test_s21_strchr) {
  ck_assert_ptr_eq(s21_strchr("hello", 'o'), strchr("hello", 'o'));
  ck_assert_ptr_eq(s21_strchr("hello", 'z'), strchr("hello", 'z'));
  ck_assert_ptr_eq(s21_strchr("hello", '\0'), strchr("hello", '\0'));
  ck_assert_ptr_eq(s21_strchr("", 'a'), strchr("", 'a'));
}
END_TEST

START_TEST(test_s21_strncmp) {
  ck_assert_int_eq(s21_strncmp("abc", "abc", 3), strncmp("abc", "abc", 3));
  ck_assert_int_eq(s21_strncmp("abc", "abd", 2), strncmp("abc", "abd", 2));
  ck_assert_int_eq(s21_strncmp("abc", "abd", 3), strncmp("abc", "abd", 3));
  ck_assert_int_eq(s21_strncmp("abc", "abc", 0), strncmp("abc", "abc", 0));
}
END_TEST

START_TEST(test_s21_strncpy) {
  char dest[50];
  char orig_dest[50];

  memset(dest, 0, sizeof(dest));
  memset(orig_dest, 0, sizeof(orig_dest));
  s21_strncpy(dest, "hello", 5);
  memcpy(orig_dest, "hello", 5);
  ck_assert_str_eq(dest, orig_dest);

  memset(dest, 0, sizeof(dest));
  memset(orig_dest, 0, sizeof(orig_dest));
  s21_strncpy(dest, "", 1);
  memcpy(orig_dest, "", 1);
  ck_assert_str_eq(dest, orig_dest);
}
END_TEST

START_TEST(test_s21_strcspn) {
  ck_assert_int_eq(s21_strcspn("hello", "aeiou"), strcspn("hello", "aeiou"));
  ck_assert_int_eq(s21_strcspn("hello", "xyz"), strcspn("hello", "xyz"));
  ck_assert_int_eq(s21_strcspn("hello", ""), strcspn("hello", ""));
  ck_assert_int_eq(s21_strcspn("", "aeiou"), strcspn("", "aeiou"));
}
END_TEST

START_TEST(test_s21_strerror) {
  for (int i = 0; i < ERROR_COUNT; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
  ck_assert_str_eq(s21_strerror(ERROR_COUNT + 1), "Unknown error");
}
END_TEST

START_TEST(test_s21_strlen) {
  ck_assert_int_eq(s21_strlen("hello"), strlen("hello"));
  ck_assert_int_eq(s21_strlen(""), strlen(""));
  ck_assert_int_eq(s21_strlen("1234567890"), strlen("1234567890"));
}
END_TEST

START_TEST(test_s21_strpbrk) {
  ck_assert_ptr_eq(s21_strpbrk("hello", "aeiou"), strpbrk("hello", "aeiou"));
  ck_assert_ptr_eq(s21_strpbrk("hello", "xyz"), strpbrk("hello", "xyz"));
  ck_assert_ptr_eq(s21_strpbrk("", "aeiou"), strpbrk("", "aeiou"));
}
END_TEST

START_TEST(test_s21_strrchr) {
  ck_assert_ptr_eq(s21_strrchr("hello", 'o'), strrchr("hello", 'o'));
  ck_assert_ptr_eq(s21_strrchr("hello", 'z'), strrchr("hello", 'z'));
  ck_assert_ptr_eq(s21_strrchr("hello", '\0'), strrchr("hello", '\0'));
}
END_TEST

START_TEST(test_s21_strstr) {
  ck_assert_ptr_eq(s21_strstr("hello world", "world"),
                   strstr("hello world", "world"));
  ck_assert_ptr_eq(s21_strstr("hello world", "o w"),
                   strstr("hello world", "o w"));
  ck_assert_ptr_eq(s21_strstr("hello world", ""), strstr("hello world", ""));
}
END_TEST

START_TEST(test_s21_strtok) {
  char str1[] = "hello world example";
  char str2[] = "hello world example";
  const char *delim = " ";
  char *token1 = s21_strtok(str1, delim);
  char *token2 = strtok(str2, delim);
  while (token1 && token2) {
    ck_assert_str_eq(token1, token2);
    token1 = s21_strtok(S21_NULL, delim);
    token2 = strtok(S21_NULL, delim);
  }
  ck_assert_ptr_eq(token1, token2);
}
END_TEST

START_TEST(test_s21_memchr_edge_cases) {
  ck_assert_ptr_eq(s21_memchr("abc", 'a', 0), memchr("abc", 'a', 0));
  ck_assert_ptr_eq(s21_memchr("", 'a', 0), memchr("", 'a', 0));
  ck_assert_ptr_eq(s21_memchr("", 'a', 1), memchr("", 'a', 1));
  ck_assert_ptr_eq(s21_memchr("abc", '\0', 4), memchr("abc", '\0', 4));
}
END_TEST

START_TEST(test_s21_memcmp_edge_cases) {
  ck_assert_int_eq(s21_memcmp("abc", "abc", 0), 0);
  ck_assert_int_eq(s21_memcmp("abc", "", 3), 97);
  ck_assert_int_eq(s21_memcmp("", "", 0), 0);
  ck_assert_int_eq(s21_memcmp(NULL, NULL, 0), 0);
}
END_TEST

START_TEST(test_s21_strlen_edge_cases) {
  ck_assert_int_eq(s21_strlen(""), strlen(""));
  ck_assert_int_eq(s21_strlen(NULL), 0);
  ck_assert_int_eq(s21_strlen("a\0b"), strlen("a\0b"));
}
END_TEST

Suite *s21_string_suite(void) {
  Suite *s = suite_create("s21_string");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_memchr);
  tcase_add_test(tc_core, test_s21_memcmp);
  tcase_add_test(tc_core, test_s21_memcpy);
  tcase_add_test(tc_core, test_s21_memset);
  tcase_add_test(tc_core, test_s21_strncat);
  tcase_add_test(tc_core, test_s21_strchr);
  tcase_add_test(tc_core, test_s21_strncmp);
  tcase_add_test(tc_core, test_s21_strncpy);
  tcase_add_test(tc_core, test_s21_strcspn);
  tcase_add_test(tc_core, test_s21_strerror);
  tcase_add_test(tc_core, test_s21_strlen);
  tcase_add_test(tc_core, test_s21_strpbrk);
  tcase_add_test(tc_core, test_s21_strrchr);
  tcase_add_test(tc_core, test_s21_strstr);
  tcase_add_test(tc_core, test_s21_strtok);
  tcase_add_test(tc_core, test_s21_memchr_edge_cases);
  tcase_add_test(tc_core, test_s21_memcmp_edge_cases);
  tcase_add_test(tc_core, test_s21_strlen_edge_cases);

  suite_add_tcase(s, tc_core);
  return s;
}

int test_string(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_string_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_VERBOSE);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}