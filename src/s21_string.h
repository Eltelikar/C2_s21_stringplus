#ifndef S21_STRING
#define S21_STRING

#include <stdarg.h>
#include <stdlib.h>

#include "s21_errorlist.h"

#define S21_NULL ((void *)0)
typedef unsigned long s21_size_t;

// s21_string func
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

// s21_sprintf func
typedef struct {
  int minus;
  int plus;
  int space;
  int width;
  int precision;
  int is_long;
  int is_short;
} FormatSpec;

int s21_sprintf(char *str, const char *format, ...);
void s21_int_to_str(long long value, char *str, int precision);
void s21_float_to_str(double num, char *str, int precision);
void s21_unsigned_to_str(unsigned long long num, char *str);
void s21_handle_unsigned(char **cur, unsigned long long value, FormatSpec spec);
void s21_handle_int(char **cur, long long value, FormatSpec spec);
void s21_handle_float(char **cur, double value, FormatSpec spec);
void s21_handle_char(char **cur, char value, FormatSpec spec);
void s21_handle_string(char **cur, char *value, FormatSpec spec);
void s21_parse_format(const char **format, FormatSpec *spec);
void s21_handle_numeric(char **cur, const char *formatted_value,
                        int is_negative, FormatSpec spec);
void s21_handle_padding(char **cur, const char *value, int len,
                        FormatSpec spec);
void s21_parse_handle(char **cur, const char **format, va_list args,
                      FormatSpec spec, int *error);

// s21_part5 func
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

#endif
