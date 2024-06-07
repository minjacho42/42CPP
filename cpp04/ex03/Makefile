.DEFAULT_GOAL := all
SRCS = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
CPP = c++ -Wall -Wextra -Werror -std=c++98 -MMD -MP
NAME = cpp04_ex03
-include $(DEPS)

all :
	@echo "cpp04_ex03 : make $(NAME)"
	@make $(NAME)

$(NAME) : $(OBJS)
	@$(CPP) -o $(NAME) $(OBJS)

%.o : %.cpp
	@$(CPP) -c $<

clean :
	@echo "cpp04_ex03 : make clean"
	@rm -f $(OBJS) $(DEPS)

fclean :
	@echo "cpp04_ex03 : make fclean"
	@rm -f $(OBJS) $(NAME) $(DEPS)

re : fclean
	@ echo "cpp04_ex03 : make re"
	@ make all

.PHONY: all clean fclean re
