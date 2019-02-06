#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

class User
{
private:
	std::string name;
	std::string type;

public:
	User();
	User(const std::string& name, const std::string& type);
	~User() {};
	std::string getName() const { return name; }
	std::string getType() const { return type; }

	friend std::ostream& operator<<(std::ostream& os, const User& u);
	friend std::istream& operator>>(std::istream& is, User& u);
};

class Issue
{
private:
	std::string description, status, reporter, solver;
	//std::string status;
	//std::string reporter;
	//std::string solver;

public:
	Issue();
	Issue(const std::string& desc, const std::string& status, const std::string& reporter, const std::string& solver);
	~Issue() {};
	bool operator==(const Issue& i);
	std::string getDescription() const { return description; }
	std::string getStatus() const { return status; }
	std::string getReporter() const { return reporter; }
	std::string getSolver() const { return solver; }
	void setReporter(const std::string& rep);
	void setDescription(const std::string& desc);
	void setStatus();
	void setSolver(const std::string& sol);

	friend std::ostream& operator<<(std::ostream& os, const Issue& i);
	friend std::istream& operator>>(std::istream& is, Issue& i);
};