#include "PracticalExam.h"
#include "QTIssue.h"
#include <QtWidgets/QApplication>
#include "Controller.h"
#include "QTTester.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	IssueRepository repo{ "Users.txt","Issues.txt" };
	Controller ctrl{ repo };
	repo.test();
	std::vector<User> temp = ctrl.getRepo().getUsers();
	for (auto u : temp)
	{
		if (u.getType() == "Programmer")
		{
			QTIssue* q = new QTIssue{ ctrl,u };
			q->setWindowTitle(QString::fromStdString(u.getName()) + " " + QString::fromStdString(u.getType()));
			q->show();
		}
		else
		{
			QTTester* q = new QTTester{ ctrl,u };
			q->setWindowTitle(QString::fromStdString(u.getName()) + " " + QString::fromStdString(u.getType()));
			q->show();
		}
	}

	return a.exec();
}
