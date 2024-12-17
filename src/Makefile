CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
SANITIZE=-fsanitize=address -g
TST_LIBS = -lcheck
ifeq ($(shell uname), Linux)
	TST_LIBS += -lm -lpthread -lrt -lsubunit
endif
LIB_NAME = s21_string

SRCS=$(wildcard s21_*.c)

OBJS=$(SRCS:.c=.o)

all: clean test

clean:
	rm -rf *.o test *.a *.gcno *.gcda *.gcov *.html *.css Main SANITIZE

clang-format:
	clang-format -i *.c *.h tests/*.c tests/*.h

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIB_NAME).a: $(OBJS)
	ar rc $(LIB_NAME).a $^
	ranlib $(LIB_NAME).a
	rm -rf *.o

test: clean $(LIB_NAME).a
	$(CC) $(FLAGS) s21_test.c tests/*.c $(LIB_NAME).a $(TST_LIBS) -o test

sanitize: clean $(LIB_NAME).a
	$(CC) $(FLAGS) $(SANITIZE) s21_test.c tests/*.c $(LIB_NAME).a $(TST_LIBS) -o SANITIZE

main: $(LIB_NAME).a
	$(CC) $(FLAGS) main.c -L. $(LIB_NAME).a $(TST_LIBS) -o Main

add_coverage_flag:
	$(eval FLAGS += --coverage)

gcov_report: add_coverage_flag test 
	./test
	rm -rf check*.gcda check*.gcno
	gcov -b -l -p -c s21_*.gcno
	gcovr -o gcov_report.html --html --html-details --exclude 's21_test.*|tests/.'
