# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:      :+:    :+:    #
#                                                      +:+                     #
#    By: rpet <marvin@codam.nl>                       +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/30 13:04:14 by rpet          #+#    #+#                  #
#    Updated: 2021/08/19 14:29:47 by rpet          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =			ft_containers
STD_NAME =		std_containers
FT_OFILE =		ft_containers.txt
STD_OFILE =		std_containers.txt
TIMES_FILE =	ft_times.txt std_times.txt
SRC =			main.cpp
FLAGS =			-Wall -Werror -Wextra -std=c++98 -pedantic
DEBUG =			-fsanitize=address -g3
CC =			clang++
DIRCONTAINERS =	./containers/
DIRUTILS =		./utils/
_CONTAINERS =	list vector map stack queue 
_UTILS =		ListNode MapNode \
		 		NodeIterator RandomAccessIterator BidirectionalIterator \
		 		Iterator ReverseIterator \
				TypeTraits Utils Pair
CONTAINERS =	$(addsuffix .hpp, $(addprefix $(DIRCONTAINERS), $(_CONTAINERS)))
UTILS =			$(addsuffix .hpp, $(addprefix $(DIRUTILS), $(_UTILS)))
INC =			$(CONTAINERS) $(UTILS)

ifeq ($(DEBUG),1)
	FLAGS += -fsanitize=address -g3
endif

.PHONY: all clean fclean re debug test

all: $(NAME) #$(STD_NAME)

$(NAME): $(SRC) $(INC)
	$(CC) $(FLAGS) $(SRC) -I$(DIRCONTAINERS) -I$(DIRUTILS) -o $(NAME)

$(STD_NAME): $(SRC) $(INC)
	$(CC) $(FLAGS) $(SRC) -I$(DIRCONTAINERS) -I$(DIRUTILS) -D USE_STD=1 -o $(STD_NAME)

clean:
	rm -f $(FT_OFILE) $(STD_OFILE)
	rm -rf $(NAME).dSYM $(STD_NAME).dSYM

fclean: clean
	rm -f $(NAME) $(STD_NAME) $(TIMES_FILE)

re: fclean all

debug:
	@make DEBUG=1

test:
	@make all
	./$(NAME) > $(FT_OFILE)
#	./$(STD_NAME) > $(STD_OFILE)
	diff $(FT_OFILE) $(STD_OFILE)
