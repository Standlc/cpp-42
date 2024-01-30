#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource *src = new MateriaSource();

	std::cout << "IMateriaSource src: learning Ice and Cure\n";
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *john = new Character("john");

	std::cout << "creating materias and equiping john\n";
	AMateria *tmp;
	tmp = src->createMateria("ice");
	john->equip(tmp);
	tmp = src->createMateria("cure");
	john->equip(tmp);
	// will return NULL because materia doesn't exist
	tmp = src->createMateria("nothing");
	john->equip(tmp);

	std::cout << "\n";
	std::cout << "john is ready to use its materias on bob\n";
	ICharacter *bob = new Character("bob");
	john->use(0, *bob);
	john->use(1, *bob);

	//

	std::cout << "\n";
	std::cout << "creating daniel on the stack and equiping him\n";
	Character Daniel("Daniel");
	// won't use() because daniel doesn't have materias yet
	Daniel.use(0, *bob);
	AMateria *ice = new Ice();
	Daniel.equip(new Ice());
	Daniel.equip(ice);
	Daniel.equip(new Cure());

	std::cout << "\n";
	std::cout << "creating daniel's copy\n";
	Character Daniel_copy(Daniel);

	std::cout << "\n";
	std::cout << "daniel's copy is using its materias on Daniel!!\n";
	Daniel_copy.use(0, Daniel);
	Daniel_copy.use(2, Daniel);

	std::cout << "\n";
	std::cout << "unequiping daniel of his 3rd item (he won't be able to use it)\n";
	Daniel.unequip(1);
	Daniel.use(1, Daniel);
	delete ice;

	std::cout << "\n";
	delete bob;
	delete john;
	delete src;
	return 0;
}