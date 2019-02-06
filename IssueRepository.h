#pragma once
#include "Domain.h"
#include <vector>
#include <fstream>
#include "Observer.h"
#include <assert.h>

using namespace std;

class IssueRepository: public Observable
{
private:
	std::vector<User> users;
	std::vector<Issue> issues;
	std::string filenameU;
	std::string filenameI;

	void readFromFileU();
	void readFromFileI();

public:
	IssueRepository();
	IssueRepository(const std::string& f1, const std::string& f2);
	~IssueRepository() {};

	std::vector<User> getUsers() const { return users; }
	std::vector<Issue> getIssues() const { return issues; }

	void writeToFile();
	void addIssue(const Issue & i);
	void addUser(const User & u);
	//Description: This function adds an object of type Issue to the issues repository
	//Pre: i - an object of type Issue
	//Post: it adds an issue to the Issues repository

	void removeIssue(const Issue & i);
	//Description: This function removes an object of type Issue from the issues repository
	//Pre: i - an object of type Issue
	//Post: it removes an issue from the Issues repository

	static bool wayToSort(const Issue & i1, const Issue & i2);
	void resolve(int issueIdx, User u);
	//Description: This function "resolves" an issue, it sets its solver and status to the name of the user and closed
	//Pre: issueIdx - the position of the issue in the repository and u - the object of type user which solved the issue
	//Post: The function sets the status of the issue to closed and the solver of the issue to the name of the given user

	std::vector<Issue> sortRepo();
	void test();
};