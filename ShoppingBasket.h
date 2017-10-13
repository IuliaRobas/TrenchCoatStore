#pragma once
#include "TrenchCoat.h"
#include <vector>

class ShoppingBasket
{
protected:
	std::vector <TrenchCoat> trenchCoats;
	double sum;
	int current;
public:
	ShoppingBasket();
	virtual ~ShoppingBasket() {}

	// Adds a trench coat to the basket.
	void add(const TrenchCoat& trenchCoat);

	// Starts displaying items in the basket.
	void start();

	// Displays next item in the basket.
	void next();

	// Checks if the basket is empty.
	bool isEmpty();

	// Gets the total sum of the items in the basket.
	double ShoppingBasket::getTotal();

	// Gets the current trench coat in the basket.
	TrenchCoat ShoppingBasket::getCurrentTrenchCoat();

	// Gets the size of the shopping basket, that is the number of items in it.
	int ShoppingBasket::getSize();
};

//void testShoppingBasket();