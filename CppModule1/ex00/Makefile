SRCFILES = $(wildcard *.cpp)
OBJFILES = $(SRCFILES:.cpp=.o)
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CC    	 = g++
NAME     = Zombie

all: $(NAME)

%.o: %.cpp
	$(CC) -c $(CPPFLAGS) $< -o $@

$(NAME): $(OBJFILES)
	$(CC) $(CPPFLAGS) $(OBJFILES) -o $(NAME)

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
.SECONDARY: $(OBJFILES)
