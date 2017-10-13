#include "Controller.h"
#include <algorithm>
int Controller::addCoatToRepository(const int&ID, const double& size, const double& length, const std::string& colour, const double& price, const double& quantity, const std::string& photograph)
{
	TrenchCoat c{ ID, size, length,colour,price,quantity,photograph };
	this->validator.validate(c);
	int res = this->repo->addCoat(c);
	return res;
}

int Controller::deleteCoatFromRepository(const int& ID)
{
	TrenchCoat c = this->repo->findByID(ID);
	int res = this->repo->deleteCoat(c);
	return res;
}

int Controller::updateCoatFromRepository(const int&ID, const double& size, const double&length, const std::string& colour, const double& price, const double& quantity, const std::string& photograph)
{
	//TrenchCoat c = this->repo.findByID(ID);
	TrenchCoat c{ ID,size,length,colour,price,quantity,photograph };
	this->validator.validate(c);
	int res = this->repo->updateCoat(c);
	return res;
}

std::vector<TrenchCoat> Controller::listTrenchCoatsWithSizeCtrl(const double& size)
{
	if (size == 0)
	{
		std::vector<TrenchCoat> res = getRepo()->getCoats();
		return res;
	}
	std::vector<TrenchCoat> all = getRepo()->getCoats();
	std::vector<TrenchCoat> res = std::vector<TrenchCoat>{};
	for (int i = 0; i < all.size(); i++)
	{
		TrenchCoat c = all[i];
		if (c.getSize() == size)
			res.push_back(c);
	}
	return res;
}


std::vector<TrenchCoat> Controller::listTrenchCoatsWithLengthSmallerThanCtrl(const double& length)
{

	std::vector<TrenchCoat> all = getRepo()->getCoats();
	std::vector<TrenchCoat> res = std::vector<TrenchCoat>{};
	//auto it = std::copy_if(all.begin(), all.end(), res.begin(),[&](TrenchCoat c) {return (c.getLength() < length); });

	for (int i = 0; i < all.size(); i++)
	{
		TrenchCoat c = all[i];
		if (c<length)
			res.push_back(c);
	}
	return res;

}

bool comparisonFunction(TrenchCoat c1, TrenchCoat c2)
{
	return c1.getPrice() < c2.getPrice();
}

//DynamicVector& Controller::sortByPrice(DynamicVector& trenchCoats)
std::vector<TrenchCoat>& Controller::sortByPrice(std::vector<TrenchCoat>& trenchCoats)
{

	std::sort(trenchCoats.begin(), trenchCoats.end(), comparisonFunction);
	/*int length = trenchCoats.size();
	for (int i = 0; i < length-1; i++)
	{
	TrenchCoat& c1 = trenchCoats[i];
	for (int j = i + 1; j < length; j++)
	{
	TrenchCoat& c2 = trenchCoats[j];
	if (c1.getPrice() > c2.getPrice())
	{
	TrenchCoat aux{};
	aux.setID(c1.getID());
	c1.setID(c2.getID());
	c2.setID(aux.getID());

	aux.setSize(c1.getSize());
	c1.setSize(c2.getSize());
	c2.setSize(aux.getSize());

	aux.setColour(c1.getColour());
	c1.setColour(c2.getColour());
	c2.setColour(aux.getColour());

	aux.setPrice(c1.getPrice());
	c1.setPrice(c2.getPrice());
	c2.setPrice(aux.getPrice());

	aux.setQuantity(c1.getQuantity());
	c1.setQuantity(c2.getQuantity());
	c2.setQuantity(aux.getQuantity());

	aux.setPhotograph(c1.getPhotograph());
	c1.setPhotograph(c2.getPhotograph());
	c2.setPhotograph(aux.getPhotograph());
	}
	}

	}*/
	return trenchCoats;
}

void Controller::addCoatToShoppingBasketCtrl(const TrenchCoat& c)
{
	if (this->basket == nullptr)
		return;
	//this->basket.add(c);
	this->basket->add(c);
}

void Controller::startShoppingBasket()
{
	//this->basket.start();
	if (this->basket == nullptr)
		return;
	this->basket->start();
}

void Controller::nextTrenchCoatsShoppingBasket()
{
	//this->basket.next();
	if (this->basket == nullptr)
		return;
	this->basket->next();
}

void Controller::saveShoppingBasket(const std::string& filename)
{
	if (this->basket == nullptr)
		return;

	this->basket->setFilename(filename);
	this->basket->writeToFile();
}