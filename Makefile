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

test:
	gcc -I./src $(FLAGS) $(SRCS) $(TESTS) -o $(TEST_NAME)

clean:

fclean: clean
	rm -f $(NAME) $(TEST_NAME)
