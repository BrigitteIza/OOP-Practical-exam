#pragma once

#include <QWidget>
#include "ui_QTIssue.h"
#include "Controller.h"
#include <qmessagebox.h>

class QTIssue : public QWidget, public Observer
{
	Q_OBJECT

public:
	QTIssue(Controller& ctrl, const User& u, QWidget *parent = Q_NULLPTR);
	~QTIssue();

	void on_resolvebutton_clicked();

	void populateIssuesList();

	int getSelectedIndex();

	void listItemChanged();
	void update() override;

	void on_removeButton_clicked();

private:
	Ui::QTIssue ui;
	Controller& ctrl;
	User u;
};
