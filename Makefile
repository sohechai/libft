# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 14:07:19 by sohechai          #+#    #+#              #
#    Updated: 2021/02/02 11:13:12 by sofiahechai      ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


NAME			=		libft.a

INCLUDE			=		includes

HEADERS			=		./includes/libft.h

CC				=		gcc

RM				=		rm -rf

CFLAGS 			= 		-Wall -Wextra -Werror

SRC				=		ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
						ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c \
						ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
						ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c \
						ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
						ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
						ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
						ft_strcmp.c ft_strcat.c \

FT_PRINTF		=		ft_printf.c\
						/libft/ft_putchar.c\
						/libft/ft_putstr.c\
						/libft/ft_putnbr.c\
						/libft/ft_strlen.c\
						/libft/ft_strjoin.c\
						/libft/ft_itoabase.c\
						/libft/ft_strncmp.c\
						/libft/ft_strlen_int.c\
						/libft/ft_putlenstr.c\
						/libft/ft_strdup.c\
						/libft/ft_atoi.c\
						/srcs/ft_isflag.c\
						/srcs/ft_number.c\
						/srcs/ft_dot.c\
						/srcs/ft_stock_arg.c\
						/srcs/ft_star.c\
						/srcs/ft_zero.c\
						/srcs/ft_writedot.c\
						/srcs/ft_writedotnext.c\
						/srcs/ft_putstar.c\
						/srcs/ft_putstarnext.c\
						/srcs/ft_putfielddot.c\
						/srcs/ft_putfielddotnext.c\
						/srcs/ft_putfielddotpos.c\
						/srcs/ft_putzerodot.c\
						/srcs/ft_putzerodotnext.c\
						/srcs/ft_putzero.c\
						/srcs/ft_putzeronext.c\
						/srcs/ft_simpleflag.c\
						/srcs/ft_simpleflagnext.c\
						/srcs/ft_putspaces.c\
						/srcs/ft_spaceneg.c\
						/srcs/ft_difminus.c

SRCS			=		$(addprefix srcs/, $(SRC)) $(addprefix srcs/ft_printf/, $(FT_PRINTF))

OBJS			= 		$(SRCS:.c=.o)

all				: 		$(NAME)

$(NAME) : $(OBJS) $(HEADER)
				@ar rcs ${NAME} ${OBJS}

%.o: %.c $(HEADERS)
		@${CC} ${CFLAGS} -c $< -o $@

clean		:
		@${RM} -f $(OBJS)


fclean		:		clean
		@${RM} -f $(NAME)

re			:		fclean all

.PHONY: 	re fclean clean all
