#ifndef CSTUDENTDELEGATE_H
#define CSTUDENTDELEGATE_H

#include <QStyledItemDelegate>

class CStudentDelegate : public QStyledItemDelegate
{
	Q_OBJECT

public:
	CStudentDelegate(QObject *parent = nullptr);
	~CStudentDelegate();

protected:
    // QAbstractItemDelegate interface
    virtual QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    virtual void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    virtual void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // CSTUDENTDELEGATE_H
