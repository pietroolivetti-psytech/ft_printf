CC = cc
NAME = libftprintf.a

SRCS = ft_printf.c utils.c unsigned_utils.c
FLAGS = -Wall -Wextra -Werror -g -O0
#The line below is a definition that tells make what the OBJS variable holds.
OBJS = $(SRCS:.c=.o)
LIB = ar -rcs
RM = rm -f 

#Obj creation
%.o: %.c
	$(CC) $(FLAGS) -c $<
#linking creation
$(NAME): $(OBJS)
	$(LIB) $(NAME) $(OBJS)

all: $(NAME)
clean: 
	$(RM) $(OBJS)
fclean:
	$(RM) $(NAME) $(OBJS)
re: fclean all

.PHONY:	all clean fclean re