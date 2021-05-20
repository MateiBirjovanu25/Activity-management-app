#include "repo.h"

void Repo::add(const Activitate& activ)
{
	const float p = pacanica();
	if (p >= proc)
	{
		throw (PacanicaException(p));
	}
	
	for (auto miere : activitati)
	{
		if (miere.second.getTitlu() == activ.getTitlu() && miere.second.getTip() == activ.getTip())
		{
			throw AddException();
		}
	}
	activitati.insert(std::pair<int, Activitate>(n, activ));
	this->n++;
}

void Repo::del(const string titlu, const string tip)
{
	const float p = pacanica();
	if (p >= proc)
	{
		throw (PacanicaException(p));
	}
	int gasit = 0;
	for (auto& miere : activitati)
	{
		if (miere.second.getTitlu() == titlu && miere.second.getTip() == tip)
		{
			gasit = 1;
			activitati.erase(miere.first);
			break;
		}
	}
	if (gasit == 0)
	{
		throw DelException();
	}
}

void Repo::update(const Activitate& activ)
{
	const float p = pacanica();
	if (p >= proc)
	{
		throw (PacanicaException(p));
	}
	int gasit = 0;
	for (auto& miere : activitati)
	{
		if (miere.second.getTitlu() == activ.getTitlu() && miere.second.getTip() == activ.getTip())
		{
			gasit = 1;
			miere.second.setDescriere(activ.getDescriere());
			miere.second.setDurata(activ.getDurata());
			break;
		}
	}
	if (gasit == 0)
	{
		throw UptExceptions();
	}
}


Activitate Repo::search(const string titlu, const string tip)
{
	const float p = pacanica();
	if (p >= proc)
	{
		throw (PacanicaException(p));
	}
	for (auto& miere : activitati)
	{
		if (miere.second.getTitlu() == titlu && miere.second.getTip() == tip)
		{
			return miere.second;
		}
	}
	throw SrcExceptions();
}

vector<Activitate> Repo::getAll()
{
	const float p = pacanica();
	if (p >= proc)
	{
		throw (PacanicaException(p));
	}
	vector<Activitate> labrador;
	for (auto& miere : activitati)
	{
		labrador.push_back(miere.second);
	}
	return labrador;
}

void Repo::addList(string& titlu, string& tip)
{
	const float p = pacanica();
	if (p >= proc)
	{
		throw (PacanicaException(p));
	}
	Activitate activ;
	int gasit = 0;
	for (auto& miere : activitati)
	{
		if (miere.second.getTitlu() == titlu && miere.second.getTip() == tip)
		{
			activ = miere.second;
			gasit = 1;
		}
	}
	if (gasit == 1)
	{
		lista.push_back(activ);
	}
	else
	{
		throw SrcExceptions();
	}
	
}

void Repo::deleteList()
{
	const float p = pacanica();
	if (p >= proc)
	{
		throw (PacanicaException(p));
	}
	while (!lista.empty())
	{
		lista.pop_back();
	}
}

vector<Activitate> Repo::getList() 
{
	const float p = pacanica();
	if (p >= proc)
	{
		throw (PacanicaException(p));
	}
	return lista;
}

float Repo::pacanica()
{
	float rnd;
	std::mt19937 mt{ std::random_device{}() };
	std::uniform_int_distribution<> dist(1, 100);
	rnd = (float)dist(mt);
	float prob = rnd / 100;
	return prob;
}
