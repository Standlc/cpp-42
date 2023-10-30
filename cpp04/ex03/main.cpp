#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource *src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("nothing");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	//

	Character me_2("me_2");
	me_2.use(0, *bob);
	me_2.equip(new Ice());
	me_2.equip(new Ice());
	me_2.equip(new Cure());

	Character me_2_copy(me_2);
	me_2_copy.use(0, me_2);
	me_2_copy.use(2, me_2);

	delete bob;
	delete me;
	delete src;
	return 0;
}