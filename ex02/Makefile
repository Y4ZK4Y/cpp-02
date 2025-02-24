NAME := fixed2

SRC := Fixed.cpp main.cpp
OBJ := $(SRC:.cpp=.o)

CC := c++
CFLAGS := -Wall -Wextra -Werror

RM = /bin/rm -rf

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
