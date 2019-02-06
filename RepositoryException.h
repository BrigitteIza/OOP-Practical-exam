
#pragma once
#include <exception>
#include <string>
class InvalidException : public std::exception {

private:
	std::string message;

public:

	InvalidException(std::string message);
	virtual const char* what();
};

