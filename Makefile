NAME =		convert_base
TEST_NAME =	test.out

FLAGS = 	-Wall -Wextra -Werror

SRCDIR =	src
TESTDIR =	test

SRCS =		$(SRCDIR)/atoi_base.c \
			$(SRCDIR)/itoa_base.c \
			$(SRCDIR)/main.c

TESTS =		$(TESDIR)/atoi_base.c \
			$(TESDIR)/itoa_base.c

all: $(NAME)

$(NAME):
	gcc -I./src $(FLAGS) $(SRCS) -o $(NAME)

test: build_ctest
	gcc -I./src $(FLAGS) $(SRCS) $(TESTS) $(TESTDIR)/ctest.a -o $(TEST_NAME)

build_ctest:
	cd test/ctest && make && make clean

fclean_ctest:
	cd test/ctest && make fclean

clean:

fclean: clean fclean_ctest
	rm -f $(NAME) $(TEST_NAME)
