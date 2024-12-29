#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <new>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie(std::string zombie_name);
		~Zombie(void);
		void announce(void);
};

Zombie	*newzombie(std::string name);
void	randomChump(std::string name);


#endif