#include "IssueRepository.h"
#include <algorithm>

void IssueRepository::readFromFileU()
{
	ifstream file(this->filenameU);

	User u;
	while (file >> u)
		this->users.push_back(u);

	file.close();
}

void IssueRepository::readFromFileI()
{
	ifstream file(this->filenameI);

	Issue i;
	while (file >> i)
		this->issues.push_back(i);

	file.close();
}


IssueRepository::IssueRepository()
{
	this->users = {};
	this->issues = {};
	this->filenameU = "";
	this->filenameI = "";
}

IssueRepository::IssueRepository(const std::string & f1, const std::string & f2)
{
	this->filenameU = f1;
	this->filenameI = f2;

	this->readFromFileU();
	this->readFromFileI();
}

void IssueRepository::addIssue(const Issue& i)
{
	this->issues.push_back(i);
	this->notify();
}

void IssueRepository::addUser(const User& u)
{
	this->users.push_back(u);
}


void IssueRepository::removeIssue(const Issue& i)
{
	auto it = std::find(this->issues.begin(), this->issues.end(), i);
	if (it == this->issues.end())
	{
	}
	else
	{
		auto index = std::distance(this->issues.begin(), it);
		this->issues.erase(this->issues.begin() + (index));
	}
	this->notify();
}

bool IssueRepository::wayToSort(const Issue& i1, const Issue& i2)
{
	if (i1.getStatus() < i2.getStatus())
		return true;
	else
		if (i1.getStatus() == i2.getStatus())
			if (i1.getDescription() < i2.getDescription())
				return true;
			else
				return false;
		else
			return false;
}

void IssueRepository::resolve(int issueIdx, User u)
{
	if (issueIdx < 0 || issueIdx >= this->issues.size())
		return;
	Issue& currentIssue = this->issues[issueIdx];
	currentIssue.setStatus();
	currentIssue.setSolver(u.getName());
	this->notify();
	
}

std::vector<Issue> IssueRepository::sortRepo()
{
	std::vector<Issue> res = this->issues;
	std::sort(res.begin(), res.end(), wayToSort);
	return res;
}

void IssueRepository::writeToFile()
{
	ofstream file(this->filenameI);

	for (auto i : this->issues)
	{
		file << i;
	}

	file.close();
}

void IssueRepository::test()
{
	Issue i{ "Lala","Closed","Anca","Maria" };
	IssueRepository repo{};
	repo.addIssue(i);
	assert(repo.getIssues().size() == 1);
	repo.removeIssue(i);
	assert(repo.getIssues().size() == 0);
	Issue i2{ "Lala","Open","Anca","" };
	User u{ "Monica","Programmer" };
	repo.addIssue(i2);
	repo.addUser(u);
	repo.resolve(0, u);
	assert(repo.getIssues()[0].getStatus()=="Closed");
	assert(repo.getIssues()[0].getSolver() == "Monica");
}