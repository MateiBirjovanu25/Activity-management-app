#pragma once
#include "service.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qtablewidget.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qcombobox.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets\qformlayout.h>
#include <QtWidgets\qgridlayout.h>
#include <QtWidgets/qmessagebox.h>
#include <qpalette.h>


class Prog : public QWidget {
public:
	Prog(ServActiv& servo2) : servo{ servo2 } {
		init();
		loadData(servo.getList());
		initConnect();
	}
private:
	QLineEdit* titlu = new QLineEdit;
	QLineEdit* tip = new QLineEdit;
	QLineEdit* nrGen = new QLineEdit;
	QLineEdit* numeFis = new QLineEdit;

	QPushButton* btnAdaugare = new QPushButton{ "adauga" };
	QPushButton* btnGolire = new QPushButton{ "goleste" };
	QPushButton* btnGenereaza = new QPushButton{ "genereaza" };
	QPushButton* btnExport = new QPushButton{ "export" };

	QListWidget* lista = new QListWidget;



	void init();
	void loadData(std::vector<Activitate>);
	void initConnect();
	ServActiv& servo;
};