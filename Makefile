# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: sohechai <sohechai@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/17 14:07:19 by sohechai     #+#   ##    ##    #+#        #
#    Updated: 2019/10/31 16:19:54 by sohechai    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

SRC			=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
				ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c\
				ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c\
				ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c\
				ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c\
				ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\

OBJ			= ${SRC:.c=.o}

NAME		=	libft.a

CC			= 	cc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -rf

HEADER		=	libft.h

all:			${NAME}

$(NAME) : $(OBJ) $(HEADER)
				ar rcs ${NAME} ${OBJ}

%.o: %.c $(HEADER)
				${CC} ${CFLAGS} -c $< -o $@

clean :	
				${RM} -f *.o
			
fclean :        clean 
				rm -f ${NAME}
		

re :            fclean all
