#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <string>
#include <iostream>

class Zombie
{
	public:
		Zombie(std::string, int);
		~Zombie();
		void advert(void);
	private:
		std::string name;
		std::string type;
		int color;
};
#endif