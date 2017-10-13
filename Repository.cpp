#include "Repository.h"
#include <string>
#include <fstream>
//#include <assert.h>
#include "Utils.h"
#include "RepositoryExceptions.h"
using namespace std;

/*
Repository::Repository(const std::string& filename)
{
	this->filename = filename;
	this->readFromFile();
}
*/
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
	{
		throw DuplicateTrenchCoatException();
		return 0;
	}
	this->trenchCoats.push_back(c);
	//this->writeToFile();
	return 1;

}

int Repository::deleteCoat(const TrenchCoat& c)
{
	TrenchCoat found = this->findByID(c.getID());
	if (found.getID() == 0)
	{
		throw InexistentTrenchCoatException();
		return 0;
	}
	int pos = this->findPositionByID(c.getID());
	this->trenchCoats.erase(trenchCoats.begin() + pos);
	//this->writeToFile();
	return 1;
}

int Repository::updateCoat(const TrenchCoat& c)
{
	int pos = this->findPositionByID(c.getID());
	if (this->trenchCoats.size() == 0)
		return 0;
	if (pos == -1)
	{
		throw InexistentTrenchCoatException();
		return 0;
	}
	else
	{
		this->trenchCoats[pos].setSize(c.getSize());
		this->trenchCoats[pos].setColour(c.getColour());
		this->trenchCoats[pos].setPrice(c.getPrice());
		this->trenchCoats[pos].setQuantity(c.getQuantity());
		this->trenchCoats[pos].setPhotograph(c.getPhotograph());
		//this->writeToFile();
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
/*
void Repository::readFromFile()
{
	ifstream file(this->filename);

	if (!file.is_open())
		throw FileException("The file could not be opened!");

	TrenchCoat coat;
	while (file >> coat)
		this->trenchCoats.push_back(coat);

	file.close();
}*/
/*
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
*/
/*
void testRepository()
{
	Repository repo{};
	TrenchCoat c1(11, 34, 15, "beige", 100, 200, "https://cache.net-a-porter.com/images/products/372462/372462_in_pp.jpg");
	assert(repo.addCoat(c1) == 1);
	assert(repo.getCoats().size() == 1);
	TrenchCoat test1 = repo.findByID(11);
	assert(test1.getColour() == "beige");
	TrenchCoat test2 = repo.findByID(55);
	assert(test2.getID() == 0);
	TrenchCoat c2(11, 28, 15, "blue", 100, 200, "google.ro");
	assert(repo.addCoat(c2) == 0);
	assert(repo.getCoats().size() == 1);
	assert(repo.deleteCoat(c1) == 1);
	TrenchCoat c3(23, 28, 15, "white", 100, 200, "ssa.com");
	assert(repo.deleteCoat(c3) == 0);
	assert(repo.getCoats().size() == 0);


	assert(repo.updateCoatRef(c3) == 0);
	assert(repo.addCoat(c1) == 1);
	assert(repo.getCoats().size() == 1);
	TrenchCoat c4(11, 22, 15, "ssd", 1, 2, "ewe");
	assert(repo.updateCoatRef(c4) == 1);

	for (int i = 0; i < repo.getCoats().size(); i++)
	{
		TrenchCoat ex = repo.getCoats()[i];
		assert(ex.getColour() == "ssd");
		//cout << "hi";
		//cout << ex.getID() << " " << ex.getSize() << " " << ex.getColour()<<" "<<ex.getPrice() <<" "<<ex.getQuantity()<< endl;
	}
	cout << "Repository tested" << endl;


}*/