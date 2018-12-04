#ifndef CSTUDENTTABLEMODEL_H
#define CSTUDENTTABLEMODEL_H

#include "CStudent.h"
#include <QAbstractTableModel>
#include <vector>

class CStudentTableModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	CStudentTableModel(QObject *parent = nullptr);
    ~CStudentTableModel();

public:
	// model method
	void insertStudent(const CStudent& stu);
	void removeStudent(QString name);
	void removeAllStudents();
	void modifyStudent(const CStudent& stu);

protected:
    // QAbstractItemModel interface
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual int columnCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const override;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    virtual bool insertRows(int row, int count, const QModelIndex &parent) override;
    virtual bool removeRows(int row, int count, const QModelIndex &parent) override;
    virtual void sort(int column, Qt::SortOrder order) override;

private:
    std::vector<CStudent> m_vectStudent;
};

#endif // CSTUDENTTABLEMODEL_H
