#include "Controller.h"

Controller::Controller()
{
}

void Controller::addIssueCtrl(const std::string & desc, const User& u)
{
	
	try {
		Issue i;
		i.setReporter(u.getName());
		i.setDescription(desc);
		this->repo.addIssue(i);
	}
	catch (InvalidException& e)
	{
		e.what();
	}
}

void Controller::addObserver(Observer * newObserver) 
{
	this->repo.addObserver(newObserver);
	this->repo.writeToFile();
}

void Controller::removeIssueCtrl(const Issue & i)
{
	this->repo.removeIssue(i);
	this->repo.writeToFile();
}

void Controller::resolveIssue(int issueIdx,User u)
{
	this->repo.resolve(issueIdx,u);
	this->repo.writeToFile();
}
