#include "modelview.h"
#include "CityListDelegate.h"


ModelView::ModelView(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
	, m_cityListModel(nullptr)
{
	ui.setupUi(this);
	m_cityListModel = new CityListModel(this);
	ui.listView->setModel(m_cityListModel);
	ui.listView->setItemDelegate(new CityListDelegate(this));
}

ModelView::~ModelView()
{

}

void ModelView::on_pushButtonAdd_clicked()
{
	m_cityListModel->insertCity(QString::fromLocal8Bit("¹óÑô"));
}

void ModelView::on_pushButtonDel_clicked()
{
	m_cityListModel->removeCity();
}

void ModelView::on_pushButtonDelAll_clicked()
{
	m_cityListModel->removeAllCitys();
	ui.listView->viewport()->update();
}
