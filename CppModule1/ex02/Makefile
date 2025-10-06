CC       = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRCFILES = main.cpp
NAME     = program

all: $(NAME)

$(NAME): $(SRCFILES)
	$(CC) $(CPPFLAGS) $(SRCFILES) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re