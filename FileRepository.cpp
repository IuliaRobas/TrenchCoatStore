#include "Repository.h"
#include <string>
#include <fstream>
#include "Utils.h"
#include "RepositoryExceptions.h"

using namespace std;

Repository::Repository(const std::string& filename)
{
	this->filename = filename;
	this->readFromFile();
}


TrenchCoat Repository::findByID(const int& ID)
{
	std::vector<TrenchCoat> coatsInRepo = this->trenchCoats;
	if (coatsInRepo.size() == 0)
		return TrenchCoat{};

	//for (int i = 0; i < this->trenchCoats.size(); i++)
	for (std::vector<TrenchCoat>::iterator it = this->trenchCoats.begin(); it != this->trenchCoats.end(); it++)
	{

		//TrenchCoat c = coatsInRepo[i];
		TrenchCoat c = *it;
		if (c.getID() == ID)
			return c;
		//return this->trenchCoats.getElementOnPos(i);
	}
	return TrenchCoat{};

}

int Repository::addCoat(const TrenchCoat& c)
{
	TrenchCoat found = this->findByID(c.getID());
	if (found.getID() != 0)
		return 0;
	this->trenchCoats.push_back(c);
	this->writeToFile();
	return 1;

}

int Repository::deleteCoat(const TrenchCoat& c)
{
	TrenchCoat found = this->findByID(c.getID());
	if (found.getID() == 0)
		return 0;
	int pos = this->findPositionByID(c.getID());
	this->trenchCoats.erase(trenchCoats.begin() + pos);
	this->writeToFile();
	return 1;
}

int Repository::updateCoat(const TrenchCoat& c)
{
	int pos = this->findPositionByID(c.getID());
	if (this->trenchCoats.size() == 0)
		return 0;
	if (pos == -1)
		return 0;
	else
	{
		this->trenchCoats[pos].setSize(c.getSize());
		this->trenchCoats[pos].setColour(c.getColour());
		this->trenchCoats[pos].setPrice(c.getPrice());
		this->trenchCoats[pos].setQuantity(c.getQuantity());
		this->trenchCoats[pos].setPhotograph(c.getPhotograph());
		this->writeToFile();
		return 1;
	}

}


int Repository::findPositionByID(const int& ID)
{
	std::vector <TrenchCoat> coatsInRepo = this->trenchCoats;
	if (coatsInRepo.size() == 0)
		return -1;

	for (int i = 0; i < this->trenchCoats.size(); i++)
	{

		TrenchCoat c = coatsInRepo[i];
		if (c.getID() == ID)
			return i;
	}
	return -1;
}

int Repository::updateCoatRef(const TrenchCoat& c)
{
	TrenchCoat& found = this->findByIDRef(c.getID());
	if (found.getID() == 0)
		return 0;
	//TrenchCoat c1 = this->findByID(c.getID());
	//int pos = this->findPositionByID(c.getID());
	//TrenchCoat c1 = this->trenchCoats.getElementOnPos(pos);
	std::vector <TrenchCoat> coatsInRepo = this->trenchCoats;
	if (coatsInRepo.size() == 0)
		return 0;

	found.setSize(c.getSize());
	found.setColour(c.getColour());
	found.setPrice(c.getPrice());
	found.setQuantity(c.getQuantity());
	found.setPhotograph(c.getPhotograph());
	this->writeToFile();
	return 1;
}

TrenchCoat& Repository::findByIDRef(const int&ID)
{

	std::vector <TrenchCoat> coatsInRepo = this->trenchCoats;
	if (coatsInRepo.size() == 0)
		return TrenchCoat{};

	for (int i = 0; i < this->trenchCoats.size(); i++)
	{

		TrenchCoat c = coatsInRepo[i];
		if (c.getID() == ID)
			return this->trenchCoats[i];
	}
	return TrenchCoat{};
}


void Repository::readFromFile()
{
	ifstream file(this->filename);

	if (!file.is_open())
		throw FileException("The file could not be opened!");

	TrenchCoat coat;
	while (file >> coat)
		this->trenchCoats.push_back(coat);

	file.close();
}

void Repository::writeToFile()
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