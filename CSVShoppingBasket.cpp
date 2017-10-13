#include "CSVShoppingBasket.h"
#include <fstream>
#include <Windows.h>
#include "RepositoryExceptions.h"

using namespace std;

void CSVShoppingBasket::writeToFile()
{
	ofstream f(this->filename);

	if (!f.is_open())
		throw FileException("The file could not be opened!");

	for (auto s : this->trenchCoats)
		f << s;

	f.close();
}

void CSVShoppingBasket::displayShoppingBasket() const
{
	string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations
											   //ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\OpenOffice 4\\program\\scalc.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	ShellExecuteA(NULL, NULL, "C:\\Users\\Utilizator\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Accessories\\Notepad.lnk", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
