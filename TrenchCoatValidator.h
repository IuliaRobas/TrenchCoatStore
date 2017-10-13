#pragma once
#include <string>
#include "TrenchCoat.h"
#include <vector>

class TrenchCoatException
{
private:
	std::vector<std::string>errors;
public:
	TrenchCoatException(std::vector<std::string> _errors);
	std::vector<std::string> getErrors() const;
};

class TrenchCoatValidator
{
public:
	TrenchCoatValidator() {}
	static void validate(const TrenchCoat& c);
};
