# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 20:42:04 by sumsong           #+#    #+#              #
#    Updated: 2022/09/09 11:50:16 by sumsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g3 -fsanitize=thread
RM				=	rm -rf

SRC_DIR			=	./srcs/
SRC				=	main.c arg_invalid_check.c struct_init.c philo_utils.c \
					philo_routine.c philo_print.c philo_monitoring.c

SRCS			=	$(addprefix $(SRC_DIR), $(SRC))
OBJS			=	$(SRCS:.c=.o)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(BONUS)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $?

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

PHONY: all clean fclean re