#include "TrenchCoat.h"
#include <Windows.h>
#include <shellapi.h>
#include "Utils.h"
#include <vector>
#include <string>
#include <assert.h>
#include <iostream>
using namespace std;

TrenchCoat::TrenchCoat()
{
	this->ID = 0;
	this->size = 0;
	this->length = 0;
	this->colour = "";
	this->price = 0;
	this->quantity = 0;
	this->photograph = "";
}

TrenchCoat::TrenchCoat(const int& ID, const double& size, const double&length, const std::string& colour, const double& price, const double& quantity, const std::string& photograph)
{
	this->ID = ID;
	this->size = size;
	this->length = length;
	this->colour = colour;
	this->price = price;
	this->quantity = quantity;
	this->photograph = photograph;
}

void TrenchCoat::display()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getPhotograph().c_str(), NULL, SW_SHOWMAXIMIZED);

}

bool TrenchCoat::operator==(const TrenchCoat& c)
{
	if (this->getID() != c.getID())
		return false;
	return true;
}

bool TrenchCoat::operator<(const double& length)
{
	if (this->getLength() <length)
		return true;
	return false;
}

istream & operator >> (istream & is,TrenchCoat & c)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 7) // make sure all the data was valid
		return is;

	c.ID = stod(tokens[0]);
	c.size = stod(tokens[1]);
	c.length = stod(tokens[2]);
	c.colour = tokens[3];
	c.price = stod(tokens[4]);
	c.quantity = stod(tokens[5]);
	c.photograph = tokens[6];

	return is;

}

ostream & operator<<(ostream & os, const TrenchCoat & c)
{
	os << c.ID << "," << c.size << "," << c.length << "," << c.colour << "," << c.price<< "," << c.quantity << "," << c.photograph << "\n";
	return os;
}

/*
void testTrenchCoat()
{
	TrenchCoat c1{ 1,34,15,"red",300,100,"link1" };
	TrenchCoat c2{ 2,34,15,"blue",500,100,"link2" };
	assert((c1 == c2) == false);
	TrenchCoat c3{ 1,36,15,"white",300,100,"link3" };
	assert(c1 == c3);
	cout << "TrenchCoat tested" << endl;
}*/