NAME = graphs

CC = g++

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

HDR = main.hpp

SRCS = main.cpp dijkstra.cpp

OBJS = $(SRCS:.cpp=.o)

%.o:	%.cpp $(HDR)
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
