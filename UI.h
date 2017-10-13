#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;
public:
	UI(const Controller& c) : ctrl(c) {}
	void startUI();
	static int readIntegerNumber(const char* message);
private:

	static void printModes();
	static void printAdministratorOptions();
	static void UI::printUserOptions();
	void UI::printShoppingBasketOptions();

	void startAdministratorMode();
	void startUserMode();
	int UI::ShoppingBasketOption();
	void listTrenchCoatsWithSizeUI();

	void displayAllCoatsRepo();
	void addCoatToRepo();
	void updateCoatFromRepo();
	void listTrenchCoatsLengthSmallerThan();
	void initData();
	void deleteCoatFromRepo();
	void UI::sortAscendinglyByPriceUI();

	void addCoatToShoppingBasket(const TrenchCoat& c);
	

	void UI::displayShoppingBasketUI();

	double UI::readFloatNumber(const char* message);
	

	void saveShoppingBasketToFileUI();
	void seeFileShoppingBasketUI();
	void UI::saveShoppingBasketToFileUI(const std::string fileType);
};


