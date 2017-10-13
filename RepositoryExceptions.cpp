#include "RepositoryExceptions.h"

FileException::FileException(const std::string & msg) : message(msg)
{
}

const char * FileException::what()
{
	return message.c_str();
}

RepositoryException::RepositoryException() : exception{}, message{ "" }
{
}

RepositoryException::RepositoryException(const std::string & msg) : message{ msg }
{
}

const char * RepositoryException::what()
{
	return this->message.c_str();
}

const char * DuplicateTrenchCoatException::what()
{
	return "There is another trench coat with the same ID!";
}

const char * InexistentTrenchCoatException::what()
{
	return "There isn't any trench coat with that ID!";
}