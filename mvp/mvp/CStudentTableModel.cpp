#include "CStudentTableModel.h"
#include "CStudent.h"
#include <QIcon>
#include <algorithm>

CStudentTableModel::CStudentTableModel(QObject *parent)
	: QAbstractTableModel(parent)
{
	CStudent stu1, stu2, stu3;
	stu1.name = QString::fromLocal8Bit("柳华丽");
	stu1.phoneNumber = QString::fromLocal8Bit("18001289141");
	stu2.name = QString::fromLocal8Bit("李昱良");
	stu2.phoneNumber = QString::fromLocal8Bit("18001289142");
	stu3.name = QString::fromLocal8Bit("杨春海");
	stu3.phoneNumber = QString::fromLocal8Bit("18001289143");
	m_vectStudent.push_back(stu1);
	m_vectStudent.push_back(stu2);
	m_vectStudent.push_back(stu3);
	std::sort(m_vectStudent.begin(), m_vectStudent.end());
	//for (auto i = 0; i < 10000; ++i)
	//{
	//	m_vectStudent.push_back(stu1);
	//	m_vectStudent.push_back(stu2);
	//	m_vectStudent.push_back(stu3);
    //}
	//std::sort(m_vectStudent.begin(), m_vectStudent.end());
}

CStudentTableModel::~CStudentTableModel()
{

}

void CStudentTableModel::insertStudent(const CStudent& stu)
{
	auto iter = std::lower_bound(m_vectStudent.begin(), m_vectStudent.end(), stu);
	m_vectStudent.insert(iter, stu);
	iter = std::lower_bound(m_vectStudent.begin(), m_vectStudent.end(), stu);
	insertRow(iter - m_vectStudent.begin());
}

void CStudentTableModel::removeStudent(QString name)
{
	auto iter = std::find(m_vectStudent.begin(), m_vectStudent.end(), name);

	if (m_vectStudent.end() != iter)
	{
		removeRow(iter - m_vectStudent.begin());

		m_vectStudent.erase(iter);
	}
}

void CStudentTableModel::removeAllStudents()
{
	//m_vectStudent.clear();
	//emit layoutChanged();

	if (!m_vectStudent.empty())
	{
		removeRows(0, m_vectStudent.size(), QModelIndex());
		m_vectStudent.clear();
	}
}

void CStudentTableModel::modifyStudent(const CStudent& stu)
{
	auto iter = std::find(m_vectStudent.begin(), m_vectStudent.end(), stu.name);

	if (m_vectStudent.end() != iter)
	{
		*iter = stu;

		int row = iter - m_vectStudent.begin();

		emit dataChanged(index(row, 0), index(row, columnCount(QModelIndex())));

		//emit layoutChanged();
	}
}

int CStudentTableModel::rowCount(const QModelIndex &parent) const
{
	return m_vectStudent.size();
}

int CStudentTableModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant CStudentTableModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid() || index.row() >= m_vectStudent.size())
	{
		return QVariant();
	}

	if (Qt::TextAlignmentRole == role)
	{
		return QVariant(Qt::AlignCenter);
	}
    else if (Qt::DisplayRole == role || Qt::EditRole == role || Qt::ToolTipRole == role)
	{
		if (0 == index.column())
		{
			return QVariant(m_vectStudent[index.row()].name);
		}
		else if (1 == index.column())
		{
			return QVariant(m_vectStudent[index.row()].phoneNumber);
		}
	}
    else if (Qt::DecorationRole == role)
    {
		if (0 == index.column())
		{
			return QIcon(":/skins/ico/ringtones.ico");
		}
		else if (1 == index.column())
		{
			return QIcon(":/skins/png/phone.png");
		}
    }

	return QVariant();
}

QVariant CStudentTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (Qt::DisplayRole != role || Qt::Vertical == orientation)
	{
		return QVariant();
	}

	//if (Qt::Vertical == orientation)
	//{
	//	return QVariant(QString::number(section + 1));
	//}

	switch (section)
	{
	case 0:
		return QVariant(QString::fromLocal8Bit("姓名"));
		break;

	case 1:
		return QVariant(QString::fromLocal8Bit("电话"));
		break;

	default:
		return QVariant();
	}
}

Qt::ItemFlags CStudentTableModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
	{
		return Qt::NoItemFlags;
	}

	return __super::flags(index) | Qt::ItemIsEditable;
}


bool CStudentTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (!index.isValid() || !value.isValid() || Qt::EditRole != role)
	{
		return false;
	}

	if (0 == index.column())
	{
		m_vectStudent[index.row()].name = value.toString();
	}
	else if (1 == index.column())
	{
		m_vectStudent[index.row()].phoneNumber = value.toString();
	}

	emit dataChanged(index, index);

	return true;
}


bool CStudentTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
	beginInsertRows(parent, row, row + count - 1);
	endInsertRows();

	return true;
}

bool CStudentTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
	beginRemoveRows(parent, row, row + count - 1);
	endRemoveRows();

	return true;
}


void CStudentTableModel::sort(int column, Qt::SortOrder order)
{
    if (0 == column)
    {
		CStudent::sortFlag = 1;
    }
    else if (1 == column)
    {
		CStudent::sortFlag = 2;
    }

	if (Qt::AscendingOrder == order)
	{
		std::sort(m_vectStudent.begin(), m_vectStudent.end());
	}
	else if (Qt::DescendingOrder == order)
	{
		std::sort(m_vectStudent.rbegin(), m_vectStudent.rend());
	}

	emit dataChanged(index(0, 0), index(m_vectStudent.size() - 1, 1));
}
