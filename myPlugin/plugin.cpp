#include "plugin.h"
#include "QMessageBox"

void Plugin::SayHello(QWidget *parent)
{
	QMessageBox::information(parent, "myPlugin", "my plugin saied hello, and will call signal \"doSomething\"");
	emit doSomething();
}
