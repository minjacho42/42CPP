.DEFAULT_GOAL := all
SRCS = ClapTrap.cpp main.cpp FragTrap.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
CPP = c++ -Wall -Wextra -Werror -std=c++98 -MMD -MP
NAME = cpp03_ex02
-include $(DEPS)

all :
	@echo "cpp03_ex02 : make $(NAME)"
	@make $(NAME)

$(NAME) : $(OBJS)
	@$(CPP) -o $(NAME) $(OBJS)

%.o : %.cpp
	@$(CPP) -c $<

clean :
	@echo "cpp03_ex02 : make clean"
	@rm -f $(OBJS) $(DEPS)

fclean :
	@echo "cpp03_ex02 : make fclean"
	@rm -f $(OBJS) $(NAME) $(DEPS)

re : fclean
	@ echo "cpp03_ex02 : make re"
	@ make all

.PHONY: all clean fclean re
