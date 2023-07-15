# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 08:53:44 by ogregoir          #+#    #+#              #
#    Updated: 2023/06/23 13:39:27 by ogregoir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	src/map.c \
			src/mouvements.c \
			src/mouvement2.c \
			src/main.c \
			src/path.c \
			src/moove_monsters.c \
			src/directions_monstres.c \
			src/parsing.c \
			src/good_way.c \
			src/conditions_annexe.c \
			utils/initialisation.c \
			utils/ft_printf.c \
			
OBJS	=	$(SRCS:.c=.o)

NAME	=	so_long

RM		=	rm -f

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -g

LIBFT	=	utils/libft/libft.a

MACLINKS = -lmlx -framework OpenGL -framework AppKit 

#-------------------------------------------#

all	:	$(NAME)

$(NAME)	: $(LIBFT) $(OBJS)
	$(CC) -g $(CFLAGS) $(LIBFT) $(OBJS) $(MACLINKS) -o $(NAME)

clean	:
	$(RM)   $(OBJS)
	make 	clean -C utils/libft

fclean : clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)
	make fclean -C utils/libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	make -C utils/libft

re	: fclean all
