SRCFILES = $(wildcard *.cpp)
HEADERS  = $(wildcard *.hpp)
OBJFILES = $(SRCFILES:.cpp=.o)
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME	 = ex02
RM 		 = rm -f
CXX		 = c++

all: $(NAME)

$(NAME) : $(OBJFILES)
	$(CXX) $(CXXFLAGS) $(OBJFILES) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean :
	$(RM) $(OBJFILES)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJFILES)
