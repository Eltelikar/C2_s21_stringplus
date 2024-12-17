#include "s21_test_sprintf.h"

START_TEST(test_s21_sprintf_basic) {
  char s21_buffer[100];
  char std_buffer[100];

  // Тест с целыми числами
  s21_sprintf(s21_buffer, "%d", 42);
  sprintf(std_buffer, "%d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест с символами
  s21_sprintf(s21_buffer, "%c", 'A');
  sprintf(std_buffer, "%c", 'A');
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест с плавающей точкой
  s21_sprintf(s21_buffer, "%.2f", 3.14159);
  sprintf(std_buffer, "%.2f", 3.14159);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест со строками
  s21_sprintf(s21_buffer, "%s", "Hello");
  sprintf(std_buffer, "%s", "Hello");
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест с символом '%'
  s21_sprintf(s21_buffer, "%%");
  sprintf(std_buffer, "%%");
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_width_precision) {
  char s21_buffer[100];
  char std_buffer[100];

  // Тест ширины и точности с плавающей точкой
  s21_sprintf(s21_buffer, "%10.2f", 123.456);
  sprintf(std_buffer, "%10.2f", 123.456);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест ширины с целым числом
  s21_sprintf(s21_buffer, "%5d", 42);
  sprintf(std_buffer, "%5d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест ширины и отрицательного числа
  s21_sprintf(s21_buffer, "%5d", -42);
  sprintf(std_buffer, "%5d", -42);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_flags) {
  char s21_buffer[100];
  char std_buffer[100];

  // Флаг '+'
  s21_sprintf(s21_buffer, "%+d", 42);
  sprintf(std_buffer, "%+d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Флаг ' '
  s21_sprintf(s21_buffer, "% d", 42);
  sprintf(std_buffer, "% d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Флаг '-'
  s21_sprintf(s21_buffer, "%-5d", 42);
  sprintf(std_buffer, "%-5d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_length_modifiers) {
  char s21_buffer[100];
  char std_buffer[100];

  s21_sprintf(s21_buffer, "%hu", (unsigned short)65535);
  sprintf(std_buffer, "%hu", (unsigned short)65535);
  ck_assert_str_eq(s21_buffer, std_buffer);

  s21_sprintf(s21_buffer, "%ld", (long)1234567890);
  sprintf(std_buffer, "%ld", (long)1234567890);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_edge_cases) {
  char s21_buffer[100];
  char std_buffer[100];

  // Пустая строка вместо NULL
  s21_sprintf(s21_buffer, "%s", "");
  sprintf(std_buffer, "%s", "");
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Точность для %d
  s21_sprintf(s21_buffer, "%.0d", 0);
  sprintf(std_buffer, "%.0d", 0);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Нулевая ширина
  s21_sprintf(s21_buffer, "%0d", 42);
  sprintf(std_buffer, "%0d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Комбинация флагов
  s21_sprintf(s21_buffer, "%-+5d", 42);
  sprintf(std_buffer, "%-+5d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_zero_width_precision) {
  char s21_buffer[100];
  char std_buffer[100];

  // Точность и ширина равны 0
  s21_sprintf(s21_buffer, "%.0d", 0);
  sprintf(std_buffer, "%.0d", 0);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Точность 0, но не 0 число
  s21_sprintf(s21_buffer, "%.0d", 42);
  sprintf(std_buffer, "%.0d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_unsigned_edge) {
  char s21_buffer[100];
  char std_buffer[100];

  // Тест с максимальным значением unsigned
  s21_sprintf(s21_buffer, "%u", (unsigned int)4294967295);
  sprintf(std_buffer, "%u", (unsigned int)4294967295);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест с минимальным значением
  s21_sprintf(s21_buffer, "%u", 0);
  sprintf(std_buffer, "%u", 0);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_multiple_specifiers) {
  char s21_buffer[512];
  char std_buffer[512];

  // Смешанные спецификаторы
  s21_sprintf(s21_buffer, "%d %c %.2f %s", 42, 'A', 3.1415, "Hello");
  sprintf(std_buffer, "%d %c %.2f %s", 42, 'A', 3.1415, "Hello");
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_edge_cases2) {
  char s21_buffer[100];
  char std_buffer[100];

  // Тесты для спецификатора %d с различными длинами
  s21_sprintf(s21_buffer, "%hd", (short)32767);
  sprintf(std_buffer, "%hd", (short)32767);
  ck_assert_str_eq(s21_buffer, std_buffer);

  s21_sprintf(s21_buffer, "%ld", (long)-9223372036854775807);
  sprintf(std_buffer, "%ld", (long)-9223372036854775807);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Проверка флага '+' и пробела
  s21_sprintf(s21_buffer, "%+d", 42);
  sprintf(std_buffer, "%+d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  s21_sprintf(s21_buffer, "% d", 42);
  sprintf(std_buffer, "% d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Смешанные спецификаторы
  s21_sprintf(s21_buffer, "%5.3d", 123);
  sprintf(std_buffer, "%5.3d", 123);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Проверка с нулевым указателем для строки
  s21_sprintf(s21_buffer, "%s", NULL);
  sprintf(std_buffer, "%s", "(null)");
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_long_numbers) {
  char s21_buffer[100];
  char std_buffer[100];

  // Проверка минимального значения long
  s21_sprintf(s21_buffer, "%ld", (long)-9223372036854775807);
  sprintf(std_buffer, "%ld", (long)-9223372036854775807);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Проверка положительного значения long
  s21_sprintf(s21_buffer, "%ld", (long)9223372036854775807);
  sprintf(std_buffer, "%ld", (long)9223372036854775807);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_short) {
  char s21_buffer[100];
  char std_buffer[100];

  // Пример с коротким числом
  short short_num = 123;
  s21_sprintf(s21_buffer, "%hd", short_num);
  sprintf(std_buffer, "%hd", short_num);
  ck_assert_str_eq(s21_buffer, std_buffer);

  short_num = -123;
  s21_sprintf(s21_buffer, "%hd", short_num);
  sprintf(std_buffer, "%hd", short_num);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_unsigned) {
  char s21_buffer[100];
  char std_buffer[100];

  unsigned int unsigned_num = 12345;
  s21_sprintf(s21_buffer, "%u", unsigned_num);
  sprintf(std_buffer, "%u", unsigned_num);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_width_and_precision) {
  char s21_buffer[100];
  char std_buffer[100];

  s21_sprintf(s21_buffer, "%10.4d", 123);
  sprintf(std_buffer, "%10.4d", 123);
  ck_assert_str_eq(s21_buffer, std_buffer);

  s21_sprintf(s21_buffer, "%10.4f", 123.4567);
  sprintf(std_buffer, "%10.4f", 123.4567);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_flags_combination) {
  char s21_buffer[100];
  char std_buffer[100];

  s21_sprintf(s21_buffer, "%+d", 123);
  sprintf(std_buffer, "%+d", 123);
  ck_assert_str_eq(s21_buffer, std_buffer);

  s21_sprintf(s21_buffer, "% d", -123);
  sprintf(std_buffer, "% d", -123);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_short_long_modifiers) {
  char s21_buffer[100];
  char std_buffer[100];

  // Спецификатор с модификатором h
  short short_val = 123;
  s21_sprintf(s21_buffer, "%hd", short_val);
  sprintf(std_buffer, "%hd", short_val);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Спецификатор с модификатором l
  long long_val = 123456789;
  s21_sprintf(s21_buffer, "%ld", long_val);
  sprintf(std_buffer, "%ld", long_val);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_flags_combinations) {
  char s21_buffer[100];
  char std_buffer[100];

  // Флаг "+"
  s21_sprintf(s21_buffer, "%+d", 42);
  sprintf(std_buffer, "%+d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Флаг " "
  s21_sprintf(s21_buffer, "% d", 42);
  sprintf(std_buffer, "% d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Флаг "-"
  s21_sprintf(s21_buffer, "%-10d", 42);
  sprintf(std_buffer, "%-10d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_unsigned2) {
  char s21_buffer[100];
  char std_buffer[100];

  // Беззнаковое число
  sprintf(std_buffer, "%lu", 4294967295UL);
  s21_sprintf(s21_buffer, "%lu", 4294967295UL);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_precision) {
  char s21_buffer[100];
  char std_buffer[100];

  // Точность для числа
  s21_sprintf(s21_buffer, "%.5d", 42);
  sprintf(std_buffer, "%.5d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Точность для строки
  s21_sprintf(s21_buffer, "%.3s", "hello");
  sprintf(std_buffer, "%.3s", "hello");
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_empty_string_with_width) {
    char s21_buffer[100];
    char std_buffer[100];

    int s21_res = s21_sprintf(s21_buffer, "|%-10s|", "");
    int std_res = sprintf(std_buffer, "|%-10s|", "");

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
  tcase_add_test(tc_core, test_s21_sprintf_multiple_specifiers);
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
