#pragma once
#include "IssueRepository.h"
#include "RepositoryException.h"

class Controller
{
private:
	IssueRepository repo;

public:
	Controller();
	Controller(const IssueRepository& r) : repo{ r } {};
	~Controller() {};

	IssueRepository getRepo() const { return repo; }
	void addIssueCtrl(const std::string& desc, const User& u);
	void addObserver(Observer * newObserver);
	void removeIssueCtrl(const Issue& i);
	void resolveIssue(int issueIdx,User u);
};
