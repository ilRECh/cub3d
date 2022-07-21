SRCS	= get_next_line.c get_next_line_utils.c 

OBJS	= $(SRCS:.c=.o)

HDRS	= get_next_line.h

NAME	= gnl.a

RM	= rm -rf
GCC	= gcc
AR	= ar -crs
FLAGS	= -Wall -Wextra -Werror -c

%.o : %.c $(HDRS)
	$(GCC) $(FLAGS) $(INCLUDES) $< -o $@

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

re:	fclean all

clean:
	$(RM) $(OBJS)

fclean: 	clean
	$(RM) $(NAME)
	
.PHONY:	
	all clean fclean re 