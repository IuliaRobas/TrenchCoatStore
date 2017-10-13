#pragma once
#include "Repository.h"
#include <fstream>
#include "RepositoryExceptions.h"
using namespace std;
class RepositoryFile : public Repository
{
protected:
	std::string filename;

public:
	RepositoryFile(std::string f) :filename(f) { readFromFile(); };
	virtual ~RepositoryFile() {};

	virtual int addCoat(const TrenchCoat& c) override;
	virtual int deleteCoat(const TrenchCoat& c) override;
	virtual int updateCoat(const TrenchCoat& c) override;
	virtual int findPositionByID(const int& ID) override;
	//TrenchCoat findByPosition(const int& pos) override;
	virtual TrenchCoat findByID(const int& ID) override;
	virtual int updateCoatRef(const TrenchCoat& c) override;
	virtual TrenchCoat& findByIDRef(const int&ID) override;
	virtual std::vector <TrenchCoat> getCoats()  override;

	void setFilename(const std::string& filename);
private:
	void writeToFile() ;
	void readFromFile();
	//void displayRepository() ;
};
