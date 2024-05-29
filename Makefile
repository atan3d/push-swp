# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 17:24:32 by nicolive          #+#    #+#              #
#    Updated: 2024/05/28 17:19:16 by najeuneh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -c -Wall -Werror -Wextra 

LIBFT.A = ./libft/libft.a

LIBFT = ./libft

NAME = push_swap


MY_OBJECTS = $(MY_SOURCES:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME) : $(MY_OBJECTS)
	$(MAKE) -C $(LIBFT)
	cc $(LIBFT) -o $(NAME) $(MY_OBJECTS)

$(MY_OBJECTS):
	$(CC) $(CFLAGS) ${@:.o=.c} -o $@

clean:
	$(MAKE) clean -C $(LIBFT)
	${RM} ${MY_OBJECTS}


fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	${RM} ${NAME}

re: fclean all

.PHONY: fclean re clean all