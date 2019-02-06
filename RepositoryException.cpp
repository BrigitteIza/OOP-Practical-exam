#include "RepositoryException.h"

InvalidException::InvalidException(std::string message) {
	this->message = message;
}

const char* InvalidException::what() {
	return this->message.c_str();
}
