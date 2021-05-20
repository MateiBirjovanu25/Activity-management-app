#include "GUI.h"

void GUI::update()
{
	loadData(servo.getActivitati());
}

void GUI::loadData(vector<Activitate> activitati)
{
	list->clear();
	for (auto& activ : activitati)
	{
		auto it = new QListWidgetItem{ QString::fromStdString(activ.getTitlu()) };
		it->setData(Qt::UserRole, QString::fromStdString(activ.getTip()));
		list->addItem(it);
	}


	tab->clear();
	for (int k = 0;k < 4;k++)
		tab->insertColumn(k);


	tab->insertRow(0);
	auto it = new QTableWidgetItem{ "TITLU" };
	tab->setItem(0, 0, it);
	auto it2 = new QTableWidgetItem{ "TIP" };
	tab->setItem(0, 1, it2);
	auto it3 = new QTableWidgetItem{ "DESCRIERE" };
	tab->setItem(0, 2, it3);
	auto it4 = new QTableWidgetItem{ "DURATA" };
	tab->setItem(0, 3, it4);

	
	int i = 1;
	for (auto& activ :activitati )
	{
		tab->insertRow(i);
		auto titlu = new QTableWidgetItem{ QString::fromStdString(activ.getTitlu()) };
		auto tip = new QTableWidgetItem{ QString::fromStdString(activ.getTip()) };
		auto descriere = new QTableWidgetItem{ QString::fromStdString(activ.getDescriere()) };
		auto durata = new QTableWidgetItem{ QString::number(activ.getDurata()) };
		tab->setItem(i, 0, titlu);
		tab->setItem(i, 1, tip);
		tab->setItem(i, 2, descriere);
		tab->setItem(i, 3, durata);
		i++;
	}
}

void GUI::init()
{
	//auto w = new QWidget;
	setStyleSheet("background-color: 	#d0b998");
	auto lyMain = new QHBoxLayout;

	auto lyData = new QFormLayout;
	tipTxt->setStyleSheet("background-color: 	#f0e1cf");
	lyData->addRow("tip", tipTxt);
	titluTxt->setStyleSheet("background-color: 	#f0e1cf");
	lyData->addRow("titlu", titluTxt);
	descriereTxt->setStyleSheet("background-color: 	#f0e1cf");
	lyData->addRow("descriere", descriereTxt);
	durataTxt->setStyleSheet("background-color: 	#f0e1cf");
	lyData->addRow("durata", durataTxt);

	

	auto lyBtns = new QHBoxLayout;
	lyBtns->addWidget(adauga);
	adauga->setStyleSheet("background-color: 	#94ceea");
	QPixmap pixmap1("add.png");
	QIcon ButtonIcon2(pixmap1);
	adauga->setIcon(ButtonIcon2);
	lyBtns->addWidget(sterge);
	QPixmap pixmap2("del.png");
	QIcon ButtonIcon3(pixmap2);
	sterge->setIcon(ButtonIcon3);
	sterge->setStyleSheet("background-color: 	#94ceea");
	lyBtns->addWidget(actualizeaza);
	QPixmap pixmap3("upd.png");
	QIcon ButtonIcon4(pixmap3);
	actualizeaza->setIcon(ButtonIcon4);
	actualizeaza->setStyleSheet("background-color: 	#94ceea");

	auto lyContent = new QVBoxLayout;

	lyContent->addLayout(lyData);
	lyContent->addWidget(btnReadOnly);
	lyContent->addWidget(btnProg);
	

	auto lyCos = new QHBoxLayout;
	lyCos->addWidget(btnAddCos);
	btnAddCos->setStyleSheet("background-color: 	#94ceea");
	lyCos->addWidget(btnDelCos);
	btnDelCos->setStyleSheet("background-color: 	#94ceea");
	lyCos->addWidget(btnGenCos);
	nrGen->setStyleSheet("background-color: 	#f0e1cf");
	lyCos->addWidget(nrGen);
	btnGenCos->setStyleSheet("background-color: 	#94ceea");
	lyContent->addLayout(lyCos);

	btnProg->setStyleSheet("background-color: 	#94ceea");
	btnReadOnly->setStyleSheet("background-color: 	#94ceea");
	lyContent->addLayout(lyBtns);


	auto lyLeft = new QVBoxLayout;
	auto lyRight = new QVBoxLayout;

	lyLeft->addLayout(lyContent);
	undo->setStyleSheet("background-color: 	#94ceea");
	QPixmap pixmap4("undo.png");
	QIcon ButtonIcon5(pixmap4);
	undo->setIcon(ButtonIcon5);
	lyLeft->addWidget(undo);


	lyRight->addWidget(list);
	list->setStyleSheet("background-color: #54a6bf");
	tab->setStyleSheet("background-color: #54a6bf");
	//lyRight->addWidget(tab);
	lyRight->addWidget(refresh);
	QPixmap pixmap("unnamed.png");
	QIcon ButtonIcon(pixmap);
	refresh->setIcon(ButtonIcon);
	refresh->setStyleSheet("background-color: 	#54a6bf");
	auto lySort = new QHBoxLayout;
	auto lyFilt = new QHBoxLayout;
	lySort->addWidget(sortDesc);
	sortDesc->setStyleSheet("background-color: 	#4294d2");
	lySort->addWidget(sortTip);
	sortTip->setStyleSheet("background-color: 	#4294d2");
	lyFilt->addWidget(filtruDesc);
	filtruDesc->setStyleSheet("background-color: 	#4294d2");
	lyFilt->addWidget(filtruTip);
	filtruTip->setStyleSheet("background-color: 	#4294d2");
	lyRight->addLayout(lySort);
	lyRight->addLayout(lyFilt);
	


	lyMain->addLayout(lyLeft);
	lyMain->addLayout(lyRight);
	setLayout(lyMain);
	//w->show();
}

void GUI::initConnect()
{
	//auto tip = tipTxt->text().toStdString();
	//auto titlu = titluTxt->text().toStdString();
	//auto descriere = descriereTxt->text().toStdString();
	//int durata = descriereTxt->text().QString::toInt();


	QObject::connect(btnAddCos, &QPushButton::clicked, [&]() { // buton adaugare
		try
		{
			servo.adaugareLista(titluTxt->text().toStdString(), tipTxt->text().toStdString());
		}
		catch (SrcExceptions)
		{
			QMessageBox::information(nullptr, "eroare adaugare", "nu exista");
		}
		catch (ValidException)
		{
			QMessageBox::information(nullptr, "eroare adaugare", "date invalide");
		}
		});

	QObject::connect(btnDelCos, &QPushButton::clicked, [&]() { // buton golire
		try
		{
			servo.stergereLista();
		}
		catch (SrcExceptions)
		{
			QMessageBox::information(nullptr, "eroare adaugare", "nu exista activitate");
		}
		});

	QObject::connect(btnGenCos, &QPushButton::clicked, [&]() { // buton genereaza
		try
		{
			servo.generare(nrGen->text().toInt());
		}
		catch (SrcExceptions)
		{
			QMessageBox::information(nullptr, "eroare adaugare", "eroare");
		}
		});


	QObject::connect(adauga, &QPushButton::clicked, [&]() { // buton adaugare
			try
			{
				servo.adaugare(titluTxt->text().toStdString(), descriereTxt->text().toStdString(), tipTxt->text().toStdString(), durataTxt->text().toInt());
			}
			catch (AddException)
			{
				QMessageBox::information(nullptr, "eroare adaugare", "deja exista activitate cu acest tip si titlu");
			}
			catch (ValidException)
			{
				QMessageBox::information(nullptr, "eroare adaugare", "date invalide");
			}
			loadData(servo.getActivitati());
		});

	QObject::connect(sterge, &QPushButton::clicked, [&]() { //buton stergere
		try
		{
			servo.stergere(titluTxt->text().toStdString(), tipTxt->text().toStdString());
		}
		catch (DelException)
		{
			QMessageBox::information(nullptr, "eroare stergere", "nu exista element");
		}
		loadData(servo.getActivitati());
		});

	QObject::connect(actualizeaza, &QPushButton::clicked, [&]() { // buton modificare
		try
		{
			servo.modificare(titluTxt->text().toStdString(), descriereTxt->text().toStdString(), tipTxt->text().toStdString(), durataTxt->text().toInt());
		}
		catch (UptExceptions)
		{
			QMessageBox::information(nullptr, "eroare modificare", "nu exista element");
		}
		catch (ValidException)
		{
			QMessageBox::information(nullptr, "eroare modificare", "date invalide");
		}
		loadData(servo.getActivitati());
		});

	QObject::connect(list, &QListWidget::itemSelectionChanged, [&]() { //actualizare campuri
			auto elems = list->selectedItems();
			if (elems.isEmpty())
			{
				titluTxt->setText("");
				tipTxt->setText("");
				descriereTxt->setText("");
				durataTxt->setText("");
			}
			else
			{
				auto item = elems.at(0);
				string titlu = item->text().toStdString();
				string tip = item->data(Qt::UserRole).toString().toStdString();
				Activitate activ = servo.cautare(titlu, tip);

				titluTxt->setText(QString::fromStdString(activ.getTitlu()));
				tipTxt->setText(QString::fromStdString(activ.getTip()));
				descriereTxt->setText(QString::fromStdString(activ.getDescriere()));
				durataTxt->setText(QString::number(activ.getDurata()));
			}
		});


	QObject::connect(refresh, &QPushButton::clicked, [&]() {   //refresh
		loadData(servo.getActivitati());
		});


	QObject::connect(filtruDesc, &QPushButton::clicked, [&]() {   //filtrare descriere
			vector<Activitate> activitati;
			string descriere = descriereTxt->text().toStdString();
			activitati = servo.filtrareDescriere(descriere);
			loadData(activitati);
		});

	QObject::connect(filtruTip, &QPushButton::clicked, [&]() {   //filtrare tip
		vector<Activitate> activitati;
		string tip = tipTxt->text().toStdString();
		activitati = servo.filtrareTip(tip);
		loadData(activitati);
		});


	QObject::connect(sortDesc, &QPushButton::clicked, [&]() {   //sortare descriere
		vector<Activitate> activitati;
		activitati = servo.sortDescriere();
		loadData(activitati);
		});

	QObject::connect(sortTip, &QPushButton::clicked, [&]() {   //sortare tip + durata
		vector<Activitate> activitati;
		activitati = servo.sortDurata();
		loadData(activitati);
		});

	QObject::connect(undo, &QPushButton::clicked, [&]() {   //undo
		try
		{
			servo.undo();
		}
		catch(UndoException)
		{
			QMessageBox::information(nullptr, "eroare undo", "nu se mai poate");
		}
		
		loadData(servo.getActivitati());
		});


	QObject::connect(btnProg, &QPushButton::clicked, [&]() {
		auto program = new Prog{ servo };
		program->show();
		});

	QObject::connect(btnReadOnly, &QPushButton::clicked, [&]() {
		auto histograma = new ReadOnlyGui{ servo };
		histograma->show();
		});

}