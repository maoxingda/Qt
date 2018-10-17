#ifndef MODELVIEW_H
#define MODELVIEW_H

#include <QtGui/QWidget>
#include "ui_modelview.h"
#include "CityListModel.h"

class ModelView : public QWidget
{
	Q_OBJECT

public:
	ModelView(QWidget *parent = 0, Qt::WFlags flags = 0);
	~ModelView();

private slots:
	void on_pushButtonAdd_clicked();
	void on_pushButtonDel_clicked();
	void on_pushButtonDelAll_clicked();

private:
	Ui::ModelViewClass ui;
	CityListModel* m_cityListModel;
};

#endif // MODELVIEW_H
