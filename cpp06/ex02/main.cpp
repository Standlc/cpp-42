#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
	{
		std::cout << "Class A\n";
	}
	else if (dynamic_cast<B *>(p) != NULL)
	{
		std::cout << "Class B\n";
	}
	else if (dynamic_cast<C *>(p) != NULL)
	{
		std::cout << "Class C\n";
	}
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "Class A\n";
		return;
	}
	catch (const std::exception &e)
	{
	}

	try
	{
		dynamic_cast<B &>(p);
		std::cout << "Class B\n";
		return;
	}
	catch (const std::exception &e)
	{
	}

	try
	{
		dynamic_cast<C &>(p);
		std::cout << "Class C\n";
	}
	catch (const std::exception &e)
	{
	}
}

Base *generate(void)
{
	int randomNumber = rand() % 3;

	if (randomNumber == 0)
	{
		std::cout << "generating class A\n";
		return new A();
	}
	if (randomNumber == 1)
	{
		std::cout << "generating class B\n";
		return new B();
	}
	std::cout << "generating class C\n";
	return new C();
}

int main()
{
	srand(time(NULL));

	Base *ptr_1 = generate();
	Base *ptr_2 = generate();
	Base *ptr_3 = generate();

	std::cout << "with pointers\n";
	identify(ptr_1);
	identify(ptr_2);
	identify(ptr_3);

	std::cout << "\nwith references\n";
	identify(*ptr_1);
	identify(*ptr_2);
	identify(*ptr_3);

	delete ptr_1;
	delete ptr_2;
	delete ptr_3;
	return 0;
}