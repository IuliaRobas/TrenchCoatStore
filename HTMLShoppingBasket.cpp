#include "HTMLShoppingBasket.h"
#include <fstream>
#include <Windows.h>
#include "RepositoryExceptions.h"

using namespace std;

void HTMLShoppingBasket::writeToFile()
{
	ofstream f(this->filename);

	if (!f.is_open())
		throw FileException("The file could not be opened!");
	f << "<!DOCTYPE html> " << endl <<
		"<html>" << endl <<
		"<head> " << endl <<
		"<title>ShoppingBasketHTML</title> " << endl <<
		"</head> " << endl <<
		"<body>" << endl <<
		"<table border=\"1\">" << endl <<
		"<tr>" << endl <<
		"<td>ID</td>" << endl <<
		"<td>Size</td>" << endl <<
		"<td>Length</td>" << endl <<
		"<td>Colour</td>" << endl <<
		"<td>Price</td>" << endl <<
		"<td>Quantity</td>" << endl <<
		"<td>Photograph link</td>" << endl <<
		"</tr>" << endl;

	for (auto s : this->trenchCoats)
	{
		f << "<tr>" << endl; 
		f << "<td>" << s.getID() << "</td>" << endl <<
			"<td>" << s.getSize() << "</td>" << endl <<
			"<td>" << s.getLength() << "</td>" << endl <<
			"<td>" << s.getColour() << "</td>" << endl <<
			"<td>" << s.getPrice() << "</td>" << endl <<
			"<td>" << s.getQuantity() << "</td>" << endl <<
			"<td><a href=" << endl << "\"" << s.getPhotograph() << "\">Link</a></td>" << endl <<
			"</tr>" << endl;
	}
	f<<"</table>"<<endl<<
		"</body>" << endl <<
		"</html>";
	f.close();
}

void HTMLShoppingBasket::displayShoppingBasket() const
{
	string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations
											   //ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\OpenOffice 4\\program\\scalc.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	ShellExecuteA(NULL, NULL, "chrome.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}