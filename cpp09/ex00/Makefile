.DEFAULT_GOAL := all
SRCS = main.cpp BitcoinExchange.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
CPP = c++ -Wall -Wextra -Werror -std=c++98 -MMD -MP
NAME = cpp09_00
-include $(DEPS)

all :
	@echo "cpp09_00 : make $(NAME)"
	@make $(NAME)

$(NAME) : $(OBJS)
	@$(CPP) -o $(NAME) $(OBJS)

%.o : %.cpp
	@$(CPP) -c $<

clean :
	@echo "cpp09_00 : make clean"
	@rm -f $(OBJS) $(DEPS)

fclean :
	@echo "cpp09_00 : make fclean"
	@rm -f $(OBJS) $(NAME) $(DEPS)

re : fclean
	@ echo "cpp09_00 : make re"
	@ make all

.PHONY: all clean fclean re
