#include "Character.hpp"

Character::Character(std::string const name)
{
	// std::cout << "Character constructor called\n";
	_name = name;
	for (int i = 0; i < 4; i++)
	{
		_items[i] = NULL;
	}
}

Character::Character(Character const &c)
{
	// std::cout << "Character copy constructor called\n";
	for (int i = 0; i < 4; i++)
	{
		_items[i] = NULL;
	}
	*this = c;
}

Character &Character::operator=(Character const &c)
{
	_name = c._name;
	for (int i = 0; i < 4; i++)
	{
		delete _items[i];
		_items[i] = NULL;
		if (c._items[i])
		{
			_items[i] = c._items[i]->clone();
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		delete _items[i];
	}
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria *m)
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

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3 && _items[idx])
	{
		_items[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx <= 3 && _items[idx])
	{
		_items[idx]->use(target);
	}
}
