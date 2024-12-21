#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *result = S21_NULL;
  if (str != S21_NULL) {
    const unsigned char *pointer = (const unsigned char *)str;
    unsigned char target = (unsigned char)c;

    while (n--) {
      if (*pointer == target) {
        result = (void *)pointer;
        break;
      }
      pointer++;
    }
  }
  return result;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  if (n > 0) {
    const unsigned char *pointer1 = (const unsigned char *)str1;
    const unsigned char *pointer2 = (const unsigned char *)str2;
    s21_size_t i = 0;
    while (i < n) {
      if (pointer1[i] != pointer2[i]) {
        result = pointer1[i] - pointer2[i];
        break;
      }
      i++;
    }
  }
  return result;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  if (dest != S21_NULL && src != S21_NULL) {
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;
    for (s21_size_t i = 0; i < n; i++) {
      d[i] = s[i];
    }
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  if (str != S21_NULL && n > 0) {
    unsigned char *pointer = (unsigned char *)str;
    unsigned char value = (unsigned char)c;
    for (s21_size_t i = 0; i < n; i++) {
      pointer[i] = value;
    }
  }
  return str;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *result = dest;
  if (dest != S21_NULL && src != S21_NULL) {
    char *pointer = dest;
    const char *src_ptr = src;

    while (*pointer != '\0') {
      pointer++;
    }

    while (n-- && *src_ptr != '\0') {
      *pointer = *src_ptr;
      pointer++;
      src_ptr++;
    }
    *pointer = '\0';
  }
  return result;
}

char *s21_strchr(const char *str, int c) {
  char *result = S21_NULL;
  if (str != S21_NULL) {
    const char *pointer = str;
    unsigned char value = (unsigned char)c;

    while (*pointer != '\0') {
      if (*pointer == value) {
        result = (char *)pointer;
        break;
      }
      pointer++;
    }

    if (result == S21_NULL && value == '\0') {
      result = (char *)pointer;
    }
  }
  return result;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  if (str1 != S21_NULL && str2 != S21_NULL && n > 0) {
    const char *pointer1 = str1;
    const char *pointer2 = str2;

    while (n-- && (*pointer1 != '\0' || *pointer2 != '\0')) {
      if (*pointer1 != *pointer2) {
        result = (unsigned char)*pointer1 - (unsigned char)*pointer2;
        break;
      }
      pointer1++;
      pointer2++;
    }
  }
  return result;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *result = S21_NULL;
  if (dest != S21_NULL && src != S21_NULL) {
    s21_size_t i = 0;
    for (; i < n && src[i] != '\0'; i++) {
      dest[i] = src[i];
    }

    for (; i < n; i++) {
      dest[i] = '\0';
    }

    result = dest;
  }
  return result;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  if (str1 != S21_NULL && str2 != S21_NULL) {
    const char *str1_ptr = str1;
    int found = 0;

    while (*str1_ptr && !found) {
      const char *str2_ptr = str2;
      while (*str2_ptr) {
        if (*str1_ptr == *str2_ptr) {
          found = 1;
          break;
        }
        str2_ptr++;
      }
      if (!found) {
        str1_ptr++;
        result++;
      }
    }
  }
  return result;
}

char *s21_strerror(int errnum) {
  char *result = S21_NULL;
  static char unkn_err[128] = {'\0'};
  if (errnum >= 0 && errnum < ERROR_COUNT) {
    const char *errors[] = ERRORS;
    result = (char *)errors[errnum];
  } else {
#if defined(__linux__)
    s21_sprintf(unkn_err, "Unknown error %d", errnum);
#elif defined(__APPLE__)
    s21_sprintf(unkn_err, "Unknown error: %d", errnum);
#endif
    result = unkn_err;
  }
  return result;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t result = 0;
  if (str != S21_NULL) {
    const char *str_ptr = str;
    while (*str_ptr) {
      result++;
      str_ptr++;
    }
  }
  return result;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = S21_NULL;
  if (str1 != S21_NULL && str2 != S21_NULL) {
    const char *str1_ptr = str1;
    int found = 0;

    while (*str1_ptr && !found) {
      const char *str2_ptr = str2;
      while (*str2_ptr) {
        if (*str1_ptr == *str2_ptr) {
          result = (char *)str1_ptr;
          found = 1;
          break;
        }
        str2_ptr++;
      }
      if (!found) {
        str1_ptr++;
      }
    }
  }
  return result;
}

char *s21_strrchr(const char *str, int c) {
  char *result = S21_NULL;
  if (str != S21_NULL) {
    const char *pointer = str;
    while (*pointer) {
      if (*pointer == (char)c) {
        result = (char *)pointer;
      }
      pointer++;
    }
    if ((char)c == '\0') {
      result = (char *)pointer;
    }
  }
  return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = S21_NULL;
  if (haystack != S21_NULL && needle != S21_NULL) {
    if (!*needle) {
      result = (char *)haystack;
    } else {
      while (*haystack) {
        const char *h = haystack;
        const char *n = needle;
        while (*h && *n && *h == *n) {
          h++;
          n++;
        }
        if (!*n) {
          result = (char *)haystack;
          break;
        }
        haystack++;
      }
    }
  }
  return result;
}

char *s21_strtok(char *str, const char *delim) {
  static char *current;
  char *result = S21_NULL;

  if (delim != S21_NULL) {
    if (str != S21_NULL) {
      current = str;
    }
    if (current != S21_NULL) {
      while (*current && s21_strchr(delim, *current)) {
        current++;
      }
      if (*current != '\0') {
        result = current;
        while (*current && !s21_strchr(delim, *current)) {
          current++;
        }
        if (*current) {
          *current = '\0';
          current++;
        }
      }
    }
  }
  return result;
}