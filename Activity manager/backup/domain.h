#pragma once
#include <string>
using std::string;
#include <iostream>
#include <algorithm>
class Activitate
{
public:
	/*
	constructor activitate(cu campuri date)
	*/
	Activitate(string titlu, string descriere, string tip, int durata) :tip{ tip }, descriere{ descriere }, titlu{ titlu }, durata{ durata } {}

	/*
	constructor activitate(cu obiect dat)
	*/
	Activitate(const Activitate& ot) :tip{ ot.tip }, titlu{ ot.titlu }, descriere{ ot.descriere }, durata{ ot.durata } {}

	/*
	constructor activitate(default)
	*/
	Activitate() = default;


	Activitate& operator=(const Activitate& s) = default;

	bool operator==(const Activitate& s) {
		if (titlu == s.getTitlu())
		{
			if (descriere == s.getDescriere())
			{
				if (durata == s.getDurata())
				{
					if (tip == s.getTip())
					{
						return true;}}}}return false;
	}

	Activitate(Activitate&& s) = default;
	/*
	pre:-
	post: returneaza titlul
	*/
	string getTitlu() const;

	/*
	pre:-
	post: returneaza descrierea
	*/
	string getDescriere() const;

	/*
	pre:-
	post: returneaza tipul
	*/
	string getTip() const;

	/*
	pre:-
	post: returneaza durata
	*/
	int getDurata() const ;


	/*
	pre:titlu(string)
	post: seteaza titlul obiectului
	*/
	void setTitlu(const string titlu);

	/*
	pre:tip(string)
	post: seteaza tipul obiectului
	*/
	void setTip(const string tip);

	/*
	pre:descriere(string)
	post: seteaza descrierea obiectului
	*/
	void setDescriere(const string descriere);

	/*
	pre:durata(int)
	post: seteaza durata obiectului
	*/
	void setDurata(const int durata) noexcept;

private:
	string titlu;
	string descriere;
	string tip;
	int  durata;


};

