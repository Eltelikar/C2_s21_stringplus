#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  if (str == S21_NULL || format == S21_NULL) {
    return -1;
  }
  int error = 0;
  va_list args;
  char *cur = str;
  s21_memset(str, 0, 100);

  va_start(args, format);

  while (*format) {
    if (*format == '%') {
      format++;
      FormatSpec spec = {0, 0, 0, 0, -1, 0, 0};
      s21_parse_format(&format, &spec);
      s21_parse_handle(&cur, &format, args, spec, &error);
    } else {
      *cur++ = *format;
    }
    format++;
  }

  *cur = '\0';
  va_end(args);

  int result = -1;
  if (error == 0) result = cur - str;

  return result;
}

void s21_parse_handle(char **cur, const char **format, va_list args,
                      FormatSpec spec, int *error) {
  switch (**format) {
    case 'u': {
      unsigned long long value;
      if (spec.is_long) {
        value = va_arg(args, unsigned long);
      } else if (spec.is_short) {
        value = (unsigned short)va_arg(args, unsigned int);
      } else {
        value = va_arg(args, unsigned int);
      }
      s21_handle_unsigned(cur, value, spec);
      break;
    }
    case 'd': {
      long long value;
      if (spec.is_long) {
        value = va_arg(args, long);
      } else {
        value = va_arg(args, int);
      }
      s21_handle_int(cur, value, spec);
      break;
    }
    case 'f': {
      double value = va_arg(args, double);
      if (spec.precision == -1) spec.precision = 6;
      s21_handle_float(cur, value, spec);
      break;
    }
    case 'c': {
      char value = (char)va_arg(args, int);
      s21_handle_char(cur, value, spec);
      break;
    }
    case 's': {
      char *value = va_arg(args, char *);
      if (value == S21_NULL) {
        value = "(null)";
      }
      s21_handle_string(cur, value, spec);
      break;
    }
    case '%': {
      *(*cur)++ = '%';
      break;
    }
    default:
      *error = 1;
      break;
  }
}

void s21_parse_format(const char **format, FormatSpec *spec) {
  while (**format == '-' || **format == '+' || **format == ' ') {
    if (**format == '-') spec->minus = 1;
    if (**format == '+') spec->plus = 1;
    if (**format == ' ') spec->space = 1;
    (*format)++;
  }

  while (**format >= '0' && **format <= '9') {
    spec->width = spec->width * 10 + (**format - '0');
    (*format)++;
  }

  if (**format == '.') {
    (*format)++;
    spec->precision = 0;
    while (**format >= '0' && **format <= '9') {
      spec->precision = spec->precision * 10 + (**format - '0');
      (*format)++;
    }
  }

  if (**format == 'h') {
    spec->is_short = 1;
    (*format)++;
  } else if (**format == 'l') {
    spec->is_long = 1;
    (*format)++;
  }
}

void s21_handle_unsigned(char **cur, unsigned long long value,
                         FormatSpec spec) {
  char temp[50];
  s21_unsigned_to_str(value, temp);
  s21_handle_numeric(cur, temp, 0, spec);
}

void s21_handle_numeric(char **cur, const char *formatted_value,
                        int is_negative, FormatSpec spec) {
  int len = s21_strlen(formatted_value);
  if (is_negative) len++;
  if (spec.plus && !is_negative) {
    len++;
  } else if (spec.space && !is_negative) {
    len++;
  }

  int padding = spec.width - len;

  if (padding > 0) {
    if (spec.minus) {
      if (spec.plus && !is_negative)
        *(*cur)++ = '+';
      else if (spec.space && !is_negative)
        *(*cur)++ = ' ';
      else if (is_negative)
        *(*cur)++ = '-';

      s21_strncpy(*cur, formatted_value, s21_strlen(formatted_value) + 1);
      *cur += s21_strlen(formatted_value);
      for (int i = 0; i < padding; i++) *(*cur)++ = ' ';
    } else {
      for (int i = 0; i < padding; i++) *(*cur)++ = ' ';

      if (spec.plus && !is_negative)
        *(*cur)++ = '+';
      else if (spec.space && !is_negative)
        *(*cur)++ = ' ';
      else if (is_negative)
        *(*cur)++ = '-';

      s21_strncpy(*cur, formatted_value, s21_strlen(formatted_value) + 1);
      *cur += s21_strlen(formatted_value);
    }
  } else {
    if (spec.plus && !is_negative)
      *(*cur)++ = '+';
    else if (spec.space && !is_negative)
      *(*cur)++ = ' ';
    else if (is_negative)
      *(*cur)++ = '-';

    s21_strncpy(*cur, formatted_value, s21_strlen(formatted_value) + 1);
    *cur += s21_strlen(formatted_value);
  }
}

void s21_handle_int(char **cur, long long value, FormatSpec spec) {
  if (spec.precision == 0 && value == 0) {
    return;
  }
  char temp[50];
  if (spec.precision == -1) spec.precision = 0;

  int is_negative = (value < 0);
  if (is_negative) {
    value = -value;
  }

  s21_int_to_str(value, temp, spec.precision);
  s21_handle_numeric(cur, temp, is_negative, spec);
}

void s21_handle_float(char **cur, double value, FormatSpec spec) {
  char temp[50];
  s21_float_to_str(value, temp, spec.precision);
  s21_handle_numeric(cur, temp, value < 0, spec);
}

void s21_handle_padding(char **cur, const char *value, int len,
                        FormatSpec spec) {
  if (spec.width > len) {
    if (spec.minus) {
      s21_strncpy(*cur, value, len);
      *cur += len;
      for (int i = len; i < spec.width; i++) *(*cur)++ = ' ';
    } else {
      for (int i = len; i < spec.width; i++) *(*cur)++ = ' ';
      s21_strncpy(*cur, value, len);
      *cur += len;
    }
  } else {
    s21_strncpy(*cur, value, len);
    *cur += len;
  }
}

void s21_handle_char(char **cur, char value, FormatSpec spec) {
  char temp[2] = {value, '\0'};
  if (*cur) {
    s21_handle_padding(cur, temp, 1, spec);
  }
}

void s21_handle_string(char **cur, char *value, FormatSpec spec) {
  if (value == S21_NULL) {
    value = "(null)";
  }

  int len = s21_strlen(value);

  if (spec.precision >= 0 && spec.precision < len) {
    len = spec.precision;
  }

  if (*cur) {
    s21_handle_padding(cur, value, len, spec);
  }
}

void s21_int_to_str(long long value, char *str, int precision) {
  int i = 0;
  if (value < 0) value = -value;
  do {
    str[i++] = (value % 10) + '0';
    value /= 10;
  } while (value > 0);

  while (i < precision) {
    str[i++] = '0';
  }

  for (int j = 0; j < i / 2; j++) {
    char temp = str[j];
    str[j] = str[i - j - 1];
    str[i - j - 1] = temp;
  }

  str[i] = '\0';
}

void s21_float_to_str(double num, char *str, int precision) {
  int i = 0;

  if (num < 0) num = -num;

  double factor = 1.0;
  for (int j = 0; j < precision; j++) {
    factor *= 10.0;
  }

  num = (long long)(num * factor + 0.5);

  long long int_part = (long long)(num / factor);
  long long frac_part = (long long)(num) % (long long)factor;

  if (int_part == 0) {
    str[i++] = '0';
  } else {
    char int_str[20];
    int j = 0;

    while (int_part > 0) {
      int_str[j++] = (int_part % 10) + '0';
      int_part /= 10;
    }

    for (int k = j - 1; k >= 0; k--) {
      str[i++] = int_str[k];
    }
  }

  if (precision > 0) {
    str[i++] = '.';

    for (int j = 0; j < precision; j++) {
      frac_part *= 10;
      str[i++] = (frac_part / (long long)factor) + '0';
      frac_part %= (long long)factor;
    }
  }

  str[i] = '\0';
}

void s21_unsigned_to_str(unsigned long long num, char *str) {
  int i = 0;

  if (num == 0) {
    str[i++] = '0';
  } else {
    char temp[20];
    int j = 0;

    while (num > 0) {
      temp[j++] = (num % 10) + '0';
      num /= 10;
    }

    for (int k = j - 1; k >= 0; k--) {
      str[i++] = temp[k];
    }
  }

  str[i] = '\0';
}