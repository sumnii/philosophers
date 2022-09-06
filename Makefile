NAME			=	philo

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf

SRC_DIR			=	./srcs/
SRC				=	main.c arg_invalid_check.c philo_init.c philo_utils.c \
					philo_routine.c

SRCS			=	$(addprefix $(SRC_DIR), $(SRC))
OBJS			=	$(SRCS:.c=.o)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all

bonus: $(BONUS)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $?

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

PHONY: all clean fclean re bonus