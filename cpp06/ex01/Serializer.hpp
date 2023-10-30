#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

typedef struct Data
{
	std::string name;
	int age;
} Data;

class Serializer
{
public:
	Serializer();
	Serializer(const Serializer &s);
	~Serializer();
	Serializer &operator=(const Serializer &s);

	static uintptr_t serialize(Data *ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif