# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 17:24:32 by nicolive          #+#    #+#              #
#    Updated: 2024/06/05 12:59:18 by najeuneh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
ORANGE=\033[38;2;255;165;0m
NC=\033[0m 

CC = cc

NAME = push_swap

MY_SOURCES =  algo_utils.c algo_utils3.c check_arg.c parsing.c rotate.c algo_utils2.c algoritme.c ft_reverse_rotate.c \
				push.c swap.c \

CFLAGS = -c -Wall -Werror -Wextra

PRINTF.A = ./ft_printf/libftprintf.a

PRINTF = ./ft_printf

LIBFT.A = ./libft/libft.a

LIBFT = ./libft

NAME = push_swap

INCLUDE = ./inc/libft.h

INCLUDE2 = ./inc/push_swap.h

INCLUDE3 = ./inc/ft_printf.h

MY_OBJECTS = $(MY_SOURCES:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME) : $(MY_OBJECTS)
	@$(MAKE) -C $(PRINTF)
	@$(MAKE) -C $(LIBFT)
	@printf "                                               \r"
	@echo "                       								 "        			
	@echo "██╗   ██╗███████╗██╗  ██╗        ███████╗██╗    ██╗ █████╗ ██████╗ "
	@echo "██╔══██╗██║   ██║██╔════╝██║  ██║        ██╔════╝██║    ██║██╔══██╗██╔══██╗"
	@echo "██████╔╝██║   ██║███████╗███████║        ███████╗██║ █╗ ██║███████║██████╔╝"
	@echo "██╔═══╝ ██║   ██║╚════██║██╔══██║        ╚════██║██║███╗██║██╔══██║██╔═══╝ "
	@echo "██║     ╚██████╔╝███████║██║  ██║███████╗███████║╚███╔███╔╝██║  ██║██║     "
	@echo "╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     "
	@echo "                       								 "     
	@cc $(LIBFT.A) $(PRINTF.A) -o $(NAME) $(MY_OBJECTS)

clean:
	@$(MAKE) clean -C $(PRINTF)
	@$(MAKE) clean -C $(LIBFT)
	@${RM} ${MY_OBJECTS}


fclean: clean
	@$(MAKE) fclean -C $(PRINTF)
	@$(MAKE) fclean -C $(LIBFT)
	@${RM} ${NAME}

re: fclean all

.PHONY: fclean re clean all