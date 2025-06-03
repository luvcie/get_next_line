CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

ifdef BUFFER_SIZE
    CFLAGS += -D BUFFER_SIZE=$(BUFFER_SIZE)
endif

NAME = gnl_bonus_tester

SRCS_BONUS = get_next_line_bonus.c \
             get_next_line_utils_bonus.c \
             main_bonus_test.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

HEADER_BONUS = get_next_line_bonus.h

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME)

bonus: $(NAME)

%.o: %.c $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
