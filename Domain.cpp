#include "Domain.h"

using namespace std;

User::User()
{
	this->name = "";
	this->type = " ";
}

User::User(const std::string & name, const std::string & type)
{
	this->name = name;
	this->type = type;
}

std::ostream & operator<<(std::ostream & os, const User & u)
{
	os << u.name << " - " << u.type << "\n";
	return os;
}

std::vector<std::string> split(std::string data, char delimiter)
{
	std::vector<std::string> splitString;
	std::stringstream strStream(data);
	std::string token;

	while (getline(strStream, token, delimiter))
		splitString.push_back(token);
	return splitString;
}

std::istream & operator>>(std::istream& input, User& u)
{
	std::string data;

	getline(input, data);

	std::vector<std::string> dataSplit = split(data, ',');

	if (dataSplit.size() == 2) {
		u.name = dataSplit[0];
		u.type = dataSplit[1];
	}

	return input;
}

Issue::Issue()
{
	this->description = " ";
	this->status = "Open";
	this->reporter = " ";
	this->solver = " ";
}

Issue::Issue(const std::string & desc, const std::string & status, const std::string & reporter, const std::string & solver)
{
	this->description = desc;
	this->status = status;
	this->reporter = reporter;
	this->solver = solver;
}

bool Issue::operator==(const Issue & i)
{
	if (i.getDescription() == this->description)
		return true;
	else
		return false;
}

void Issue::setReporter(const std::string & rep)
{
	this->reporter = rep;
}

void Issue::setDescription(const std::string & desc)
{
	this->description = desc;
}

void Issue::setStatus()
{
	this->status = "Closed";
}

void Issue::setSolver(const std::string & sol)
{
	this->solver = sol;
}

std::ostream & operator<<(std::ostream & os, const Issue & i)
{
	os << i.description << "," << i.status << "," << i.reporter << "," << i.solver << "\n";
	return os;
}

std::istream & operator>>(std::istream& input, Issue& i)
{
	std::string data;

	getline(input, data);

	std::vector<std::string> dataSplit = split(data, ',');

	if (dataSplit.size() == 4) {
		i.description = dataSplit[0];
		i.status = dataSplit[1];
		i.reporter = dataSplit[2];
		i.solver = dataSplit[3];
	}

	return input;
}
