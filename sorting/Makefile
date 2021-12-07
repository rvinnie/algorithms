NAME = sorting

CC = clang++

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

HDR = main.hpp

SRCS = main.cpp bubbleSort.cpp insertionSort.cpp \
		mergeSort.cpp quickSort.cpp selectionSort.cpp

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
