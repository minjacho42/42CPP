.DEFAULT_GOAL := all
SRCS = main.cpp RPN.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
CPP = c++ -Wall -Wextra -Werror -std=c++98 -MMD -MP
NAME = RPN
-include $(DEPS)

all :
	@echo "RPN : make $(NAME)"
	@make $(NAME)

$(NAME) : $(OBJS)
	@$(CPP) -o $(NAME) $(OBJS)

%.o : %.cpp
	@$(CPP) -c $<

clean :
	@echo "RPN : make clean"
	@rm -f $(OBJS) $(DEPS)

fclean :
	@echo "RPN : make fclean"
	@rm -f $(OBJS) $(NAME) $(DEPS)

re : fclean
	@ echo "RPN : make re"
	@ make all

.PHONY: all clean fclean re
