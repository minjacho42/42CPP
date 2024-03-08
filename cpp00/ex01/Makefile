.DEFAULT_GOAL := all
SRCS = PhoneBook.cpp Contact.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
CPP = c++ -Wall -Wextra -Werror -std=c++98 -MMD -MP
NAME = PhoneBook
-include $(DEPS)

all :
	@echo "PhoneBook : make $(NAME)"
	@make $(NAME)

$(NAME) : $(OBJS)
	@$(CPP) -o $(NAME) $(OBJS)

%.o : %.cpp
	@$(CPP) -c $<

clean :
	@echo "PhoneBook : make clean"
	@rm -f $(OBJS) $(DEPS)

fclean :
	@echo "PhoneBook : make fclean"
	@rm -f $(OBJS) $(NAME) $(DEPS)

re : fclean
	@ echo "PhoneBook : make re"
	@ make all

.PHONY: all clean fclean re
