CC = c++ 
SRC = megaphone.cpp
CFLAGS = -Wall -Wextra -Werror
NAME = megaphone

all: $(NAME)

$(NAME): $(SRC) 
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@echo "No object files"
fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean