.DEFAULT_GOAL := all
SRCS = main.cpp Base.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
CPP = c++ -std=c++98 -MMD -MP -Wall -Wextra -Werror
NAME = cpp06_ex02
-include $(DEPS)

all :
	@echo "cpp06_ex02 : make $(NAME)"
	@make $(NAME)

$(NAME) : $(OBJS)
	@$(CPP) -o $(NAME) $(OBJS)

%.o : %.cpp
	@$(CPP) -c $<

clean :
	@echo "cpp06_ex02 : make clean"
	@rm -f $(OBJS) $(DEPS)

fclean :
	@echo "cpp06_ex02 : make fclean"
	@rm -f $(OBJS) $(NAME) $(DEPS)

re : fclean
	@ echo "cpp06_ex02 : make re"
	@ make all

.PHONY: all clean fclean re
