# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 14:00:51 by jbarbate          #+#    #+#              #
#    Updated: 2023/03/14 09:39:53 by jbarbate         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc
SRCS = srcs/main.c \
	   srcs/parsing.c \
	   srcs/tools.c \
	   srcs/philo.c \
	   srcs/exec.c \
	   srcs/time.c \
	   srcs/print.c \
	   srcs/free.c
OBJS = ${SRCS:.c=.o}
NAME = philo
CFLAGS = -Wall -Wextra -Werror

.c.o:
	@${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@echo "<| Compiling project |>"
	@echo "-----------------------"
	@${GCC} ${CFLAGS} -o ${NAME} ${LIBFT} ${OBJS}
	@echo "-----------------------"
	@echo "<| Compiling success |>"

all: ${OBJS} ${NAME}

clean:
	@rm -f ${OBJS}
	@echo Everything is clean

fclean: clean
	@rm -f ${NAME}

re: fclean all
