.DEFAULT_GOAL := all
SRCS =
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
CPP = c++ -Wall -Wextra -Werror -std=c++98 -MMD -MP
NAME = bin_name
-include $(DEPS)

all :
	@echo "bin_name : make $(NAME)"
	@make $(NAME)

$(NAME) : $(OBJS)
	@$(CPP) -o $(NAME) $(OBJS)

%.o : %.c
	@$(CPP) -c $<

clean :
	@echo "bin_name : make clean"
	@rm -f $(OBJS) $(DEPS)

fclean :
	@echo "bin_name : make fclean"
	@rm -f $(OBJS) $(NAME) $(DEPS)

re : fclean
	@ echo "bin_name : make re"
	@ make all

.PHONY: all clean fclean re
