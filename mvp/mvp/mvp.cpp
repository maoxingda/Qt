#include "mvp.h"
#include "CStudentTableModel.h"
#include "CStudentDelegate.h"
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>


mvp::mvp(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);
    ui.tableView->setSortingEnabled(true);
	ui.tableView->setModel(new CStudentTableModel(ui.tableView));
	ui.tableView->setItemDelegate(new CStudentDelegate(ui.tableView));
	ui.tableView->verticalHeader()->setHidden(true);
//    ui.tableView->horizontalHeader()->setHidden(true);
//    ui.tableView->horizontalHeader()->setSortIndicatorShown(true);
    ui.tableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
}

mvp::~mvp()
{

}

void mvp::on_add_clicked()
{
	CStudentTableModel* pSTM = dynamic_cast<CStudentTableModel*>(ui.tableView->model());

	if (nullptr != pSTM)
	{
		CStudent stu;
		stu.name = ui.lineEditName->text();
		stu.phoneNumber = ui.lineEditPhoneNum->text();

		pSTM->insertStudent(stu);
	}
}

void mvp::on_del_clicked()
{
	CStudentTableModel* pSTM = dynamic_cast<CStudentTableModel*>(ui.tableView->model());

	if (nullptr != pSTM)
	{
		pSTM->removeStudent(ui.lineEditName->text());
	}
}

void mvp::on_delAll_clicked()
{
    CStudentTableModel* pSTM = dynamic_cast<CStudentTableModel*>(ui.tableView->model());

    if (nullptr != pSTM)
    {
        pSTM->removeAllStudents();
    }
}

void mvp::on_modify_clicked()
{
	CStudentTableModel* pSTM = dynamic_cast<CStudentTableModel*>(ui.tableView->model());

	if (nullptr != pSTM)
	{
		CStudent stu;
		stu.name = ui.lineEditName->text();
		stu.phoneNumber = ui.lineEditPhoneNum->text();

		pSTM->modifyStudent(stu);
	}
}
