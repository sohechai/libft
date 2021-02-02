# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/21 14:11:14 by sohechai          #+#    #+#              #
#    Updated: 2021/02/02 00:03:07 by sofiahechai      ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRC			=	ft_printf.c\
				./libft/ft_putchar.c\
				./libft/ft_putstr.c\
				./libft/ft_putnbr.c\
				./libft/ft_strlen.c\
				./libft/ft_strjoin.c\
				./libft/ft_itoabase.c\
				./libft/ft_strncmp.c\
				./libft/ft_strlen_int.c\
				./libft/ft_putlenstr.c\
				./libft/ft_strdup.c\
				./libft/ft_atoi.c\
				./srcs/ft_isflag.c\
				./srcs/ft_number.c\
				./srcs/ft_dot.c\
				./srcs/ft_stock_arg.c\
				./srcs/ft_star.c\
				./srcs/ft_zero.c\
				./srcs/ft_writedot.c\
				./srcs/ft_writedotnext.c\
				./srcs/ft_putstar.c\
				./srcs/ft_putstarnext.c\
				./srcs/ft_putfielddot.c\
				./srcs/ft_putfielddotnext.c\
				./srcs/ft_putfielddotpos.c\
				./srcs/ft_putzerodot.c\
				./srcs/ft_putzerodotnext.c\
				./srcs/ft_putzero.c\
				./srcs/ft_putzeronext.c\
				./srcs/ft_simpleflag.c\
				./srcs/ft_simpleflagnext.c\
				./srcs/ft_putspaces.c\
				./srcs/ft_spaceneg.c\
				./srcs/ft_difminus.c

OBJ			= ${SRC:.c=.o}

NAME		=	libftprintf.a

CC			= 	cc

CFLAGS		=	-Wall -Wextra -Werror -g3

RM			=	rm -rf

HEADER		=	ft_printf.h

all:			${NAME}

$(NAME) : $(OBJ) $(HEADER)
				@ar rcs ${NAME} ${OBJ}
				
				@echo "\033[95m \nCompiling ${NAME}, please be patient...\n"

%.o: %.c $(HEADER)
				@${CC} ${CFLAGS} -c $< -o $@

clean :	
				@${RM} -f *.o ./srcs/*.o ./libft/*.o
				@echo "\033[91mDeleting object files..."
			
fclean :        clean 
				rm -f ${NAME}
				@echo "\033[91mDeleting printf.a..."

re :            fclean all