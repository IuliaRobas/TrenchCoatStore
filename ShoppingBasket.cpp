#include "ShoppingBasket.h"
#include <iostream>
#include <assert.h>
#include "Repository.h"
#include "TrenchCoat.h"
using namespace std;

ShoppingBasket::ShoppingBasket()
{
	this->sum = 0;
	this->current = 0;
}

void ShoppingBasket::add(const TrenchCoat& trenchCoat)
{
	this->trenchCoats.push_back(trenchCoat);
	this->sum += trenchCoat.getPrice();
}

double ShoppingBasket::getTotal()
{
	return this->sum;
}

bool ShoppingBasket::isEmpty()
{
	return this->trenchCoats.size() == 0;
}



TrenchCoat ShoppingBasket::getCurrentTrenchCoat()
{
	if (this->current == this->trenchCoats.size())
		this->current = 0;
	std::vector <TrenchCoat> elems = this->trenchCoats;
	if (elems.size() != 0)
		return elems[this->current];
	return TrenchCoat{};
}

void ShoppingBasket::start()
{
	if (this->trenchCoats.size() == 0)
		return;
	this->current = 0;
	TrenchCoat currentTrenchCoat = this->getCurrentTrenchCoat();
	currentTrenchCoat.display();
}

void ShoppingBasket::next()
{
	if (this->trenchCoats.size() == 0)
		return;
	this->current++;
	TrenchCoat currentTrenchCoat = this->getCurrentTrenchCoat();
	currentTrenchCoat.display();
}

int ShoppingBasket::getSize()
{
	return this->trenchCoats.size();
}
/*
void testShoppingBasket()
{
	ShoppingBasket basket{};
	TrenchCoat c1(11, 34, 15, "beige", 100, 200, "https://cache.net-a-porter.com/images/products/372462/372462_in_pp.jpg");
	basket.add(c1);
	TrenchCoat c2(11, 34, 15, "beige", 23, 200, "https://cache.net-a-porter.com/images/products/372462/372462_in_pp.jpg");
	basket.add(c2);
	assert(basket.getTotal() == 123);
	cout << "ShoppingBasket tested" << endl;
}
*/