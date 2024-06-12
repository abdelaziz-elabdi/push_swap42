# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-abdi <ael-abdi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 16:38:46 by ael-abdi          #+#    #+#              #
#    Updated: 2024/03/31 18:25:01 by ael-abdi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap
NAME2 = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
obj = mandatory/tools1.c mandatory/ft_split.c mandatory/main.c mandatory/tools.c mandatory/swap_mov.c mandatory/push_a_b.c mandatory/sort.c mandatory/find_max_min.c
bobj = bonus/tools1.c bonus/ft_split.c bonus/main.c bonus/tools.c bonus/swap_mov.c bonus/check_sort.c bonus/check_mouv.c bonus/get_next_line.c bonus/get_next_line_utils.c

OFILES = $(obj:.c=.o)
BFILES = $(bobj:.c=.o)
all: $(NAME1) 

bonus: $(NAME2)

$(NAME1): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o ${NAME1}
$(NAME2): $(BFILES)
	$(CC) $(CFLAGS) $(BFILES) -o ${NAME2}

mandatory/%.o: mandatory/%.c mandatory/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@
bonus/%.o: bonus/%.c bonus/checker.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OFILES) $(BFILES)

fclean: clean
	$(RM) $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re