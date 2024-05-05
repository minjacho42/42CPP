.DEFAULT_GOAL := all
SRCS = main.cpp Harl.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
CPP = c++ -Wall -Wextra -Werror -std=c++98 -MMD -MP
NAME = cpp01_ex05
-include $(DEPS)

all :
	@echo "cpp01_ex05 : make $(NAME)"
	@make $(NAME)

$(NAME) : $(OBJS)
	@$(CPP) -o $(NAME) $(OBJS)

%.o : %.cpp
	@$(CPP) -c $<

clean :
	@echo "cpp01_ex05 : make clean"
	@rm -f $(OBJS) $(DEPS)

fclean :
	@echo "cpp01_ex05 : make fclean"
	@rm -f $(OBJS) $(NAME) $(DEPS)

re : fclean
	@ echo "cpp01_ex05 : make re"
	@ make all

.PHONY: all clean fclean re
