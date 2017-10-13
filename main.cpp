#include <cstdlib>
#include <iostream>
#include <cstdio>
#include "UI.h"
#include <string>
#include "ShoppingBasket.h"
#include "Tests.h"
#include <crtdbg.h>
#include "RepositoryExceptions.h"
#include "CSVShoppingBasket.h"
#include "HTMLShoppingBasket.h"
#include "RepositoryFile.h"

//#include "FileRepository.h"

using namespace std;

int main()
{
	
	//Tests::testAll();

	//testDynamicVector(); 	
	//testTrenchCoat(); 
	//testRepository();
	//testDynamicVectorT<TrenchCoat>();
	//testShoppingBasket();


	/*
	Repository repo{};
	Controller ctrl{ repo };
	UI ui{ ctrl };
	ui.startUI();

	_CrtDumpMemoryLeaks();
	*/
	try
	{

		//Repository repo{ "Coats.txt" };	
		
		VirtualRepository* repo = new RepositoryFile{ "Coats.txt" };
		//FileShoppingBasket* HTMLbasket = new HTMLShoppingBasket{};
		cout << "\n**********************************************************";
		cout << "\nSHOPPING BASKET FILE STORAGE OPTIONS.\n";
		cout << "1 - CSV file.\n";
		cout << "2 - HTML file.\n";
		cout << "0 - Exit.\n";
		cout << "**********************************************************\n";
		int option = UI::readIntegerNumber("Please enter your option: ");
		if (option == 0)
			return 0;
		switch (option)
		{
		case 1:
		{
			FileShoppingBasket* CSVbasket = new CSVShoppingBasket{};
			Controller ctrl{ repo ,CSVbasket,TrenchCoatValidator {} };
			UI ui{ ctrl };
			ui.startUI();
		}
		case 2:
		{
			FileShoppingBasket* HTMLbasket = new HTMLShoppingBasket{};
			Controller ctrl{ repo ,HTMLbasket,TrenchCoatValidator{} };
			UI ui{ ctrl };
			ui.startUI();
		}
		}
		
	}
	catch (FileException& e)
	{
		cout << "Repository file could not be opened! The application will terminate." << endl;
		return 1;
	}

	
	return 0;
}


