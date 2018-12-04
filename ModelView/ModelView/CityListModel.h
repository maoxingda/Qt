#ifndef CITYLISTMODEL_H
#define CITYLISTMODEL_H

#include <QAbstractListModel>
#include <vector>

class CityListModel : public QAbstractListModel
{
	Q_OBJECT

public:
	CityListModel(QObject *parent);
	~CityListModel();


	virtual int rowCount(const QModelIndex &parent = QModelIndex() ) const;


	virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;


	virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);


	virtual bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex() );


	virtual bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex() );


	virtual Qt::ItemFlags flags(const QModelIndex &index) const;

	void insertCity(QString city);

	void removeCity();

	void removeAllCitys();

public:
	std::vector<QString> m_vectCitys;
};

#endif // CITYLISTMODEL_H
