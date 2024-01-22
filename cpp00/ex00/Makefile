.DEFAULT_GOAL := all
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
CPP = c++ -Wall -Wextra -Werror -std=c++98 -MMD -MP
NAME = megaphone
-include $(DEPS)

all :
	@echo "megaphone : make $(NAME)"
	@make $(NAME)

$(NAME) : $(OBJS)
	@$(CPP) -o $(NAME) $(OBJS)

%.o : %.cpp
	@$(CPP) -c $<

clean :
	@echo "megaphone : make clean"
	@rm -f $(OBJS) $(DEPS)

fclean :
	@echo "megaphone : make fclean"
	@rm -f $(OBJS) $(NAME) $(DEPS)

re : fclean
	@ echo "megaphone : make re"
	@ make all

.PHONY: all clean fclean re
