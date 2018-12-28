#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPluginLoader>
#include "plugininterface.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
	Q_OBJECT

public:
	explicit Widget(QWidget *parent = 0);
	~Widget();

private slots:
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();
	void onDoSomething();

	void on_pushButton_3_clicked();

signals:
	void saySomething(QWidget *);

private:
	Ui::Widget *ui;
	PluginInterface *interface = nullptr;
	QPluginLoader pluginLoader;
};

#endif // WIDGET_H
