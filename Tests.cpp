#include "TrenchCoat.h"

#include"Repository.h"
#include "ShoppingBasket.h"
#include "TrenchCoat.h"
#include "Controller.h"
#include "Tests.h"
#include <iostream>
#include <assert.h>

using namespace std;

void Tests::testTrenchCoat()
{
	TrenchCoat c{};
	assert(c.getColour() == "");
	assert(c.getID() == 0);
	assert(c.getSize() == 0);
	assert(c.getLength() == 0);
	assert(c.getPrice() == 0);
	assert(c.getQuantity() == 0);
	assert(c.getPhotograph() == "");

	TrenchCoat c1{ 1,34,15,"red",300,100,"link1" };
	assert(c1.getID() == 1);
	assert(c1.getSize() == 34);
	assert(c1.getLength() == 15);
	assert(c1.getPrice() == 300);
	assert(c1.getQuantity() == 100);
	assert(c1.getPhotograph() == "link1");
	assert(c1.getColour() == "red");

	c1.setID(11);
	c1.setSize(30);
	c1.setLength(10);
	c1.setColour("blue");
	c1.setPrice(150);
	c1.setQuantity(500);
	c1.setPhotograph("newlink");
	assert(c1.getID() == 11);
	assert(c1.getSize() == 30);
	assert(c1.getLength() == 10);
	assert(c1.getPrice() == 150);
	assert(c1.getQuantity() == 500);
	assert(c1.getPhotograph() == "newlink");
	assert(c1.getColour() == "blue");

	TrenchCoat c2{ 2,34,15,"blue",500,100,"link2" };
	assert((c1 == c2) == false);
	TrenchCoat c3{ 2,36,15,"white",300,100,"link3" };
	assert(c2 == c3);
	assert(c3 < 20);
	cout << "TrenchCoat tested" << endl;
}

/*
void Tests::testDynamicVector()
{
	DynamicVector trenchCoats{ 1 };
	TrenchCoat c1{ 1,34,15,"red",300,100,"link1" };
	TrenchCoat c2{ 2,34,15,"blue",500,100,"link2" };
	trenchCoats.add(c1);
	assert(trenchCoats.getSize() == 1);
	trenchCoats.add(c2);
	assert(trenchCoats.getSize() == 2);
	TrenchCoat c = trenchCoats.getElementOnPos(1);
	assert(c.getID() == 2);
	trenchCoats - c1;
	assert(trenchCoats.getSize() == 1);
	assert(trenchCoats.getElementOnPos(0).getID() == 2);
	cout << "DynamicVector tested" << endl;
	/*for (int i = 0; i < trenchCoats.size(); i++)
	{
	TrenchCoat c = trenchCoats.getElementOnPos(i);
	cout << c.getID() << " " << c.size() << " " << c.getColour() << " " << c.getPrice() << "$ " << c.getQuantity() << " " << endl;
	}

}*/
/*
void Tests::testDynamicVectorT()
{

	DynamicVectorT <TrenchCoat>trenchCoats{ 1 };
	TrenchCoat c1{ 1,34,15,"red",300,100,"link1" };
	TrenchCoat c2{ 2,34,15,"blue",500,100,"link2" };
	trenchCoats.add(c1);
	assert(trenchCoats.getSize() == 1);
	trenchCoats.add(c2);
	assert(trenchCoats.getSize() == 2);
	TrenchCoat c = trenchCoats.getElementOnPos(1);
	assert(c.getID() == 2);


	//test the iterator
	DynamicVectorT<int> v1{ 2 };
	v1.add(12);
	v1.add(13);
	assert(v1.getSize() == 2);
	DynamicVectorT<int>::iterator it = v1.begin();
	assert(*it == 12);
	assert(it != v1.end());
	it++;
	assert(*it == 13);
	cout << "DynamicVectorTemplate tested" << endl;

}*/

void Tests::testRepository()
{

	Repository repo{};
	TrenchCoat c1(11, 34, 15, "beige", 100, 200, "https://cache.net-a-porter.com/images/products/372462/372462_in_pp.jpg");
	assert(repo.updateCoatRef(c1) == 0);
	assert((repo.findByID(1).getID()) == 0);
	assert((repo.findByIDRef(1).getID() == 0));
	assert(repo.addCoat(c1) == 1);
	assert((repo.findByID(11).getID()) == 11);
	assert((repo.findByIDRef(11).getID() == 11));
	assert(repo.getCoats()[0].getID() == 11);
	assert(repo.getCoats().size() == 1);
	assert(repo.findPositionByID(11) == 0);
	assert(repo.findPositionByID(0) == -1);
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

	assert(repo.updateCoat(c3) == 0);
	assert(repo.updateCoatRef(c3) == 0);
	assert(repo.addCoat(c1) == 1);
	assert(repo.getCoats().size() == 1);
	TrenchCoat c4{ 11, 22,30, "ssd", 1, 2, "ewe" };
	assert(repo.updateCoat(c4) == 1);
	assert(repo.updateCoatRef(c3) == 0);
	assert(repo.getCoats().size() == 1);
	assert(repo.updateCoatRef(c4) == 1);

	for (int i = 0; i < repo.getCoats().size(); i++)
	{
		TrenchCoat ex = repo.getCoats()[i];
		assert(ex.getColour() == "ssd");
		//cout << "hi";
		//cout << ex.getID() << " " << ex.size() << " " << ex.getColour()<<" "<<ex.getPrice() <<" "<<ex.getQuantity()<< endl;
	}
	cout << "Repository tested" << endl;



}

void Tests::testShoppingBasket()
{
	ShoppingBasket basket{};
	assert(basket.isEmpty());
	assert(basket.getTotal() == 0);
	assert(basket.getCurrentTrenchCoat().getID() == 0);
	basket.start();
	basket.next();
	TrenchCoat c1(11, 34, 15, "beige", 100, 200, "https://cache.net-a-porter.com/images/products/372462/372462_in_pp.jpg");
	basket.add(c1);
	TrenchCoat c2(11, 34, 15, "beige", 23, 200, "https://cache.net-a-porter.com/images/products/372462/372462_in_pp.jpg");
	basket.add(c2);
	assert(basket.getTotal() == 123);
	assert(basket.getSize() == 2);
	basket.start();
	basket.next();
	cout << "ShoppingBasket tested" << endl;
}

void Tests::testController()
{
	//Repository repo{};
	VirtualRepository* repo = new Repository();
	Controller ctrl{ repo };
	assert(ctrl.getRepo()->getCoats().size() == 0);
	///assert(ctrl.getShoppingBasket().getCurrentTrenchCoat().getID() == 0);
	assert(ctrl.getShoppingBasket()->getCurrentTrenchCoat().getID() == 0);
	///assert(ctrl.getShoppingBasket().getSize() == 0);
	assert(ctrl.getShoppingBasket()->getSize() == 0);
	///assert(ctrl.getShoppingBasket().getTotal()==0);
	assert(ctrl.getShoppingBasket()->getTotal() == 0);

	assert(ctrl.addCoatToRepository(12, 34, 15, "pink", 200, 40, "www.google.ro")==1);
	assert(ctrl.addCoatToRepository(12, 34, 15, "pink", 200, 40, "www.google.ro") == 0);

	assert(ctrl.addCoatToRepository(13, 36, 15, "purple", 200, 45, "www.google.ro")==1);
	assert(ctrl.updateCoatFromRepository(13, 40, 25, "pink", 250, 55, "www.google1.ro") == 1);
	assert(ctrl.updateCoatFromRepository(55, 40, 25, "pink", 250, 55, "www.google1.ro") == 0);

	assert(ctrl.getRepo()->getCoats().size() == 2);
	std::vector<TrenchCoat>res = ctrl.listTrenchCoatsWithSizeCtrl(34);
	assert(res.size() == 1);
	std::vector<TrenchCoat>res2 = ctrl.listTrenchCoatsWithSizeCtrl(50);
	assert(res2.size() == 0);
	std::vector<TrenchCoat>res1 = ctrl.listTrenchCoatsWithLengthSmallerThanCtrl(20);
	assert(res1.size() == 2);
	std::vector<TrenchCoat>res4 = ctrl.listTrenchCoatsWithLengthSmallerThanCtrl(1);
	assert(res4.size() == 0);

	assert(ctrl.deleteCoatFromRepository(12) == 1);
	assert(ctrl.deleteCoatFromRepository(50) == 0);
	assert(ctrl.getRepo()->getCoats().size() == 1);
	TrenchCoat c1(11, 34, 15, "beige", 200, 200, "https://cache.net-a-porter.com/images/products/372462/372462_in_pp.jpg");
	TrenchCoat c2(2, 34, 15, "beige", 20, 200, "https://cache.net-a-porter.com/images/products/372462/372462_in_pp.jpg");
	
	std::vector<TrenchCoat> trenchCoats{};
	trenchCoats.push_back(c1);
	
	std::vector<TrenchCoat> v = ctrl.listTrenchCoatsWithSizeCtrl(0);
	assert(v.size() == trenchCoats.size());
	trenchCoats.push_back(c2);
	ctrl.sortByPrice(trenchCoats);
	assert(trenchCoats[0].getPrice() == 20);
	
	ctrl.addCoatToShoppingBasketCtrl(c1);

	ctrl.startShoppingBasket();
	ctrl.nextTrenchCoatsShoppingBasket();
	cout << "Controller tested" << endl;
}
void Tests::testAll()
{
	testTrenchCoat();
	testRepository();
	testController();
	testShoppingBasket();
}