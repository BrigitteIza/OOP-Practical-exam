#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PracticalExam.h"
#include "Controller.h"

class PracticalExam : public QMainWindow
{
	Q_OBJECT

public:
	PracticalExam(Controller& ctrl, QWidget *parent = Q_NULLPTR);

private:
	Ui::PracticalExamClass ui;
	Controller& ctrl;
};

