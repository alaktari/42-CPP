#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <new>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie(void);
		~Zombie(void);
		void	set_name(std::string zombie_name);
		void	announce(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif