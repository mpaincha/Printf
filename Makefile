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

H_DIR = includes/
C_DIR = srcs/
O_DIR = obj/
LIBFT = Libft/

FLAGS = -Wall -Wextra -Werror
LINKS = -I$(H_DIR) -I$(LIBFT)

C_FILES = $(shell ls -1 $(C_DIR) | grep "\.c")

O_FILES = $(addprefix $(O_DIR),$(C_FILES:.c=.o))

all:
	@make -C $(LIBFT)
	@make $(NAME)

$(NAME): $(O_FILES)
	$(eval FT_O = $(shell find $(LIBFT) -type f -print | grep "\.o"))
	@ar rcs $@ $(O_FILES) $(FT_O) && printf "\033[0;32m" || printf "\033[0;31m"
	@printf "%-24s\033[1;30m<<--\033[0;0m\n" "$@"

$(O_DIR)%.o: $(C_DIR)%.c
	@mkdir $(O_DIR) 2> /dev/null || echo "" > /dev/null
	@gcc $(FLAGS) $(LINKS) -o $@ -c $< \
	&& printf "\033[0;0m%-24s\033[1;30m-->>	\033[0;32m$@\033[0;0m\n" "$<" \
	|| (printf "\033[0;0m%-24s\033[1;30m-->>	\033[0;31m$@\033[0;0m\n" "$<" \
	&& exit 1)

clean:
	@rm $(O_FILES) 2> /dev/null || echo "" > /dev/null
	@rmdir -p $(O_DIR) 2> /dev/null || echo "" > /dev/null
	@make -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME) 2> /dev/null || echo "" > /dev/null
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
