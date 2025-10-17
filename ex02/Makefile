# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 09:20:27 by kbarru            #+#    #+#              #
#    Updated: 2025/10/16 10:00:51 by kbarru           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp Fixed.cpp
INC = Fixed.hpp
CC = c++
NAME = fixed_02
CFLAGS = -Werror -Wextra -Wall -std=c++98 -g

OBJ = $(SRC:%.cpp=%.o)

.PHONY : all
all : $(NAME)

.PHONY : re
re : fclean
	$(MAKE) all

.PHONY : clean
clean : 
	rm -rf $(OBJ)

.PHONY : fclean
fclean : clean
	rm -rf $(NAME)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp $(INC)
	$(CC) $(CFLAGS) -c $< -o $@
