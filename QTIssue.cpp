#include "QTIssue.h"

QTIssue::QTIssue(Controller& ctrl, const User& u, QWidget *parent): ctrl(ctrl), u(u), QWidget(parent)
{
	ui.setupUi(this);
	ui.issuesList->setSelectionMode(QAbstractItemView::SingleSelection);
	this->populateIssuesList();
	QObject::connect(ui.resolveButton, &QPushButton::clicked, this, &QTIssue::on_resolvebutton_clicked);
	QObject::connect(ui.removeButton, &QPushButton::clicked, this, &QTIssue::on_removeButton_clicked);
	QObject::connect(ui.issuesList, &QListWidget::itemSelectionChanged, this, [this]() {this->listItemChanged(); });
	this->ctrl.addObserver(this);
}


QTIssue::~QTIssue()
{
}

void QTIssue::on_resolvebutton_clicked()
{
	int idx = this->getSelectedIndex();
	Issue i = this->ctrl.getRepo().sortRepo()[idx];
	if (i.getStatus() == "Open")
	{
		this->ctrl.resolveIssue(idx, u);
	}
	this->populateIssuesList();
}

void QTIssue::populateIssuesList()
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


int QTIssue::getSelectedIndex()
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

void QTIssue::listItemChanged()
{
	int idx = this->getSelectedIndex();
	if (idx == -1)
		return;

	if (idx >= this->ctrl.getRepo().sortRepo().size())
		return;
	Issue i = this->ctrl.getRepo().sortRepo()[idx];
	
}

void QTIssue::update()
{
	this->populateIssuesList();
}

void QTIssue::on_removeButton_clicked()
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







