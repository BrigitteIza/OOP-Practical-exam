#pragma once

#include <QWidget>
#include "ui_QTTester.h"
#include "Controller.h"
#include <qmessagebox.h>

class QTTester : public QWidget, public Observer
{
	Q_OBJECT

public:
	QTTester(Controller& ctrl, const User& u,QWidget *parent = Q_NULLPTR);
	~QTTester();

	void on_addbutton_clicked();

	void populateIssuesList();

	int getSelectedIndex();
	void update() override;
	void listItemChanged();

	void on_removeButton_clicked();

private:
	Ui::QTTester ui;
	Controller& ctrl;
	User u;
};
