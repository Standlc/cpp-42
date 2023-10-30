#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *_items[4];

public:
	MateriaSource();
	MateriaSource(MateriaSource const &m);
	~MateriaSource();
	MateriaSource &operator=(MateriaSource const &m);

	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);
};

#endif