#pragma once
#include "service.h"
#include "program.h"
#include "readonlygui.h"
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
#include "observer.h"

class GUI : public QWidget,public Observer
{
public:
	GUI(ServActiv& servo2 ) :servo{servo2} {
		init();
		loadData(servo.getActivitati());
		initConnect();
	}
	void update() override;
private:
	QListWidget* list = new QListWidget;
	QTableWidget* tab = new QTableWidget;

	QPushButton* adauga = new QPushButton{"add"};
	QPushButton* sterge = new QPushButton{"delete"};
	QPushButton* actualizeaza = new QPushButton{"update"};
	QPushButton* undo = new QPushButton{"undo"};

	QPushButton* btnProg = new QPushButton{"program"};

	QPushButton* btnReadOnly = new QPushButton{"histograma"};


	QPushButton* filtruDesc = new QPushButton{"filtru descriere"};
	QPushButton* filtruTip = new QPushButton{"filtru tip"};

	QPushButton* sortDesc = new QPushButton{ "sortare descriere" };
	QPushButton* sortTip = new QPushButton{ "sortare tip + durata" };

	QPushButton* refresh = new QPushButton{ "refresh" };

	QPushButton* btnAddCos = new QPushButton{ "adauga in cos" };
	QPushButton* btnGenCos = new QPushButton{ "generare cos" };
	QPushButton* btnDelCos = new QPushButton{ "golire cos" };



	QLineEdit* tipTxt = new QLineEdit;
	QLineEdit* titluTxt = new QLineEdit;
	QLineEdit* descriereTxt = new QLineEdit;
	QLineEdit* durataTxt = new QLineEdit;


	QLineEdit* nrGen = new QLineEdit;

	void init();
	void loadData(std::vector<Activitate>);
	void initConnect();
	ServActiv& servo;
};