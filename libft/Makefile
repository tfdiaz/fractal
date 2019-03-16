# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/09 11:22:32 by tdiaz             #+#    #+#              #
#    Updated: 2018/07/17 20:26:28 by tdiaz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @gcc

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SRC = ischeck.c vects.c maps.c memsetdel.c memcpmv.c striteri.c lists.c puts.c \
	putsfd.c strfind.c strcmp.c strcatcpy.c strbirth.c strmerge.c strchange.c \
	ft_atoi.c ft_itoa.c ft_strsplit.c get_next_line.c \
	printf/itoa_base.c \
	printf/unicode.c \
	printf/ft_printf.c \
	printf/wchar_funt.c \
	printf/flags.c \
	printf/concheck.c \
	printf/prt_cws.c \
	printf/octhex.c \
	printf/clouds.c \
	printf/iu_prt.c \

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

.PHONY: clean fclean all re

all: $(NAME)

clean: 
		@rm -f *.o
		@cd printf/ && rm -f *.o

fclean: clean
		@rm -rf $(NAME)

re: fclean all
