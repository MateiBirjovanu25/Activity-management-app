#include "ui.h"
using std::cin;
using std::cout;
//using namespace std;
#include <cstring>
#include <sstream>

bool isNumber(string s) noexcept
{

	for (unsigned int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false)
			return false;

	return true;
}


void Ui::start() noexcept
{
	while (true)
	{
		cout << "\n1. adaugare\n2. stergere\n3. modificare\n4. afisare elemente\n";
		cout << "5. cautare dupa titlu si tip\n";
		cout << "6. filtru dupa descriere\n";
		cout << "7. filtru dupa tip\n";
		cout << "8. sortare titlu\n";
		cout << "9. sortare descriere\n";
		cout << "10. sortare tip+durata\n";
		cout << "------------------------\n";
		cout << "11. adauga in lista dupa titlu\n";
		cout << "12. sterge tot din lista\n";
		cout << "13. afisare lista\n";
		cout << "14. generare\n";
		cout << "15. exportare\n";
		cout << "16. dictionar\n";
		cout << "17. undo\n";
		cout<<"0. EXIT\n";

		cout << "introduceti numarul comenzii:";
		string optiune,urgenta;
		std::getline(cin, optiune);
		system("cls");
		

		if (optiune == "0")
			break;

		try
		{
			if (optiune == "1")
			{
				try
				{
					string tip;
					string titlu;
					string descriere, dur;
					int durata;
					cout << "introduceti tip: ";
					std::getline(cin, tip);
					cout << "introduceti titlu: ";
					std::getline(cin, titlu);
					cout << "introduceti descrierea: ";
					std::getline(cin, descriere);
					cout << "introduceti durata: ";

					std::getline(cin, dur);
					std::stringstream ss;
					ss << dur;
					ss >> durata;

					if (!isNumber(dur))
					{
						throw ValidException();
					}
					servo.adaugare(titlu, descriere, tip, durata);
				}
				catch (AddException)
				{
					cout << "deja exista element cu acest tip si titlu \n";
				}
				catch (ValidException)
				{
					cout << "datele nu sunt valide\n";
				}

			}

			else if (optiune == "2")
			{
				string tip;
				string titlu;
				cout << "introduceti tip: ";
				std::getline(cin, tip);
				cout << "introduceti titlu: ";
				std::getline(cin, titlu);
				try
				{
					servo.stergere(titlu, tip);
				}
				catch (DelException)
				{
					cout << "Nu exista element\n";
				}
			}

			else if (optiune == "3")
			{
				try
				{
					string tip;
					string titlu;
					string descriere, dur;
					int durata;
					cout << "introduceti tip: ";
					std::getline(cin, tip);
					cout << "introduceti titlu: ";
					std::getline(cin, titlu);
					cout << "introduceti descrierea: ";
					std::getline(cin, descriere);
					cout << "introduceti durata: ";
					std::getline(cin, dur);


					std::stringstream ss;
					ss << dur;
					ss >> durata;

					if (!isNumber(dur))
					{
						throw ValidException();
					}

					servo.modificare(titlu, descriere, tip, durata);
				}
				catch (AddException)
				{
					cout << "deja exista element cu acest tip si titlu \n";
				}
				catch (ValidException)
				{
					cout << "datele nu sunt valide\n";
				}
			}

			else if (optiune == "4")
			{
				auto copie = servo.getActivitati();
				for (const Activitate& i : copie)
				{
					cout << "\nTitlu: " << i.getTitlu() << " " << "Tip: " << i.getTip() << " " << "Descriere: " << i.getDescriere() << " " << "Durata: " << i.getDurata() << std::endl;
				}
				if (copie.size() == 0)
				{
					cout << "nu exista elemente\n";
				}
			}

			else if (optiune == "5")
			{
				string tip;
				string titlu;
				cout << "introduceti tip: ";
				std::getline(cin, tip);
				cout << "introduceti titlu: ";
				std::getline(cin, titlu);
				Activitate activ;
				try
				{
					activ = servo.cautare(titlu, tip);
					cout << "\ntip: " << activ.getTip() << " " << " titlu: " << activ.getTitlu() << " descriere: " << activ.getDescriere() << " durata: " << activ.getDurata() << std::endl;
				}
				catch (SrcExceptions)
				{
					cout << "Nu exista element\n";
				}
			}

			else if (optiune == "6")
			{
				string descriere;
				cout << "introduceti descriere: ";
				std::getline(cin, descriere);
				auto rez = servo.filtrareDescriere(descriere);
				for (const Activitate& i : rez)
				{
					cout << "\nTitlu: " << i.getTitlu() << " " << "Tip: " << i.getTip() << " " << "Descriere: " << i.getDescriere() << " " << "Durata: " << i.getDurata() << std::endl;
				}
				if (rez.size() == 0)
				{
					cout << "nu exista elemente\n";
				}

			}

			else if (optiune == "7")
			{
				string tip;
				cout << "introduceti tipul: ";
				std::getline(cin, tip);
				auto rez = servo.filtrareTip(tip);
				for (const Activitate& i : rez)
				{
					cout << "\nTitlu: " << i.getTitlu() << " " << "Tip: " << i.getTip() << " " << "Descriere: " << i.getDescriere() << " " << "Durata: " << i.getDurata() << std::endl;
				}
				if (rez.size() == 0)
				{
					cout << "nu exista elemente\n";
				}

			}

			else if (optiune == "8")
			{
				auto afis = servo.sortTitlu();
				for (const Activitate& i : afis)
				{
					cout << "\nTitlu: " << i.getTitlu() << " " << "Tip: " << i.getTip() << " " << "Descriere: " << i.getDescriere() << " " << "Durata: " << i.getDurata() << std::endl;
				}
				if (afis.size() == 0)
				{
					cout << "nu exista elemente\n";
				}
			}

			else if (optiune == "9")
			{
				auto afis = servo.sortDescriere();
				for (const Activitate& i : afis)
				{
					cout << "\nTitlu: " << i.getTitlu() << " " << "Tip: " << i.getTip() << " " << "Descriere: " << i.getDescriere() << " " << "Durata: " << i.getDurata() << std::endl;
				}
				if (afis.size() == 0)
				{
					cout << "nu exista elemente\n";
				}
			}

			else if (optiune == "10")
			{
				auto afis = servo.sortDurata();
				for (const Activitate& i : afis)
				{
					cout << "\nTitlu: " << i.getTitlu() << " " << "Tip: " << i.getTip() << " " << "Descriere: " << i.getDescriere() << " " << "Durata: " << i.getDurata() << std::endl;
				}
				if (afis.size() == 0)
				{
					cout << "nu exista elemente\n";
				}
			}

			else if (optiune == "11")
			{
				string titlu;
				cout << "introduceti titlu: ";
				std::getline(cin, titlu);

				string tip;
				cout << "introduceti tip: ";
				std::getline(cin, tip);

				try
				{
					servo.adaugareLista(titlu, tip);
				}
				catch (SrcExceptions)
				{
					cout << "nu exista\n";
				}

				auto copie = servo.getList();
				cout << "nr elemente: " << copie.size() << "\n";

			}

			else if (optiune == "12")
			{
				servo.stergereLista();

				auto copie = servo.getList();
				cout << "nr elemente: " << copie.size() << "\n";
			}


			else if (optiune == "13")
			{
				auto copie = servo.getList();
				for (const Activitate& i : copie)
				{
					cout << "\nTitlu: " << i.getTitlu() << " " << "Tip: " << i.getTip() << " " << "Descriere: " << i.getDescriere() << " " << "Durata: " << i.getDurata() << std::endl;
				}
				if (copie.size() == 0)
				{
					cout << "nu exista elemente\n";
				}
			}

			else if (optiune == "14")
			{
				int nr;
				string dur;
				std::cout << "introduceti nr de numere: ";
				std::getline(cin, dur);
				std::stringstream ss;
				ss << dur;
				ss >> nr;

				try
				{
					servo.generare(nr);
					auto copie = servo.getList();
					cout << "nr elemente: " << copie.size() << "\n";
				}
				catch (SrcExceptions)
				{
					cout << "nu sunt suficiente activitati\n";
				}

			}

			else if (optiune == "15")
			{
				string fisier;
				cout << "introduceti numele fisierului: ";
				getline(cin, fisier);
				servo.exportare(fisier);

				auto copie = servo.getList();
				cout << "nr elemente: " << copie.size() << "\n";
			}

			else if (optiune == "16")
			{
				std::map<string, int> rez;
				rez = servo.numarare();
				for (auto& elem : rez)
				{
					cout << elem.first << " " << elem.second << "\n";
				}
			}

			else if (optiune == "17")
			{
				try
				{
					servo.undo();
				}
				catch (UndoException)
				{
					cout << "nu mai exista actiuni anterioare\n";
				}
			}

			else
			{
				cout << "invalid\n";
			}
		}
		catch (PacanicaException& ex)
		{
			cout << "ati dat " << ex.getMessage() << " si e prea mare\n";
		}

	}

}