.DEFAULT_GOAL := all
SRCS = main.cpp PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
CPP = c++ -Wall -Wextra -Werror -std=c++98 -MMD -MP -fsanitize=address -g
NAME = PmergeMe
-include $(DEPS)

all :
	@echo "PmergeMe : make $(NAME)"
	@make $(NAME)

$(NAME) : $(OBJS)
	@$(CPP) -o $(NAME) $(OBJS)

%.o : %.cpp
	@$(CPP) -c $<

clean :
	@echo "PmergeMe : make clean"
	@rm -f $(OBJS) $(DEPS)

fclean :
	@echo "PmergeMe : make fclean"
	@rm -f $(OBJS) $(NAME) $(DEPS)

re : fclean
	@ echo "PmergeMe : make re"
	@ make all

.PHONY: all clean fclean re
