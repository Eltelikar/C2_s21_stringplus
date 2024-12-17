CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

GCOV_FLAGS_LINUX = -fprofile-arcs -ftest-coverage
GCOV_FLAGS_MACOS = -fprofile-instr-generate -fcoverage-mapping

GCOVR = gcovr
COV_TOOL_LINUX = gcov
COV_TOOL_MACOS = llvm-cov

SRC = s21_string.c s21_sprintf.c
OBJ = $(SRC:.c=.o)

TEST_SRC = s21_test.c tests/s21_test_sprintf.c tests/s21_test_string.c
TEST_EXEC = s21_test

all: clean s21_string.a

s21_string.a: $(OBJ)
	$(AR) rcs $@ $^
	ranlib $@

%.o: %.c
ifeq ($(shell uname), Linux)
	$(CC) $(CFLAGS) $(GCOV_FLAGS_LINUX) -c $< -o $@
else
	$(CC) $(CFLAGS) $(GCOV_FLAGS_MACOS) -c $< -o $@
endif

test: clean s21_string.a
ifeq ($(shell uname), Linux)
	$(CC) $(CFLAGS) $(GCOV_FLAGS_LINUX) -o $(TEST_EXEC) $(TEST_SRC) s21_string.a -lcheck -lsubunit -lm -lpthread
else
	$(CC) $(CFLAGS) $(GCOV_FLAGS_MACOS) -o $(TEST_EXEC) $(TEST_SRC) s21_string.a -lcheck -lm -lpthread
endif
	./$(TEST_EXEC)

gcov_report: clean test
ifeq ($(shell uname), Linux)
	$(COV_TOOL_LINUX) -b -l -p -c $(SRC)
else
	$(COV_TOOL_MACOS) report $(TEST_EXEC) --instr-profile=$(TEST_EXEC).profraw
endif
	$(GCOVR) -r . --html --html-details -o gcov_report.html --exclude 's21_test*|tests/*'

clean:
	rm -f *.o *.a $(TEST_EXEC) *.gcno *.gcda *.gcov *.css *.html *.profraw
	rm -rf report
