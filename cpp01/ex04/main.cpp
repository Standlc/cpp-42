#include <iostream>
#include <fstream>

void findNReplace(std::string &str, std::string find, std::string replace)
{
	int findLen = find.length();
	size_t findPos = str.find(find);

	while (findPos != std::string::npos)
	{
		str.erase(findPos, findLen);
		str.insert(findPos, replace);
		findPos = str.find(find, findPos);
	}
}

void replaceInNewFile(std::ifstream &ogFile, std::ofstream &fileReplace, std::string find, std::string replace)
{
	std::string fileContent;

	if (!getline(ogFile, fileContent, '\0'))
		return;
	if (find != replace)
		findNReplace(fileContent, find, replace);
	fileReplace << fileContent;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Enter <filename> <find> <replace>\n";
		return (1);
	}

	std::string fileName = argv[1];
	std::ifstream ogFile(fileName);
	if (!ogFile)
	{
		std::cout << "Could not open: " << fileName << std::endl;
		return (1);
	}
	std::ofstream fileReplace(fileName + ".replace");
	if (!fileReplace)
	{
		std::cout << "Could not create: " << fileName + ".replace" << std::endl;
		return (ogFile.close(), 1);
	}

	replaceInNewFile(ogFile, fileReplace, argv[2], argv[3]);
	ogFile.close();
	fileReplace.close();
}