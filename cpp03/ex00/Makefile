NAME		= ClapTrap
SRC			= ClapTrap.cpp main.cpp
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
OBJ			= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re: fclean all