#pragma once
#include "TrenchCoat.h"
#include <vector>
#include "VirtualRepository.h"

class Repository:public VirtualRepository
{
protected:
	std::vector <TrenchCoat> trenchCoats;
	//std::string filename;

public:
	/// <summary>
	/// Default constructor. Initializes an object of type repository.
	/// </summary>
	Repository() {};

	/// <summary>
	/// Contructor with parameters. Initializes an object of type repository, by reading data from the given file.
	/// </summary>
	/// <param name = "filename">A filename, of type string, the file from which the entities will be read.</param>
	/// <returns> FileException - if the file cannot be opened..</returns>
	//Repository(const std::string& filename);

	/// <summary>
	/// Adds a trench coat to the repository.
	/// </summary>
	/// <param name = "c">A coat, of type TrenchCoat.</param>
	/// <returns>1 - If the coat was added to the repository, 0 - if a coat with the same id already exists and therefore it cannot be added.</returns>
	int addCoat(const TrenchCoat& c);


	/// <summary>
	/// Deletes a trench coat from the repository.
	/// </summary>
	/// <param name = "c">A coat, of type TrenchCoat.</param>
	/// <returns>1 - If the coat was deleted from the repository, 0 - if the coat could not be deleted, as there isn't any trench coat in the repository with the given ID.</returns>
	int deleteCoat(const TrenchCoat& c);

	/// <summary>
	/// Updates a trench coat from the repository.
	/// </summary>
	/// <param name = "c">A coat, of type TrenchCoat.</param>
	/// <returns>1 - If the coat was updated from the repository, 0 - if the coat could not be updated, as there isn't any trench coat in the repository with the given ID.</returns>
	int updateCoat(const TrenchCoat& c);

	/// <summary>
	/// Returns the position of the trench coat in the repository.
	/// </summary>
	/// <param name = "ID">An ID, of type of integer.</param>
	/// <returns>-1 - If the repository is empty, or there is no coat with the given ID in the repository, i - the position of the coat with the given ID in the repository.</returns>
	int findPositionByID(const int& ID);

	//TrenchCoat findByPosition(const int& pos);


	TrenchCoat findByID(const int& ID);

	int updateCoatRef(const TrenchCoat& c);

	TrenchCoat& findByIDRef(const int&ID);

	std::vector <TrenchCoat> getCoats()  { return trenchCoats; }
/*private:
	void readFromFile();
	void writeToFile();*/
};

//void testRepository();