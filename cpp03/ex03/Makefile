NAME		= DiamondTrap
SRC			= DiamondTrap.cpp FragTrap.cpp ClapTrap.cpp main.cpp ScavTrap.cpp
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