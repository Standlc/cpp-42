#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		_items[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const &m)
{
	for (int i = 0; i < 4; i++)
	{
		_items[i] = NULL;
	}
	*this = m;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		delete _items[i];
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &m)
{
	for (int i = 0; i < 4; i++)
	{
		delete _items[i];
		_items[i] = NULL;
		if (m._items[i])
		{
			_items[i] = m._items[i]->clone();
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return;

	for (int i = 0; i < 4; i++)
	{
		if (_items[i] == NULL)
		{
			_items[i] = m;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_items[i] && _items[i]->getType() == type)
		{
			return (_items[i]->clone());
		}
	}
	return (0);
}
