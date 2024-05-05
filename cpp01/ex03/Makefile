.DEFAULT_GOAL := all
SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
CPP = c++ -Wall -Wextra -Werror -std=c++98 -MMD -MP
NAME = cpp01_ex03
-include $(DEPS)

all :
	@echo "cpp01_ex03 : make $(NAME)"
	@make $(NAME)

$(NAME) : $(OBJS)
	@$(CPP) -o $(NAME) $(OBJS)

%.o : %.cpp
	@$(CPP) -c $<

clean :
	@echo "cpp01_ex03 : make clean"
	@rm -f $(OBJS) $(DEPS)

fclean :
	@echo "cpp01_ex03 : make fclean"
	@rm -f $(OBJS) $(NAME) $(DEPS)

re : fclean
	@ echo "cpp01_ex03 : make re"
	@ make all

.PHONY: all clean fclean re
