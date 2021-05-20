#include "service.h"

/*
ServActiv::~ServActiv()
{
	
}
*/


void ServActiv::adaugare(const string& titlu,const string& descriere,const string& tip, int durata)
{
	Activitate activ{ titlu,descriere,tip,durata };
	valid.valid(activ);
	repo.add(activ);
	undoActions.push_back(std::make_unique<UndoAdauga>(repo, activ));
}


Activitate ServActiv::cautare(string titlu, string tip)
{
	return repo.search(titlu, tip);
}


void ServActiv::modificare(string titlu, string descriere, string tip, int durata)
{
	Activitate activ{ titlu,descriere,tip,durata };

	try
	{
		Activitate old_activ = repo.search(titlu, tip);
		undoActions.push_back(std::make_unique<UndoModifica>(repo, activ,old_activ));
	}
	catch (SrcExceptions)
	{
		throw UptExceptions();}
	valid.valid(activ);
	repo.update(activ);

	
}


void ServActiv::stergere(string titlu, string tip)
{
	Activitate activ{ titlu,"a",tip,1 };
	repo.del(titlu, tip);
	undoActions.push_back(std::make_unique<UndoSterge>(repo, activ));
}


vector<Activitate> ServActiv::getActivitati()
{
	return repo.getAll();
}


vector<Activitate> ServActiv::filtrareDescriere(string descriere)
{
	auto copie = getActivitati();
	vector<Activitate> rez;
	std::copy_if(copie.begin(), copie.end(), std::back_inserter(rez), [&descriere](const Activitate& a) {
		return descriere == a.getDescriere();
		});
	return rez;
}


vector<Activitate> ServActiv::filtrareTip(string tip)
{
	auto copie = getActivitati();
	vector<Activitate> rez;
	std::copy_if(copie.begin(), copie.end(), std::back_inserter(rez), [&tip](const Activitate& a) {
		return tip == a.getTip();
		});
	return rez;
}

void ServActiv::undo()
{
	if (undoActions.empty())
	{
		throw UndoException();
	}
	undoActions.back()->doUndo();
	undoActions.pop_back();
}






bool compTitlu(const Activitate& a, const Activitate& b)
{
	if (a.getTitlu() < b.getTitlu())
		return true;return false;}

bool compDescriere(const Activitate& a, const Activitate& b)
{
	if (a.getDescriere() < b.getDescriere())return true;return false;
}

bool compDurata(const Activitate& a, const Activitate& b)
{
	if (a.getTip() < b.getTip())return true;

	if (a.getTip() == b.getTip())
	{
		if (a.getDurata() < b.getDurata())return true;}
	return false;
}

/*
void sort(const vector<Activitate>& vec, bool(*comp)(const Activitate&, const Activitate&))
{
	unsigned int i, j;
	if(comp!=nullptr)
	for (i = 0;i < vec.size()-1;i++)
	{
		for (j=i+1;j<vec.size();j++)
			if (comp(vec.at(i), vec.at(j)))
			{
				std::swap(vec.at(i), vec.at(j));
			}
	}
}
*/





vector<Activitate> ServActiv::sortTitlu()
{
	auto copie = getActivitati();
	std::sort(copie.begin(),copie.end(),compTitlu);
	return copie;
}



vector<Activitate> ServActiv::sortDescriere()
{
	auto copie = getActivitati();
	std::sort(copie.begin(),copie.end(),compDescriere);
	return copie;
}

vector<Activitate> ServActiv::sortDurata()
{
	auto copie = getActivitati();
	std::sort(copie.begin(),copie.end(),compDurata);
	return copie;
}


void ServActiv::adaugareLista(string& titlu,string& tip)
{
	repo.addList(titlu, tip);
}

vector<Activitate> ServActiv::getList()
{
	return repo.getList();
}

void ServActiv::stergereLista()
{
	repo.deleteList();
}


void ServActiv::generare(int nr)
{
	
	vector<Activitate> copie=repo.getAll();
	if ((unsigned int)nr > copie.size()){throw SrcExceptions();
	}
	std::mt19937 mt{ std::random_device{}() };
	for (int i = 0;i < nr;i++)
	{
		std::uniform_int_distribution<> dist(0, copie.size() - 1);
		const int rndNr = dist(mt);
		Activitate activ = copie.at(rndNr);
		copie.erase(copie.begin() + rndNr);
		string titlu = activ.getTitlu();
		string tip = activ.getTip();
		repo.addList(titlu, tip);
	}
	
}

void ServActiv::exportare(string& fisier)
{
	fisier += ".csv";
	std::ofstream fout(fisier);
	for (auto& activ : repo.getList())
	{
		fout << activ.getTip() << "," << activ.getTitlu() << "," << activ.getDescriere() <<","<<activ.getDurata() << "\n";
	}
	fout.close();
}

std::map<string, int> ServActiv::numarare() const noexcept
{
	std::map<string, int> elements;
	for (auto& activ : repo.getAll())
	{
		if (elements.find(activ.getTip())==elements.end())
		{
			elements.insert(std::pair<string,int>(activ.getTip(),1));
		}
		else
		{
			for (auto& elem : elements)
			{
				if (elem.first == activ.getTip())
				{
					elem.second++;
				}
			}
		}
	}
	return elements;
}