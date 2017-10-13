#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include "UI.h"
#include <conio.h>
#include "TrenchCoatValidator.h"
#include "RepositoryExceptions.h"
using namespace std;

void UI::printModes()
{
	cout << "\n**********************************************************";
	cout << "\nAVAILABLE MODES.\n";
	cout << "1 - Administrator mode.\n";
	cout << "2 - User mode.\n";
	cout << "0 - Exit.\n";
	cout << "**********************************************************\n";
}

void UI::printAdministratorOptions()
{
	cout << "\n**********************************************************";
	cout << "\nAVAILABLE OPTIONS.\n";
	cout << "\t1 - Add a new trench coat.\n";
	cout << "\t2 - Delete a trench coat.\n";
	cout << "\t3 - Update the information of a trench coat.\n";
	cout << "\t4 - List all trench coats.\n";
	cout << "\t5 - List all trench coats with length smaller then a given length.\n";
	cout << "\t6 - Sort trench coats ascendingly by price.\n";
	cout << "\t0 - Back.\n";
	cout << "**********************************************************\n";
}

void UI::printUserOptions()
{
	cout << "\n**********************************************************";
	cout << "\nAVAILABLE OPTIONS.\n";
	cout << "\t1 - See the trench coats in the database, having a given size.\n";
	cout << "\t2 - See content of shopping basket and the total price of the items.\n";
	cout << "\t3 - Save shopping basket to file.\n";
	cout << "\t4 - See shopping basket as file.\n";
	cout << "\t0 - Back.\n";
	cout << "**********************************************************\n";
}

void UI::printShoppingBasketOptions()
{
	cout << "\n**********************************************************";
	cout << "\nSHOPPING BASKET OPTIONS.\n";
	cout << "\t1 - Add trench coat to shopping basket.\n";
	cout << "\t2 - Next.\n";
	cout << "\t0 - Back.\n";
	cout << "**********************************************************\n";
}
int UI::readIntegerNumber(const char* message)
{
	char string[10];
	int flag = 0;
	int r = 0;
	int res = 0;
	while (flag == 0)
	{
		cout << message;
		cin >> string;
		r = sscanf(string, "%d", &res);
		flag = (r == 1);
		if (flag == 0)
			cout << "Error reading number! Please type in again!\n";
	}
	return res;

}

double UI::readFloatNumber(const char* message)
{
	char string[20];
	int flag = 0;
	int r = 0;
	double res = 0;
	while (flag == 0)
	{
		cout << message;
		cin >> string;
		r = sscanf(string, "%lf", &res);
		flag = (r == 1);
		if (flag == 0)
			cout << "Error reading number! Please type in again!\n";
	}
	return res;
}
void UI::startAdministratorMode()
{

	while (1)
	{
		printAdministratorOptions();
		int option = readIntegerNumber("Please enter your option: ");
		if (option == 0)
			return;

		switch (option)
		{
		case 4:
		{
			this->displayAllCoatsRepo();
			break;
		}
		case 1:
		{
			this->addCoatToRepo();
			break;
		}
		case 2:
		{
			this->deleteCoatFromRepo();
			break;
		}
		case 3:
		{
			this->updateCoatFromRepo();
			break;
		}
		case 5:
		{
			this->listTrenchCoatsLengthSmallerThan();
			break;
		}
		case 6:
		{
			this->sortAscendinglyByPriceUI();
			break;
		}
		}
	}


}

int UI::ShoppingBasketOption()
{
	printShoppingBasketOptions();
	int option = readIntegerNumber("Please enter your option: ");
	return option;

}

void UI::addCoatToShoppingBasket(const TrenchCoat& c)
{

	this->ctrl.addCoatToShoppingBasketCtrl(c);
}


void UI::listTrenchCoatsLengthSmallerThan()
{
	double length = readFloatNumber("Please enter the length: ");
	std::vector<TrenchCoat> coats = this->ctrl.listTrenchCoatsWithLengthSmallerThanCtrl(length);
	//std::vector<TrenchCoat> coats = v.getAllElems();
	if (coats.size() == 0)
	{
		cout << "There are no coats with the length smaller than the given one in the repository." << endl;
		return;
	}
	else
		for (int i = 0; i < coats.size(); i++)
		{
			TrenchCoat c = coats[i];
			cout << c.getID() << " " << c.getSize() << " " << c.getLength() << " " << c.getColour() << " " << c.getPrice() << "$ " << c.getQuantity() << " " << endl;

		}


}
void UI::listTrenchCoatsWithSizeUI()
{
	double size = readIntegerNumber("Please enter the size or 0 for no size: ");
	//cout << size;
	std::vector<TrenchCoat> v = this->ctrl.listTrenchCoatsWithSizeCtrl(size);
	if (size == 0)
	{
		if (v.size() == 0)
		{
			cout << "There are no coats in the repository." << endl;
			return;
		}
		else
			for (std::vector<TrenchCoat>::iterator it = v.begin(); it != v.end(); it++)
			{
				TrenchCoat c = *it;
				cout << c.getID() << " " << c.getSize() << " " << c.getLength() << " " << c.getColour() << " " << c.getPrice() << "$ " << c.getQuantity() << " " << endl;
				c.display();
				//system("pause");
				int option = ShoppingBasketOption();
				//cout << option;
				if (option == 0)
					return;
				switch (option)
				{
				case 1:
				{

					this->addCoatToShoppingBasket(c);
					cout << "Coat added to shopping basket." << endl;

					int ID = c.getID();
					double size = c.getSize();
					double length = c.getLength();
					std::string colour = c.getColour();
					double price = c.getPrice();
					double quantity = c.getQuantity() - 1;
					std::string link = c.getPhotograph();
					int res = this->ctrl.updateCoatFromRepository(ID, size, length, colour, price, quantity, link);
					if (res == 0)
					{
						cout << "The trench coat could not be updated as there isn't any coat with the given ID in the repository." << endl;
					}
					else
					{
						cout << "Trench coat quantity successfully updated." << endl;
					}


					//double total = this->ctrl.getShoppingBasket().getTotal();
					double total = this->ctrl.getShoppingBasket()->getTotal();
					cout << "Total sum: " << total << endl;
					continue;
				}
				}
			}

			/*for (int i = 0; i < v.size(); i++)
			{
				TrenchCoat c = v[i];
				
			}*/


	}
	else
	{
		if (v.size() == 0)
		{
			cout << "There are no coats with the given size in the repository." << endl;
			return;
		}
		while (1)
		{
			for (std::vector<TrenchCoat>::iterator it = v.begin(); it != v.end(); it++)
			{
				TrenchCoat c = *it;
				cout << c.getID() << " " << c.getSize() << " " << c.getLength() << " " << c.getColour() << " " << c.getPrice() << "$ " << c.getQuantity() << " " << endl;
				c.display();
				//system("pause");
				int option = ShoppingBasketOption();
				//cout << option;
				if (option == 0)
					return;
				switch (option)
				{
				case 1:
				{

					this->addCoatToShoppingBasket(c);
					cout << "Coat added to shopping basket." << endl;

					int ID = c.getID();
					double size = c.getSize();
					double length = c.getLength();
					std::string colour = c.getColour();
					double price = c.getPrice();
					double quantity = c.getQuantity() - 1;
					std::string link = c.getPhotograph();
					int res = this->ctrl.updateCoatFromRepository(ID, size, length, colour, price, quantity, link);
					if (res == 0)
					{
						cout << "The trench coat could not be updated as there isn't any coat with the given ID in the repository." << endl;
					}
					else
					{
						cout << "Trench coat quantity successfully updated." << endl;
					}


					//double total = this->ctrl.getShoppingBasket().getTotal();
					double total = this->ctrl.getShoppingBasket()->getTotal();
					cout << "Total sum: " << total << endl;

				}
				case 2:
				{
					break;
				}
				}
			}
		}
	}

}

void UI::displayShoppingBasketUI()
{
	//if (this->ctrl.getShoppingBasket().isEmpty())
	if (this->ctrl.getShoppingBasket()->isEmpty())
	{
		cout << "Nothing to display. The shopping basket is empty." << endl;
		return;
	}

	//double total = this->ctrl.getShoppingBasket().getTotal();
	double total = this->ctrl.getShoppingBasket()->getTotal();
	cout << "Total sum: " << total << endl;
	//this->ctrl.startShoppingBasket();
	/*int size = this->ctrl.getShoppingBasket().getSize();
	for (int i = 0; i < size; i++)
	{
	TrenchCoat c = this->ctrl.getShoppingBasket().getCurrentTrenchCoat();
	c.display();
	cout << c.getID() << " " << c.getSize() << " " << c.getColour() << " " << c.getPrice() << " " << c.getQuantity() << endl;
	system("pause");
	}*/
	this->ctrl.startShoppingBasket();
	//TrenchCoat c = this->ctrl.getShoppingBasket().getCurrentTrenchCoat();
	TrenchCoat c = this->ctrl.getShoppingBasket()->getCurrentTrenchCoat();
	cout << c.getID() << " " << c.getSize() << " " << c.getLength() << " " << c.getColour() << " " << c.getPrice() << " " << c.getQuantity() << endl;
	system("pause");

	//cout << this->ctrl.getShoppingBasket().getSize() << endl;
	//for (int i = 1; i<this->ctrl.getShoppingBasket().getSize(); i++)
	for (int i = 1; i<this->ctrl.getShoppingBasket()->getSize(); i++)
	{
		this->ctrl.nextTrenchCoatsShoppingBasket();
		//TrenchCoat c = this->ctrl.getShoppingBasket().getCurrentTrenchCoat();
		TrenchCoat c = this->ctrl.getShoppingBasket()->getCurrentTrenchCoat();
		cout << c.getID() << " " << c.getSize() << " " << c.getLength() << " " << c.getColour() << " " << c.getPrice() << " " << c.getQuantity() << endl;
		system("pause");



	}
}
/*
void UI::saveShoppingBasketToFileUI()
{
	cout << "\n**********************************************************";
	cout << "\nFILE STORAGE OPTIONS.\n";
	cout << "1 - CSV file.\n";
	cout << "2 - HTML file.\n";
	cout << "**********************************************************\n";
	int option = readIntegerNumber("Please enter your option: ");
	if (option == 1)
		this->saveShoppingBasketToFileUI("CSVFile");
	else
		this->saveShoppingBasketToFileUI("HTMLFile");
	
}

void UI::saveShoppingBasketToFileUI(const std::string fileType)
{
	
	cin.ignore();
	//to ignore anything else on the same line which is a non-number
	//so that it doesn't cause a parse failure	
	if (fileType == "CSVFile")
	{
		
		std::string filename;

		int flag = 0;
		while (flag == 0)
		{
			cout << "Input the file name (absolute path): ";
			getline(cin, filename);
			for (int i = 0; i < filename.length(); i++)
				if (isdigit(filename[i]))
				{
					cout << "Error reading string! Please type in again!\n";
					flag = 0;
					break;
				}
				else
					flag = 1;
		}

		try
		{
			this->ctrl.saveShoppingBasket(filename);

			if (this->ctrl.getShoppingBasket() == nullptr)
			{
				cout << "Shopping basket cannot be displayed!" << endl;
				return;
			}
			if (this->ctrl.getShoppingBasket()->getSize() == 0)
			{
				cout << "Shopping basket is empty!" << endl;
				return;
			}
			cout << "Shopping basket successfully saved to file.\n";
		}
		catch (FileException& e)
		{
			cout << e.what() << endl;
		}
	}
	else
	{
		cout << "HTML";
		return;
	}
}
*/

void UI::saveShoppingBasketToFileUI()
{
	cin.ignore();
	std::string filename;

	int flag = 0;
	while (flag == 0)
	{
		cout << "Input the file name (absolute path): ";
		getline(cin, filename);
		for (int i = 0; i < filename.length(); i++)
			if (isdigit(filename[i]))
			{
				cout << "Error reading string! Please type in again!\n";
				flag = 0;
				break;
			}
			else
				flag = 1;
	}

	try
	{
		this->ctrl.saveShoppingBasket(filename);

		if (this->ctrl.getShoppingBasket() == nullptr)
		{
			cout << "Shopping basket cannot be displayed!" << endl;
			return;
		}
		if (this->ctrl.getShoppingBasket()->getSize() == 0)
		{
			cout << "Shopping basket is empty!" << endl;
			return;
		}
		cout << "Shopping basket successfully saved to file.\n";
	}
	catch (FileException& e)
	{
		cout << e.what() << endl;
	}

}
void UI::seeFileShoppingBasketUI()
{
	this->ctrl.getShoppingBasket()->displayShoppingBasket();


}

void UI::startUserMode()
{

	while (1)
	{
		printUserOptions();
		int option = readIntegerNumber("Please enter your option: ");
		if (option == 0)
			return;

		switch (option)
		{
		case 1:
		{
			this->listTrenchCoatsWithSizeUI();
			break;
		}
		case 2:
		{
			this->displayShoppingBasketUI();
			break;
		}
		case 3:
		{
			this->saveShoppingBasketToFileUI();
			break;
		}
		case 4:
		{
			this->seeFileShoppingBasketUI();
			return;
		}
		}
	}


}


void UI::addCoatToRepo()
{
	cout << "Please type in the information: " << endl;
	/*int ID = 0;
	cout << "ID: ";
	cin >> ID;*/
	int ID = readIntegerNumber("ID: ");

	cin.ignore();
	//cout << "Size: ";
	double size = readFloatNumber("Size: ");
	//cin >> size;
	cin.ignore(); //skips to the next newline

	double length = readFloatNumber("Length: ");
	cin.ignore();

	//to ignore anything else on the same line which is a non-number
	//so that it doesn't cause a parse failure	
	std::string colour;

	int flag = 0;
	while (flag == 0)
	{
		cout << "Colour: ";
		getline(cin, colour);
		for (int i = 0; i <colour.length(); i++)
			if (isdigit(colour[i]))
			{
				cout << "Error reading string! Please type in again!\n";
				flag = 0;
				break;
			}
			else
				flag = 1;
	}
	double price = readFloatNumber("Price: ");
	//cout << "Price: ";
	///cin >> price;
	cin.ignore();
	double quantity = readFloatNumber("Quantity: ");
	//cout << "Quantity: ";
	//cin >> quantity;
	cin.ignore();
	cout << "Photograph link: ";
	std::string link;
	getline(cin, link);
	
	try
	{	
		int res = this->ctrl.addCoatToRepository(ID, size, length, colour, price, quantity, link);
		cout << "Trench coat successfully added." << endl;
	}
	catch (RepositoryException& re)
	{
		cout << re.what() << endl;
	}
	catch (TrenchCoatException& e)
	{
		for (auto s : e.getErrors())
			cout << s;
	}
	catch (FileException& e)
	{
		cout << e.what() << endl;
	}
	/*
	int res = this->ctrl.addCoatToRepository(ID, size, length, colour, price, quantity, link);
	if (res == 0)
	{
		cout << "The trench coat could not be added as there already exists a product with the same ID." << endl;
	}
	else
	{
		cout << "Trench coat successfully added." << endl;
	}*/
}

void UI::deleteCoatFromRepo()
{
	int ID = 0;
	cout << "Please type in the ID of the trench coat to be deleted: ";
	cin >> ID;
	cin.ignore();
	try
	{
		int res = this->ctrl.deleteCoatFromRepository(ID);
		cout << "Trench coat successfully added." << endl;
	}
	catch (RepositoryException& re)
	{
		cout << re.what() << endl;
	}
	/*
	int res = this->ctrl.deleteCoatFromRepository(ID);
	if (res == 0)
	{
		cout << "The trench coat could not be deleted as there isn't any trench coat with the given ID." << endl;
	}
	else
	{
		cout << "Trench coat successfully deleted." << endl;
	}*/
}

void UI::updateCoatFromRepo()
{	
	cout << "Please type in the ID of the trench coat to be updated: ";
	int ID = readIntegerNumber("ID: ");
	cin.ignore();
	cout << "Please type in the new information about the trench coat: " << endl;
	double size = readFloatNumber("Size: ");
	cin.ignore(); 

	double length = readFloatNumber("Length: ");
	cin.ignore();

	//to ignore anything else on the same line which is a non-number
	//so that it doesn't cause a parse failure	
	std::string colour;

	int flag = 0;
	while (flag == 0)
	{
		cout << "Colour: ";
		getline(cin, colour);
		for (int i = 0; i <colour.length(); i++)
			if (isdigit(colour[i]))
			{
				cout << "Error reading string! Please type in again!\n";
				flag = 0;
				break;
			}
			else
				flag = 1;
	}
	double price = readFloatNumber("Price: ");
	//cout << "Price: ";
	///cin >> price;
	cin.ignore();
	double quantity = readFloatNumber("Quantity: ");
	//cout << "Quantity: ";
	//cin >> quantity;
	cin.ignore();
	cout << "Photograph link: ";
	std::string link;
	getline(cin, link);

	
	try
	{
		int res = this->ctrl.updateCoatFromRepository(ID, size, length, colour, price, quantity, link);
		cout << "Trench coat successfully added." << endl;
	}
	catch (RepositoryException& re)
	{
		cout << re.what() << endl;
	}
	catch (TrenchCoatException& e)
	{
		for (auto s : e.getErrors())
			cout << s;
	}
	catch (FileException& e)
	{
		cout << e.what() << endl;
	}
	/*
	int res = this->ctrl.updateCoatFromRepository(ID, size, length, colour, price, quantity, link);
	if (res == 0)
	{
		cout << "The trench coat could not be updated as there isn't any coat with the given ID in the repository." << endl;
	}
	else
	{
		cout << "Trench coat successfully updated." << endl;
	}*/

}
void UI::displayAllCoatsRepo()
{
	//DynamicVector v = this->ctrl.getRepo().getCoats();
	std::vector<TrenchCoat>v = this->ctrl.getRepo()->getCoats();
	//TrenchCoat* coats = v.getAllElems();
	if (v.size() == 0)
	{
		cout << "There are no coats in the repository." << endl;
		return;
	}
	//for (int i = 0; i < v.size(); i++)
	for (std::vector<TrenchCoat>::iterator it = v.begin(); it != v.end(); it++)
	{
		//TrenchCoat c = v[i];
		TrenchCoat c = *it;
		cout << c.getID() << " " << c.getSize() << " " << c.getLength() << " " << c.getColour() << " " << c.getPrice() << "$ " << c.getQuantity() << " " << endl;
		//c.display();
		//system("pause");
	}
}


void UI::sortAscendinglyByPriceUI()
{
	//DynamicVector& v = this->ctrl.getRepo().getCoats();
	std::vector<TrenchCoat> & v = this->ctrl.getRepo()->getCoats();
	v = this->ctrl.sortByPrice(v);
	//TrenchCoat* coats = v.;
	if (v.size() == 0)
	{
		cout << "There are no coats in the repository." << endl;
		return;
	}

	//for (int i = 0; i < v.size(); i++)
	for (std::vector<TrenchCoat>::iterator it = v.begin(); it != v.end(); it++)
	{
		TrenchCoat c = *it;
		//TrenchCoat c = v[i];
		cout << c.getID() << " " << c.getSize() << " " << c.getLength() << " " << c.getColour() << " " << c.getPrice() << "$ " << c.getQuantity() << " " << endl;

	}
}

void startUserMode()
{
	cout << "USER MODE!\n";
}

void UI::initData()
{
	
	/*this->ctrl.addCoatToRepository(1, 34, 20, "beige", 125, 200, "https://cache.net-a-porter.com/images/products/372462/372462_in_pp.jpg");
	this->ctrl.addCoatToRepository(2, 36, 25, "navy blue", 125, 200, "https://static.independent.co.uk/s3fs-public/styles/story_medium/public/thumbnails/image/2015/02/26/16/AN64094637Phase-Eight.jpg");
	this->ctrl.addCoatToRepository(3, 38, 20, "black", 125, 200, "http://media.newlookassets.com/i/newlook/362712101/womens/jackets-and-coats/macs/black-belted-trench-coat-/?$new_pdp_szoom_image_600$");
	this->ctrl.addCoatToRepository(4, 38, 10, "white", 100, 300, "https://s-media-cache-ak0.pinimg.com/736x/91/61/77/916177e8eb0e04f55f5823025ded838a.jpg");
	this->ctrl.addCoatToRepository(5, 40, 10, "red", 200, 200, "https://rainfrog.co.uk/wp-content/uploads/2015/08/Red-Short-Trenchcoat-Petra-1500.jpg");
	this->ctrl.addCoatToRepository(6, 32, 15, "khaki", 100, 150, "https://www.vanessaseward.com/media/catalog/product/cache/4/image/1800x/040ec09b1e35df139433887a97daa66f/apc/imedia/COBOL-V01194_JAA_APLAT_00.jpg");
	this->ctrl.addCoatToRepository(7, 30, 20, "leopard", 400, 50, "http://nord.imgix.net/Zoom/18/_100644518.jpg?fit=fill&bg=FFF&fm=jpg&w=391&h=600&dpr=1.5&q=52.5");
	this->ctrl.addCoatToRepository(8, 34, 10, "burgundy", 450, 80, "https://cdn-images.farfetch-contents.com/11/90/06/39/11900639_8885327_400.jpg");
	this->ctrl.addCoatToRepository(9, 32, 5, "beige", 350, 100, "http://img.mytheresa.com/1088/1088/66/jpeg/catalog/product/83/P00220626.jpg");
	this->ctrl.addCoatToRepository(10, 36, 10, "white", 400, 40, "https://cdn-images.farfetch-contents.com/11/43/71/44/11437144_8384040_400.jpg");
	*/
	}

void UI::startUI()
{
	this->initData();
	while (1)
	{
		printModes();
		int mode = readIntegerNumber("Please enter your option: ");
		if (mode == 0)
			break;
		switch (mode)
		{
		case 1:
		{
			startAdministratorMode();
			break;
		}
		case 2:
		{
			startUserMode();
			break;
		}
		}
	}
}