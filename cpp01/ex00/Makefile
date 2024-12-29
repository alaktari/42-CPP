NAME = zombie
SRC = main.cpp randomChump.cpp newZombie.cpp Zombie.cpp
CXX = c++
CXXFLAGC = -Wall -Wextra -Werror -std=c++98
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGC) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJ)