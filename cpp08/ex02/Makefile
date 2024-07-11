.DEFAULT_GOAL := all
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
CPP = c++ -Wall -Wextra -Werror -std=c++98 -MMD -MP
NAME = cpp08_02
-include $(DEPS)

all :
	@echo "cpp08_02 : make $(NAME)"
	@make $(NAME)

$(NAME) : $(OBJS)
	@$(CPP) -o $(NAME) $(OBJS)

%.o : %.cpp
	@$(CPP) -c $<

clean :
	@echo "cpp08_02 : make clean"
	@rm -f $(OBJS) $(DEPS)

fclean :
	@echo "cpp08_02 : make fclean"
	@rm -f $(OBJS) $(NAME) $(DEPS)

re : fclean
	@ echo "cpp08_02 : make re"
	@ make all

.PHONY: all clean fclean re
