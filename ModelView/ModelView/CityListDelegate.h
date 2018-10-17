#ifndef CITYLISTDELEGATE_H
#define CITYLISTDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>

class CityListDelegate : public QStyledItemDelegate
{
	Q_OBJECT

public:
	CityListDelegate(QObject *parent);
	~CityListDelegate();


	virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
	
};

#endif // CITYLISTDELEGATE_H
