#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(Cure const &a);
	~Cure();
	Cure &operator=(Cure const &a);

	Cure *clone() const;
	void use(ICharacter &target);
};

#endif