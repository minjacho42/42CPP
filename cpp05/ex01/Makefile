.DEFAULT_GOAL := all
SRCS = Bureaucrat.cpp main.cpp Form.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
CPP = c++ -Wall -Wextra -Werror -std=c++98 -MMD -MP
NAME = cpp05_ex01
-include $(DEPS)

all :
	@echo "cpp05_ex01 : make $(NAME)"
	@make $(NAME)

$(NAME) : $(OBJS)
	@$(CPP) -o $(NAME) $(OBJS)

%.o : %.cpp
	@$(CPP) -c $<

clean :
	@echo "cpp05_ex01 : make clean"
	@rm -f $(OBJS) $(DEPS)

fclean :
	@echo "cpp05_ex01 : make fclean"
	@rm -f $(OBJS) $(NAME) $(DEPS)

re : fclean
	@ echo "cpp05_ex01 : make re"
	@ make all

.PHONY: all clean fclean re
