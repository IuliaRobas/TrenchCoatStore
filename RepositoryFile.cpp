#include "RepositoryFile.h"


int RepositoryFile::deleteCoat(const TrenchCoat& c)
{
	int res=Repository::deleteCoat(c);
	writeToFile();
	return res;
}
int RepositoryFile::addCoat(const TrenchCoat& c)
{
	int res= Repository::addCoat(c);
	writeToFile();
	return res;
}

int RepositoryFile::updateCoat(const TrenchCoat& c)
{
	int res= Repository::updateCoat(c);
	writeToFile();
	return res;
 }

int RepositoryFile::findPositionByID(const int& ID)
{
	return Repository::findPositionByID(ID);

}

TrenchCoat RepositoryFile::findByID(const int& ID)
{
	return Repository::findByID(ID);
}

int RepositoryFile::updateCoatRef(const TrenchCoat& c)
{
	int res= Repository::updateCoatRef(c);
	writeToFile();
	return res;
}
TrenchCoat& RepositoryFile::findByIDRef(const int&ID)
{
	return Repository::findByIDRef(ID);
}

std::vector <TrenchCoat>  RepositoryFile::getCoats() 
{
	return Repository::getCoats();
}

void RepositoryFile::setFilename(const std::string& filename) {
	this->filename = filename;
}





void RepositoryFile::readFromFile()
{
	ifstream file(this->filename);

	if (!file.is_open())
		throw FileException("The file could not be opened!");

	TrenchCoat coat;
	while (file >> coat)
		this->trenchCoats.push_back(coat);

	file.close();
}

void RepositoryFile::writeToFile()
{
	ofstream file(this->filename);
	if (!file.is_open())
	throw FileException("The file could not be opened!");

	for (auto coat : this->trenchCoats)
	{
	file << coat;
	}

	file.close();
}