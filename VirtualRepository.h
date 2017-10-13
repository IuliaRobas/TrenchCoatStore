#pragma once
#include "TrenchCoat.h"
#include <vector>

class VirtualRepository
{

public:
	
	/// <summary>
	/// Adds a trench coat to the repository.
	/// </summary>
	/// <param name = "c">A coat, of type TrenchCoat.</param>
	/// <returns>1 - If the coat was added to the repository, 0 - if a coat with the same id already exists and therefore it cannot be added.</returns>
	virtual int addCoat(const TrenchCoat& c)=0;


	/// <summary>
	/// Deletes a trench coat from the repository.
	/// </summary>
	/// <param name = "c">A coat, of type TrenchCoat.</param>
	/// <returns>1 - If the coat was deleted from the repository, 0 - if the coat could not be deleted, as there isn't any trench coat in the repository with the given ID.</returns>
	virtual int deleteCoat(const TrenchCoat& c)=0;

	/// <summary>
	/// Updates a trench coat from the repository.
	/// </summary>
	/// <param name = "c">A coat, of type TrenchCoat.</param>
	/// <returns>1 - If the coat was updated from the repository, 0 - if the coat could not be updated, as there isn't any trench coat in the repository with the given ID.</returns>
	virtual int updateCoat(const TrenchCoat& c)=0;

	/// <summary>
	/// Returns the position of the trench coat in the repository.
	/// </summary>
	/// <param name = "ID">An ID, of type of integer.</param>
	/// <returns>-1 - If the repository is empty, or there is no coat with the given ID in the repository, i - the position of the coat with the given ID in the repository.</returns>
	virtual int findPositionByID(const int& ID)=0;

	//TrenchCoat findByPosition(const int& pos);


	virtual TrenchCoat findByID(const int& ID)=0;

	virtual int updateCoatRef(const TrenchCoat& c)=0;

	virtual TrenchCoat& findByIDRef(const int&ID)=0;

	virtual std::vector <TrenchCoat> getCoats() = 0;

};