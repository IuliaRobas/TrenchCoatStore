#pragma once
#include "FileShoppingBasket.h"

class HTMLShoppingBasket :public FileShoppingBasket
{
public:
	/*
	Writes the shopping basket to file.
	Throws: FileException - if it cannot write to file.
	*/
	void writeToFile() override;

	/*
	Displays the playlist using Notepad.
	*/
	void displayShoppingBasket() const override;
};