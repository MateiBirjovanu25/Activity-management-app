#include "program.h"

void Prog::init()
{
	setStyleSheet("background-color: 	#d0b998");
	auto lyMain = new QVBoxLayout;
	lyMain->addWidget(lista);
	lista->setStyleSheet("background-color: #54a6bf");

	auto lyLeft = new QFormLayout;
	QWidget* w = new QWidget;
	lyLeft->addRow("", w);
	lyLeft->addRow("titlu", titlu);
	titlu->setStyleSheet("background-color: 	#f0e1cf");
	lyLeft->addRow("", w);
	lyLeft->addRow("tip", tip);
	tip->setStyleSheet("background-color: 	#f0e1cf");
	auto lyRight = new QVBoxLayout;
	lyRight->addWidget(btnAdaugare);
	btnAdaugare->setStyleSheet("background-color: 	#94ceea");
	btnGolire->setStyleSheet("background-color: 	#94ceea");
	lyRight->addWidget(btnGolire);

	auto lyGen = new QHBoxLayout;
	lyGen->addWidget(nrGen);
	nrGen->setStyleSheet("background-color: 	#f0e1cf");
	lyGen->addWidget(btnGenereaza);
	btnGenereaza->setStyleSheet("background-color: 	#94ceea");
	lyRight->addLayout(lyGen);
	
	auto lyExp = new QHBoxLayout;
	lyExp->addWidget(numeFis);
	numeFis->setStyleSheet("background-color: 	#f0e1cf");
	lyExp->addWidget(btnExport);
	btnExport->setStyleSheet("background-color: 	#94ceea");
	lyRight->addLayout(lyExp);
	
	auto lyContent = new QHBoxLayout;

	lyContent->addLayout(lyLeft);
	lyContent->addLayout(lyRight);
	lyMain->addLayout(lyContent);
	setLayout(lyMain);
}

void Prog::loadData(std::vector<Activitate> activitati)
{
	lista->clear();
	for (auto& activ : activitati)
	{
		auto it = new QListWidgetItem{ QString::fromStdString(activ.getTitlu()) };
		it->setData(Qt::UserRole, QString::fromStdString(activ.getTip()));
		lista->addItem(it);
	}
}

void Prog::initConnect()
{
	QObject::connect(btnAdaugare, &QPushButton::clicked, [&]() { // buton adaugare
		try
		{
			servo.adaugareLista(titlu->text().toStdString(), tip->text().toStdString());
		}
		catch (SrcExceptions)
		{
			QMessageBox::information(nullptr, "eroare adaugare", "nu exista");
		}
		catch (ValidException)
		{
			QMessageBox::information(nullptr, "eroare adaugare", "date invalide");
		}
		loadData(servo.getList());
		});

	QObject::connect(btnGolire, &QPushButton::clicked, [&]() { // buton golire
		try
		{
			servo.stergereLista();
		}
		catch (SrcExceptions)
		{
			QMessageBox::information(nullptr, "eroare adaugare", "nu exista activitate");
		}
		loadData(servo.getList());
		});

	QObject::connect(btnGenereaza, &QPushButton::clicked, [&]() { // buton genereaza
		try
		{
			servo.generare(nrGen->text().toInt());
		}
		catch (SrcExceptions)
		{
			QMessageBox::information(nullptr, "eroare adaugare", "eroare");
		}
		loadData(servo.getList());
		});

	QObject::connect(btnExport, &QPushButton::clicked, [&]() { // buton export
		servo.exportare(numeFis->text().toStdString());
		});
}
































