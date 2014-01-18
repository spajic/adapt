#ifndef ADAPT_H
#define ADAPT_H

#include <QtWidgets/QMainWindow>
#include "ui_adapt.h"

class adapt : public QMainWindow
{
	Q_OBJECT

public:
	adapt(QWidget *parent = 0);
	~adapt();

private:
	Ui::adaptClass ui;
};

#endif // ADAPT_H
