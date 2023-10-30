#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called\n";
}

Brain::Brain(Brain const &brain)
{
	*this = brain;
	std::cout << "Brain copy constructor called\n";
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}

Brain &Brain::operator=(Brain const &brain)
{
	for (int i = 0; i < 100; i++)
	{
		_ideas[i] = brain._ideas[i];
	}
	return *this;
}

std::string &Brain::getIdea(int index)
{
	return _ideas[index];
}
