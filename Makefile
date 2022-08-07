# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsabir <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 13:27:39 by hsabir            #+#    #+#              #
#    Updated: 2022/01/12 18:58:39 by lgyger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -o
#CFLAGS += -g3 -fsanitize=address


NAME = philo
BONUS = philo_semaphore

FILES = ./philo_mandatory/main.c\
	./philo_mandatory/loop.c\
	./philo_mandatory/print.c\
	./philo_mandatory/utils.c

FILES_BONUS = ./philo_bonus/main.c\
	      ./philo_bonus/message.c\
	      ./philo_bonus/utils.c

all : $(NAME)

$(NAME): 
	$(CC) $(CFLAGS) $(NAME) $(FILES)

bonus: $(BONUS)

$(BONUS):
	$(CC) $(CFLAGS) $(BONUS) $(FILES_BONUS)
fclean:
	rm -f $(NAME)
fclean_bonus:
	rm -f $(BONUS)

re: fclean fclean_bonus all
	$(MAKE) re -sC $(LIBFT_DIR)

.PHONY: fclean_bonus bonus fclean all re
