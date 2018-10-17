#include "CityListModel.h"
#include <set>

CityListModel::CityListModel(QObject *parent)
	: QAbstractListModel(parent)
{
	//m_vectCitys.push_back(QString::fromLocal8Bit("北京"));
	//m_vectCitys.push_back(QString::fromLocal8Bit("上海"));
	//m_vectCitys.push_back(QString::fromLocal8Bit("天津"));
	m_vectCitys.push_back(QString::fromLocal8Bit("3"));
	m_vectCitys.push_back(QString::fromLocal8Bit("1"));
	m_vectCitys.push_back(QString::fromLocal8Bit("2"));
}

CityListModel::~CityListModel()
{

}

int CityListModel::rowCount(const QModelIndex &parent /*= QModelIndex() */) const
{
	if (parent.isValid())
	{
		return 0;
	}

	return m_vectCitys.size();
}

QVariant CityListModel::data(const QModelIndex &index, int role /*= Qt::DisplayRole*/) const
{
	if (index.isValid())
	{
		int row = index.row();

		if (Qt::DisplayRole == role /*|| Qt::EditRole == role */&& row < m_vectCitys.size())
		{
			return m_vectCitys.at(row);
		}
	}

	return QVariant();
}

//bool CityListModel::setData(const QModelIndex &index, const QVariant &value, int role /*= Qt::EditRole*/)
//{
//	if (index.isValid() && role == Qt::EditRole)
//	{
//		m_vectCitys[index.row()] = value.toString();
//
//		emit dataChanged(index, index);
//
//		return true;
//	}
//
//	return false;
//}

bool CityListModel::insertRows(int row, int count, const QModelIndex &parent /*= QModelIndex() */)
{
	beginInsertRows(parent, row, row + count - 1);
	endInsertRows();

	return true;
}

bool CityListModel::removeRows(int row, int count, const QModelIndex &parent /*= QModelIndex() */)
{
	beginRemoveRows(parent, row, row + count - 1);
	endRemoveRows();

	return true;
}

Qt::ItemFlags CityListModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
	{
		return Qt::ItemIsEnabled;
	}

	return __super::flags(index)/* | Qt::ItemIsEditable*/;
}

void CityListModel::insertCity(QString city)
{
	m_vectCitys.push_back(city);
	insertRow(rowCount());
}

void CityListModel::removeCity()
{
	int rowCount = this->rowCount();

	if (rowCount)
	{
		m_vectCitys.erase(m_vectCitys.begin() + rowCount - 1);
		removeRow(rowCount - 1);
	}
}

void CityListModel::removeAllCitys()
{
	//std::swap(m_vectCitys[0], m_vectCitys[2]);
	//while (!m_vectCitys.empty())
	//{
	//	removeCity();
	//}
}
