#include "QTTester.h"

QTTester::QTTester(Controller& ctrl, const User& u, QWidget *parent) : ctrl(ctrl), u(u), QWidget(parent)
{
	ui.setupUi(this);
	ui.issuesList->setSelectionMode(QAbstractItemView::SingleSelection);
	this->populateIssuesList();
	this->ctrl.addObserver(this);
	QObject::connect(ui.addButton, &QPushButton::clicked, this, &QTTester::on_addbutton_clicked);
	QObject::connect(ui.removeButton, &QPushButton::clicked, this, &QTTester::on_removeButton_clicked);
	QObject::connect(ui.issuesList, &QListWidget::itemSelectionChanged, this, [this]() {this->listItemChanged(); });
}

QTTester::~QTTester()
{
}

void QTTester::on_addbutton_clicked()
{
	std::string text = (ui.descEdit->text().toStdString());
	if (text!="")
		this->ctrl.addIssueCtrl(text,u);
	else
	{
		QMessageBox msgBox;
		msgBox.setText("The description is empty!");
		msgBox.setStandardButtons(QMessageBox::Ok);
		int ret = msgBox.exec();
	}
	this->populateIssuesList();
}

void QTTester::populateIssuesList()
{

	if (ui.issuesList->count() > 0)
		ui.issuesList->clear();

	for (auto i : this->ctrl.getRepo().sortRepo())
	{
		QString itemInList = QString::fromStdString(i.getDescription() + " - " + i.getStatus() + " - " + i.getReporter() + " - " + i.getSolver());
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		ui.issuesList->addItem(item);
	}

	if (this->ctrl.getRepo().sortRepo().size() > 0)
		ui.issuesList->setCurrentRow(0);
}


int QTTester::getSelectedIndex()
{
	if (ui.issuesList->count() == 0)
		return -1;

	QModelIndexList index = ui.issuesList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

void QTTester::update()
{
	this->populateIssuesList();
}

void QTTester::listItemChanged()
{
	int idx = this->getSelectedIndex();
	if (idx == -1)
		return;

	if (idx >= this->ctrl.getRepo().sortRepo().size())
		return;
	Issue i = this->ctrl.getRepo().sortRepo()[idx];

	ui.descEdit->setText(QString::fromStdString(i.getDescription()));

}


void QTTester::on_removeButton_clicked()
{
	int idx = this->getSelectedIndex();
	Issue i = this->ctrl.getRepo().sortRepo()[idx];
	if (i.getStatus() == "Closed")
	{
		this->ctrl.removeIssueCtrl(i);
		this->populateIssuesList();
	}
	else
		this->populateIssuesList();
}

