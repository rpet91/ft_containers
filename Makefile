# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:      :+:    :+:    #
#                                                      +:+                     #
#    By: rpet <marvin@codam.nl>                       +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/30 13:04:14 by rpet          #+#    #+#                  #
#    Updated: 2021/06/07 13:07:11 by rpet          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic
#DEBUG = -fsanitize=address -g3
CC = clang++
DIRCONTAINERS = ./containers/
DIRUTILS = ./utils/
_CONTAINERS = list.hpp \
			  vector.hpp \
			  map.hpp \
			  stack.hpp \
			  queue.hpp
_UTILS = ListNode.hpp \
		 ListIterator.hpp \
		 RandomAccessIterator.hpp \
		 BidirectionalIterator.hpp \
		 Iterator.hpp \
		 Category.hpp
CONTAINERS = $(addprefix $(DIRCONTAINERS), $(_CONTAINERS))
UTILS = $(addprefix $(DIRUTILS), $(_UTILS))
INC = $(CONTAINERS) $(UTILS)

ifeq ($(DEBUG),1)
	FLAGS += -fsanitize=address -g3
endif

.PHONY: all clean fclean re debug

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o:%.cpp $(INC)
	$(CC) $(FLAGS) -I$(DIRCONTAINERS) -I$(DIRUTILS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

debug:
	rm -f *.o
	@make DEBUG=1
