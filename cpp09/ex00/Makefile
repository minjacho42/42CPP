.DEFAULT_GOAL := all
SRCS = main.cpp BitcoinExchange.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
CPP = c++ -Wall -Wextra -Werror -std=c++98 -MMD -MP
NAME = btc
-include $(DEPS)

all :
	@echo "btc : make $(NAME)"
	@make $(NAME)

$(NAME) : $(OBJS)
	@$(CPP) -o $(NAME) $(OBJS)

%.o : %.cpp
	@$(CPP) -c $<

clean :
	@echo "btc : make clean"
	@rm -f $(OBJS) $(DEPS)

fclean :
	@echo "btc : make fclean"
	@rm -f $(OBJS) $(NAME) $(DEPS)

re : fclean
	@ echo "btc : make re"
	@ make all

.PHONY: all clean fclean re
