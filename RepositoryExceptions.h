#pragma once
#include <exception>
#include <string>

class FileException : public std::exception
{
protected:
	std::string message;

public:
	FileException(const std::string& msg);
	virtual const char* what();
};

class RepositoryException : public std::exception
{
protected:
	std::string message;

public:
	RepositoryException();
	RepositoryException(const std::string& msg);
	virtual ~RepositoryException() {}
	virtual const char* what();
};

class DuplicateTrenchCoatException : public RepositoryException
{
	const char* what();
};

class InexistentTrenchCoatException : public RepositoryException
{
	const char* what();
};