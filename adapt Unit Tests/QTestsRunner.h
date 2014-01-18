#pragma once
#include "gtest/gtest.h"
#include <QtCore>
#include <QObject>

class QTestsRunner : public QObject
{
	Q_OBJECT
public:
	QTestsRunner(QObject *parent = 0) : QObject(parent) {}

	public slots:
		void run() {
			RUN_ALL_TESTS();
			emit finished();
		}

signals:
		void finished();
};
