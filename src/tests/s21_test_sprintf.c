#include "s21_test_sprintf.h"

START_TEST(test_s21_sprintf_basic) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};

  // Тест с целыми числами
  s21_sprintf(s21_buffer, "%d", 42);
  snprintf(std_buffer, 100, "%d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест с символами
  s21_sprintf(s21_buffer, "%c", 'A');
  snprintf(std_buffer, 100, "%c", 'A');
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест с плавающей точкой
  s21_sprintf(s21_buffer, "%.2f", 3.14159);
  snprintf(std_buffer, 100, "%.2f", 3.14159);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест со строками
  s21_sprintf(s21_buffer, "%s", "Hello");
  snprintf(std_buffer, 100, "%s", "Hello");
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест с символом '%'
  s21_sprintf(s21_buffer, "%%");
  snprintf(std_buffer, 100, "%%");
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_width_precision) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};

  // Тест ширины и точности с плавающей точкой
  s21_sprintf(s21_buffer, "%10.2f", 123.456);
  snprintf(std_buffer, 100, "%10.2f", 123.456);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест ширины с целым числом
  s21_sprintf(s21_buffer, "%5d", 42);
  snprintf(std_buffer, 100, "%5d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест ширины и отрицательного числа
  s21_sprintf(s21_buffer, "%5d", -42);
  snprintf(std_buffer, 100, "%5d", -42);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_flags) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};

  // Флаг '+'
  s21_sprintf(s21_buffer, "%+d", 42);
  snprintf(std_buffer, 100, "%+d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Флаг ' '
  s21_sprintf(s21_buffer, "% d", 42);
  snprintf(std_buffer, 100, "% d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Флаг '-'
  s21_sprintf(s21_buffer, "%-5d", 42);
  snprintf(std_buffer, 100, "%-5d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_length_modifiers) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};

  s21_sprintf(s21_buffer, "%hu", (unsigned short)65535);
  snprintf(std_buffer, 100, "%hu", (unsigned short)65535);
  ck_assert_str_eq(s21_buffer, std_buffer);

  s21_sprintf(s21_buffer, "%ld", (long)1234567890);
  snprintf(std_buffer, 100, "%ld", (long)1234567890);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_edge_cases) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};

  // Пустая строка вместо NULL
  s21_sprintf(s21_buffer, "%s", "");
  snprintf(std_buffer, 100, "%s", "");
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Точность для %d
  s21_sprintf(s21_buffer, "%.0d", 0);
  snprintf(std_buffer, 100, "%.0d", 0);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Нулевая ширина
  s21_sprintf(s21_buffer, "%0d", 42);
  snprintf(std_buffer, 100, "%0d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Комбинация флагов
  s21_sprintf(s21_buffer, "%-+5d", 42);
  snprintf(std_buffer, 100, "%-+5d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_zero_width_precision) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};

  // Точность и ширина равны 0
  s21_sprintf(s21_buffer, "%.0d", 0);
  snprintf(std_buffer, 100, "%.0d", 0);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Точность 0, но не 0 число
  s21_sprintf(s21_buffer, "%.0d", 42);
  snprintf(std_buffer, 100, "%.0d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_unsigned_edge) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};

  // Тест с максимальным значением unsigned
  s21_sprintf(s21_buffer, "%u", (unsigned int)4294967295);
  snprintf(std_buffer, 100, "%u", (unsigned int)4294967295);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест с минимальным значением
  s21_sprintf(s21_buffer, "%u", 0);
  snprintf(std_buffer, 100, "%u", 0);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_edge_cases2) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};

  // Тесты для спецификатора %d с различными длинами
  s21_sprintf(s21_buffer, "%hd", (short)32767);
  snprintf(std_buffer, 100, "%hd", (short)32767);
  ck_assert_str_eq(s21_buffer, std_buffer);

  s21_sprintf(s21_buffer, "%ld", (long)-9223372036854775807);
  snprintf(std_buffer, 100, "%ld", (long)-9223372036854775807);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Проверка флага '+' и пробела
  s21_sprintf(s21_buffer, "%+d", 42);
  snprintf(std_buffer, 100, "%+d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  s21_sprintf(s21_buffer, "% d", 42);
  snprintf(std_buffer, 100, "% d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Смешанные спецификаторы
  s21_sprintf(s21_buffer, "%5.3d", 123);
  snprintf(std_buffer, 100, "%5.3d", 123);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Проверка с нулевым указателем для строки
  s21_sprintf(s21_buffer, "%s", NULL);
  snprintf(std_buffer, 100, "%s", "(null)");
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_long_numbers) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};

  // Проверка минимального значения long
  s21_sprintf(s21_buffer, "%ld", (long)-9223372036854775807);
  snprintf(std_buffer, 100, "%ld", (long)-9223372036854775807);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Проверка положительного значения long
  s21_sprintf(s21_buffer, "%ld", (long)9223372036854775807);
  snprintf(std_buffer, 100, "%ld", (long)9223372036854775807);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_short) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};

  // Пример с коротким числом
  short short_num = 123;
  s21_sprintf(s21_buffer, "%hd", short_num);
  snprintf(std_buffer, 100, "%hd", short_num);
  ck_assert_str_eq(s21_buffer, std_buffer);

  short_num = -123;
  s21_sprintf(s21_buffer, "%hd", short_num);
  snprintf(std_buffer, 100, "%hd", short_num);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_unsigned) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};

  unsigned int unsigned_num = 12345;
  s21_sprintf(s21_buffer, "%u", unsigned_num);
  snprintf(std_buffer, 100, "%u", unsigned_num);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_width_and_precision) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};

  s21_sprintf(s21_buffer, "%10.4d", 123);
  snprintf(std_buffer, 100, "%10.4d", 123);
  ck_assert_str_eq(s21_buffer, std_buffer);

  s21_sprintf(s21_buffer, "%10.4f", 123.4567);
  snprintf(std_buffer, 100, "%10.4f", 123.4567);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_flags_combination) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};

  s21_sprintf(s21_buffer, "%+d", 123);
  snprintf(std_buffer, 100, "%+d", 123);
  ck_assert_str_eq(s21_buffer, std_buffer);

  s21_sprintf(s21_buffer, "% d", -123);
  snprintf(std_buffer, 100, "% d", -123);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_short_long_modifiers) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};

  // Спецификатор с модификатором h
  short short_val = 123;
  s21_sprintf(s21_buffer, "%hd", short_val);
  snprintf(std_buffer, 100, "%hd", short_val);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Спецификатор с модификатором l
  long long_val = 123456789;
  s21_sprintf(s21_buffer, "%ld", long_val);
  snprintf(std_buffer, 100, "%ld", long_val);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_flags_combinations) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};

  // Флаг "+"
  s21_sprintf(s21_buffer, "%+d", 42);
  snprintf(std_buffer, 100, "%+d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Флаг " "
  s21_sprintf(s21_buffer, "% d", 42);
  snprintf(std_buffer, 100, "% d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Флаг "-"
  s21_sprintf(s21_buffer, "%-10d", 42);
  snprintf(std_buffer, 100, "%-10d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_unsigned2) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};

  // Беззнаковое число
  snprintf(std_buffer, 100, "%lu", 4294967295UL);
  s21_sprintf(s21_buffer, "%lu", 4294967295UL);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_precision) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};

  // Точность для числа
  s21_sprintf(s21_buffer, "%.5d", 42);
  snprintf(std_buffer, 100, "%.5d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Точность для строки
  s21_sprintf(s21_buffer, "%.3s", "hello");
  snprintf(std_buffer, 100, "%.3s", "hello");
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_empty_string_with_width) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};

  int s21_res = s21_sprintf(s21_buffer, "|%-10s|", "");
  int std_res = snprintf(std_buffer, 100, "|%-10s|", "");

  ck_assert_int_eq(s21_res, std_res);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

Suite *s21_sprintf_suite(void) {
  Suite *s = suite_create("s21_sprintf");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_sprintf_basic);
  tcase_add_test(tc_core, test_s21_sprintf_width_precision);
  tcase_add_test(tc_core, test_s21_sprintf_flags);
  tcase_add_test(tc_core, test_s21_sprintf_length_modifiers);
  tcase_add_test(tc_core, test_s21_sprintf_edge_cases);
  tcase_add_test(tc_core, test_s21_sprintf_zero_width_precision);
  tcase_add_test(tc_core, test_s21_sprintf_unsigned_edge);
  tcase_add_test(tc_core, test_s21_sprintf_edge_cases2);
  tcase_add_test(tc_core, test_s21_sprintf_long_numbers);
  tcase_add_test(tc_core, test_s21_sprintf_short);
  tcase_add_test(tc_core, test_s21_sprintf_unsigned);
  tcase_add_test(tc_core, test_s21_sprintf_width_and_precision);
  tcase_add_test(tc_core, test_s21_sprintf_flags_combination);
  tcase_add_test(tc_core, test_s21_sprintf_short_long_modifiers);
  tcase_add_test(tc_core, test_s21_sprintf_flags_combinations);
  tcase_add_test(tc_core, test_s21_sprintf_unsigned2);
  tcase_add_test(tc_core, test_s21_sprintf_precision);
  tcase_add_test(tc_core, test_s21_sprintf_empty_string_with_width);

  suite_add_tcase(s, tc_core);
  return s;
}

int test_sprintf(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_sprintf_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_VERBOSE);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}
