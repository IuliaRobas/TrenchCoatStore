#include "TrenchCoatValidator.h"

using namespace std;

TrenchCoatException::TrenchCoatException(std::vector<std::string> _errors) : errors{ _errors }
{
}

std::vector<std::string> TrenchCoatException::getErrors() const
{
	return this->errors;
}

void TrenchCoatValidator::validate(const TrenchCoat& c)
{
	vector<string> errors;
	if (c.getID() < 0)
		errors.push_back("ID cannot be smaller than 0.\n");
	if (c.getSize() < 0)
		errors.push_back("Size cannot be smaller than 0.\n");
	if (c.getLength() < 0)
		errors.push_back("Length cannot be smaller than 0.\n");
	if(c.getColour().size()<4)
		errors.push_back("The colour must have at least 4 characters.\n");
	if (c.getPrice() < 0)
		errors.push_back("Price cannot be smaller than 0.\n");
	if (c.getQuantity() < 0)
		errors.push_back("Quantity cannot be smaller than 0.\n");

	// search for "www" or "http" at the beginning of the source string
	int posWww = c.getPhotograph().find("www");
	int posHttp = c.getPhotograph().find("http");
	if (posWww != 0 && posHttp != 0)
		errors.push_back("The photograph link must start either with \"www\" or \"http\".\n");
	
	if (errors.size() > 0)
	{
		errors.insert(errors.begin(), "\n");
		throw TrenchCoatException(errors);
	}
}
