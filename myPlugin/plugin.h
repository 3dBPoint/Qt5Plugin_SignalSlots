#ifndef PLUGIN_H
#define PLUGIN_H

#include "plugininterface.h"
#include <QWidget>

class Plugin : public PluginInterface
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "my.test.plugin.interface")//导出plugin
	Q_INTERFACES(PluginInterface)
public:
	void SayHello(QWidget *parent) Q_DECL_OVERRIDE;//声明是重写虚函数
};

#endif // PLUGIN_H
