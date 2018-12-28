#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Widget)
{
	ui->setupUi(this);
}

Widget::~Widget()
{
	delete ui;
}

void Widget::on_pushButton_clicked()
{
	if(!interface)
	{
		pluginLoader.setFileName("Plugin.dll");
		QObject *plugin = pluginLoader.instance();
		if(plugin)
		{
			interface = qobject_cast<PluginInterface*>(plugin);//使用多态，将基类指针强制转换成派生类指针，检查能否转换
			if(interface)
			{
				connect(this, &Widget::saySomething, interface, &PluginInterface::SayHello);
				connect(interface, &PluginInterface::doSomething, this, &Widget::onDoSomething);
				QMessageBox::information(this, "info", "plugin loaded");
			}
			else
			{
				QMessageBox::critical(this, "err", "this is not a proper plugin");
				return;
			}
		}
		else
		{
			QMessageBox::critical(this, "err", "could not find any plugin");
			return;
		}
	}
}

void Widget::on_pushButton_2_clicked()
{
	if(interface)
	{
		if (pluginLoader.unload())
		{
			interface = nullptr;
			QMessageBox::information(this,"info","unloaded");
		}
		else
			QMessageBox::critical(this,"err", "unload failed");
	}
}

void Widget::onDoSomething()
{
	QMessageBox::information(this,"App", (QString)__FUNCTION__+" has been called.");
}

void Widget::on_pushButton_3_clicked()
{
	emit saySomething(this);
}
