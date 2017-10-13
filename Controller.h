#pragma once
#include "Repository.h"
#include "ShoppingBasket.h"
#include "TrenchCoatValidator.h"
#include "FileShoppingBasket.h"

class Controller
{
private:
	//Repository repo;
	VirtualRepository* repo;
	//ShoppingBasket basket;
	FileShoppingBasket* basket;
	TrenchCoatValidator validator;

public:
	/*Controller(const Repository& r) : repo(r) {}
	Controller(const Repository& r,const TrenchCoatValidator& v) : repo(r),validator(v) {}
	Controller(const Repository& r, FileShoppingBasket* b, const TrenchCoatValidator& v) : repo{ r }, basket{ b }, validator{ v } {}
	*/
	Controller(VirtualRepository* r) : repo(r) {};
	Controller( VirtualRepository* r, FileShoppingBasket* b, const TrenchCoatValidator& v) : repo{ r }, basket{ b }, validator{ v } {}

	VirtualRepository* getRepo() { return repo; };
	//Repository getRepo() { return repo; }
	//ShoppingBasket getShoppingBasket() const { return basket; }
	FileShoppingBasket* getShoppingBasket() const { return basket; }

	/// <summary>
	/// Adds a trench coat with the given data to the repository.
	/// </summary>
	/// <returns> 1 - If the coat was successfully added to the repository, 0 - otherwise.</returns>
	int addCoatToRepository(const int& ID, const double& size, const double&length, const std::string& colour, const double& price, const double& quantity, const std::string& photograph);

	/// <summary>
	/// Deletes a trench coat from the repository.
	/// </summary>
	/// <param name = "c">A coat, of type TrenchCoat.</param>
	/// <returns>1 - If the coat was deleted from the repository, 0 - if the coat could not be deleted, as there isn't any trench coat in the repository with the given ID.</returns>
	int deleteCoatFromRepository(const int& ID);

	/// <summary>
	/// Updates a trench coat from the repository.
	/// </summary>
	/// <param name = "c">A coat, of type TrenchCoat.</param>
	/// <returns>1 - If the coat was updated from the repository, 0 - if the coat could not be updated, as there isn't any trench coat in the repository with the given ID.</returns>
	int updateCoatFromRepository(const int& ID, const double& size, const double&length, const std::string& colour, const double& price, const double& quantity, const std::string& photograph);

	//DynamicVector& sortByPrice(DynamicVector& trenchCoats);

	/// <summary>
	/// Sorts a given vector of trench coats, ascendingly by price.
	/// </summary>
	/// <param name = "trenchCoats">A vector of trench coats.</param>
	/// <returns>The vector of trench coats sorted</returns>
	std::vector<TrenchCoat>& sortByPrice(std::vector<TrenchCoat>& trenchCoats);

	/// <summary>
	/// Returns a vector of trench coats having a given size.
	/// </summary>
	/// <param name = "length">A double, representing the size to search for.</param>
	/// <returns>A vector of trench coats having the given size.</returns>
	std::vector<TrenchCoat> listTrenchCoatsWithSizeCtrl(const double& size);

	/// <summary>
	/// Returns a vector of trench coats with length smaller than a given one.
	/// </summary>
	/// <param name = "length">A double, representing the length to search for.</param>
	/// <returns>A vector of trench coats with length smaller than the given one.</returns>
	std::vector<TrenchCoat> listTrenchCoatsWithLengthSmallerThanCtrl(const double& length);

	/// <summary>
	/// Adds a trench coat to the shopping basket.
	/// </summary>
	/// <param name = "c">A trench coat, of type TrenchCoat.</param>
	/// <returns>The trench coat is added to the shopping basket.</returns>
	void addCoatToShoppingBasketCtrl(const TrenchCoat& c);

	void Controller::startShoppingBasket();
	void Controller::nextTrenchCoatsShoppingBasket();

	/*
	Saves the shopping basket.
	Throws: FileException - if the given file cannot be opened.
	*/
	void saveShoppingBasket(const std::string& filename);

	/*
	Opens the shopping basket, with an appropriate application.
	Throws: FileException - if the given file cannot be opened.
	*/
	void openShoppingBasket() const;
};