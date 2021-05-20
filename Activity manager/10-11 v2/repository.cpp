#include "repository.h"
#include <algorithm>

/*
RepoActiv::~RepoActiv()
{
	activitati.clear();
}
*/

void RepoActiv::add(const Activitate& activ)
{
	for (const Activitate& i : activitati)
	{
		if (i.getTitlu() == activ.getTitlu() && i.getTip() == activ.getTip())
		{
			throw AddException();}}
	activitati.push_back(activ);
}


void RepoActiv::update(const Activitate& activ)
{
	//unsigned int i;
	int gasit = 0;
	/*
	for ( i = 0;i < activitati.size();i++)
	{ 
		if (activitati.at(i).getTip() == activ.getTip() && activitati.at(i).getTitlu() == activ.getTitlu())
		{
			activitati.at(i).setTip(activ.getTip());
			activitati.at(i).setTitlu(activ.getTitlu());
			activitati.at(i).setDescriere(activ.getDescriere());
			activitati.at(i).setDurata(activ.getDurata());
			gasit = 1;
			break;
		}
	}*/

	for (auto& i : activitati)
	{
		if (i.getTip() == activ.getTip() && i.getTitlu() == activ.getTitlu())
		{
			i.setTip(activ.getTip());
			i.setTitlu(activ.getTitlu());
			i.setDescriere(activ.getDescriere());
			i.setDurata(activ.getDurata());
			gasit = 1;
			break;
		}
	}

	if (gasit == 0){throw UptExceptions();
	}
}


Activitate RepoActiv::search(const string titlu, const string tip)
{
	auto suntvesel = std::find_if(activitati.begin(), activitati.end(), [&titlu, &tip](const Activitate& a) {
		return titlu == a.getTitlu() && tip == a.getTip();
		});

	if (suntvesel == activitati.end())
	{
		throw SrcExceptions();}
	else
	{
		return *suntvesel;}}
	


/*
* std::find_if(activitati.begin(), activitati.end(), std::back_inserter(rez), [&titlu,&tip](const Activitate& a){
		return titlu == a.getTitlu() && tip == a.getTip();
		})
*/

void RepoActiv::del(const string titlu, const string tip)
{
	//unsigned int i;
	int gasit = 0;

	/*
	for (i = 0;i < activitati.size();i++)
	{
		if (activitati.at(i).getTip() == tip && activitati.at(i).getTitlu() == titlu)
		{
			activitati.erase(activitati.begin()+i);
			gasit = 1;
			break;}}
	*/

	for (auto activ : activitati)
	{
		if (activ.getTip() == tip && activ.getTitlu() == titlu)
		{
			activitati.erase(std::find(activitati.begin(), activitati.end(), activ));
			gasit = 1;
			break;}}
	if (gasit == 0)
	{
		throw DelException();
	}
}

vector<Activitate> RepoActiv::getAll() 
{
	return activitati;
}


void RepoActiv::addList(string& titlu,string& tip)
{
	auto suntvesel = std::find_if(activitati.begin(), activitati.end(), [&titlu, &tip](const Activitate& a) {
		return titlu == a.getTitlu() && tip == a.getTip();
		});

	if (suntvesel == activitati.end())
	{
		throw SrcExceptions();}
	else
	{
		lista.push_back(*suntvesel);
	}
}

void RepoActiv::deleteList() noexcept
{
	while (!lista.empty())
	{
		lista.pop_back();
	}
}

vector<Activitate> RepoActiv::getList()
{
	return lista;
}

float RepoActiv::pacanica()
{
	float rnd;
	std::mt19937 mt{ std::random_device{}() };
	std::uniform_int_distribution<> dist(1, 100);
	rnd = (float)dist(mt);
	float prob = rnd / 100;
	return prob;
}

