.DEFAULT_GOAL := all
SRCS = LiteralCompound.cpp ScalarConverter.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
CPP = c++ -std=c++98 -MMD -MP -Wall -Wextra -Werror
NAME = convert
-include $(DEPS)

all :
	@echo "convert : make $(NAME)"
	@make $(NAME)

$(NAME) : $(OBJS)
	@$(CPP) -o $(NAME) $(OBJS)

%.o : %.cpp
	@$(CPP) -c $<

clean :
	@echo "convert : make clean"
	@rm -f $(OBJS) $(DEPS)

fclean :
	@echo "convert : make fclean"
	@rm -f $(OBJS) $(NAME) $(DEPS)

re : fclean
	@ echo "convert : make re"
	@ make all

.PHONY: all clean fclean re
