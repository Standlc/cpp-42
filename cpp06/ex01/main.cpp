#include "Serializer.hpp"

int main()
{
	Data jeff = {"Jeff", 34};

	uintptr_t jeffSerializedPtr = Serializer::serialize(&jeff);

	std::cout << "Jeff's serialized pointer: " << jeffSerializedPtr << "\n";
	std::cout << "\n";

	Data *jeffAgain = Serializer::deserialize(jeffSerializedPtr);

	std::cout << "Jeff after serialization and deserialization: " << jeffAgain->name << " " << jeffAgain->age << "\n";
	return 0;
}