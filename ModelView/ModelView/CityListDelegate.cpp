#include "CityListDelegate.h"

CityListDelegate::CityListDelegate(QObject *parent)
	: QStyledItemDelegate(parent)
{

}

CityListDelegate::~CityListDelegate()
{

}

void CityListDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	painter->drawText(option.rect.x(), option.rect.y() + 10, index.data().toString());
}
