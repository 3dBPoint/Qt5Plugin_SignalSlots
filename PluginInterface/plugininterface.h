#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H

#include "plugininterface_global.h"
#include <QObject>

class PLUGININTERFACESHARED_EXPORT PluginInterface : public QObject
{
	Q_OBJECT

public:
	virtual ~PluginInterface() {}

public slots:
	virtual void SayHello(QWidget *parent) = 0;

signals:
	void doSomething();
};

#define InterfaceIID "interface"
Q_DECLARE_INTERFACE(PluginInterface, InterfaceIID)

#endif // PLUGININTERFACE_H
