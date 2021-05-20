#include "domain.h"

string Activitate::getTitlu() const
{
	return titlu;
}


string Activitate::getDescriere() const
{
	return descriere;
}


string Activitate::getTip () const
{
	return tip;
}

int Activitate::getDurata() const 
{
	return durata;
}

void Activitate::setTitlu(const string titlu2) 
{
	this->titlu = titlu2;
}

void Activitate::setTip(const string tip2)
{
	this->tip = tip2;
}

void Activitate::setDescriere(const string descriere2) 
{
	this->descriere = descriere2;
}

void Activitate::setDurata(const int durata2) noexcept
{
	this->durata = durata2;
}
