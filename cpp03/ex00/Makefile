.DEFAULT_GOAL := all
SRCS = ClapTrap.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
CPP = c++ -Wall -Wextra -Werror -std=c++98 -MMD -MP
NAME = cpp03_ex00
-include $(DEPS)

all :
	@echo "cpp03_ex00 : make $(NAME)"
	@make $(NAME)

$(NAME) : $(OBJS)
	@$(CPP) -o $(NAME) $(OBJS)

%.o : %.cpp
	@$(CPP) -c $<

clean :
	@echo "cpp03_ex00 : make clean"
	@rm -f $(OBJS) $(DEPS)

fclean :
	@echo "cpp03_ex00 : make fclean"
	@rm -f $(OBJS) $(NAME) $(DEPS)

re : fclean
	@ echo "cpp03_ex00 : make re"
	@ make all

.PHONY: all clean fclean re
