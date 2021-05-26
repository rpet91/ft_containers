# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:      :+:    :+:    #
#                                                      +:+                     #
#    By: rpet <marvin@codam.nl>                       +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/30 13:04:14 by rpet          #+#    #+#                  #
#    Updated: 2021/05/26 13:12:19 by rpet          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic
#DEBUG = -fsanitize=address -g3
CC = clang++
INC = list.hpp vector.hpp map.hpp stack.hpp queue.hpp ListNode.hpp

ifeq ($(DEBUG),1)
	FLAGS += -fsanitize=address -g3
endif

.PHONY: all clean fclean re debug

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o:%.cpp $(INC)
	$(CC) $(FLAGS) -I. -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

debug:
	rm -f *.o
	@make DEBUG=1
