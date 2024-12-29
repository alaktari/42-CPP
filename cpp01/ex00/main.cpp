#include "Zombie.hpp"

int main()
{
	Zombie *heapzombie;
	std::cout << std::endl;

	heapzombie = newzombie("HeapZombie");
	if (heapzombie)
		heapzombie->announce();

	randomChump("StackZombie");

	delete heapzombie;
	std::cout << "\nEnd of the progaram. " << std::endl;
}