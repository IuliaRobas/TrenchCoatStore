#pragma once
#include <iostream>
class TrenchCoat
{
private:
	int ID;
	double size;
	double length;
	std::string colour;
	double price;
	double quantity;
	std::string photograph; //photo link
public:
	// default constructor for a Trench Coat
	TrenchCoat();

	// constructor with parameters
	TrenchCoat(const int& ID, const double& size, const double& length, const std::string& colour, const double& price, const double& quantity, const std::string& photograph);

	// overloading the equality operator
	bool operator==(const TrenchCoat& c);

	// overloading the less operator
	bool operator<(const double& length);

	// getters for the fields of the TrenchCoat class
	int getID() const { return ID; }
	double getSize()const { return size; }
	double getLength() const { return length; }
	std::string getColour() const { return colour; }
	double getPrice() const { return price; }
	double getQuantity() const { return quantity; }
	std::string getPhotograph() const { return photograph; }

	// setters for the fields of the TrenchCoat class
	void setID(const int& newID) { this->ID = newID; };
	void setSize(const double& newSize) { this->size = newSize; };
	void setLength(const double& newLength) { this->length = newLength; }
	void setColour(const std::string& newColour) { this->colour = newColour; }
	void setPrice(const double& newPrice) { this->price = newPrice; };
	void setQuantity(const double& newQuantity) { this->quantity = newQuantity; };
	void setPhotograph(const std::string& newPhotograph) { this->photograph = newPhotograph; };

	// Opens the photo of the trench coat
	void display();

	friend std::istream& operator >> (std::istream& is, TrenchCoat& c);
	friend std::ostream& operator<<(std::ostream& os, const TrenchCoat& s);
};

//void testTrenchCoat();