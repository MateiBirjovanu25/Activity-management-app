#pragma once
#include "service.h"
#include "program.h"
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


class GUI : public QWidget
{
public:
	GUI(ServActiv& servo2 ) :servo{servo2} {
		init();
		loadData(servo.getActivitati());
		initConnect();
	}
private:
	QListWidget* list = new QListWidget;
	QTableWidget* tab = new QTableWidget;

	QPushButton* adauga = new QPushButton{"add"};
	QPushButton* sterge = new QPushButton{"delete"};
	QPushButton* actualizeaza = new QPushButton{"update"};
	QPushButton* undo = new QPushButton{"undo"};

	QPushButton* btnProg = new QPushButton{"program"};


	QPushButton* filtruDesc = new QPushButton{"filtru descriere"};
	QPushButton* filtruTip = new QPushButton{"filtru tip"};

	QPushButton* sortDesc = new QPushButton{ "sortare descriere" };
	QPushButton* sortTip = new QPushButton{ "sortare tip + durata" };

	QPushButton* refresh = new QPushButton{ "refresh" };


	QLineEdit* tipTxt = new QLineEdit;
	QLineEdit* titluTxt = new QLineEdit;
	QLineEdit* descriereTxt = new QLineEdit;
	QLineEdit* durataTxt = new QLineEdit;

	void init();
	void loadData(std::vector<Activitate>);
	void initConnect();
	ServActiv& servo;
};