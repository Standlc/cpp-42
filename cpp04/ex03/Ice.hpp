#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(Ice const &a);
	~Ice();
	Ice &operator=(Ice const &a);

	Ice *clone() const;
	void use(ICharacter &target);
};

#endif