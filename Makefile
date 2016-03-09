# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpaincha <mpaincha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 12:19:31 by fsimmet           #+#    #+#              #
#    Updated: 2016/03/07 11:18:15 by mpaincha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_bzero.c \
ft_atoi.c \
ft_count_words.c \
ft_isalnum.c \
ft_itoa.c \
ft_itoabase_imax.c \
ft_itoabase_uimax.c \
ft_itoabase.c \
ft_intlen.c \
ft_isascii.c \
ft_isdigit.c \
ft_isalpha.c \
ft_islower.c \
ft_isupper.c \
ft_isprint.c \
ft_tolower.c \
ft_toupper.c \
ft_strcmp.c \
ft_strjoin.c \
ft_strjoinandfree.c \
ft_strdel.c \
ft_strnew.c \
ft_strclr.c \
ft_strsub.c \
ft_memset.c \
ft_memchr.c \
ft_memcpy.c \
ft_memcmp.c \
ft_memccpy.c \
ft_memdel.c \
ft_memmove.c \
ft_memalloc.c \
ft_putchar.c \
ft_putchar_fd.c \
ft_putnbr.c \
ft_putnbr_fd.c \
ft_putstr.c \
ft_putstr_fd.c \
ft_strcpy.c \
ft_strncpy.c \
ft_strdup.c \
ft_strchr.c \
ft_strrchr.c \
ft_strlen.c \
ft_lstnew.c \
ft_lstdbladd.c \
ft_lstdbldel.c \
ft_lstdblnew.c \
ft_strcat.c \
ft_strncat.c \
ft_strncmp.c \
ft_strequ.c \
checkingarg.c \
checkingmod.c \
checkingspecprec.c \
recovery.c \
cleaning.c \
display.c \
flags_minus.c \
flags_plus.c \
flags_space.c \
action_1.c \
action_2.c \
action_3.c \
action_4.c \
ft_printf.c \
wchar.c \
wchar_prec.c \
fill_mask.c \
ini.c \
mod_1.c \
mod_2.c \
prec.c \
width.c \
diez.c \
ft_strlower.c
SRCO = $(SRC:.c=.o)
HEADERS = .
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

re: fclean all

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(NAME): $(SRCO)
	ar rc $@ $^
	ranlib $@

clean:
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

.PHONY: re clean fclean all
