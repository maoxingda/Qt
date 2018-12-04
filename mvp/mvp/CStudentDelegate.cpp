#include "CStudentDelegate.h"
#include <QLineEdit>

CStudentDelegate::CStudentDelegate(QObject *parent)
	: QStyledItemDelegate(parent)
{

}

CStudentDelegate::~CStudentDelegate()
{

}


QWidget *CStudentDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	QLineEdit* pLineEditor = new QLineEdit(parent);

	if (nullptr != pLineEditor)
	{
		pLineEditor->setAlignment(Qt::AlignCenter);
	}

	return pLineEditor;
}

void CStudentDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
	QLineEdit* pLineEditor = dynamic_cast<QLineEdit*>(editor);

	if (nullptr != pLineEditor)
	{
		pLineEditor->setText(index.data().toString());
	}
}

void CStudentDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
	QLineEdit* pLineEditor = dynamic_cast<QLineEdit*>(editor);

	if (nullptr != pLineEditor)
	{
		model->setData(index, pLineEditor->text());
	}
}

void CStudentDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	editor->setGeometry(option.rect);
}
