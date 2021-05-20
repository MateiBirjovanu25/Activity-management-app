#pragma once
#include "repository.h"
#include <fstream>
class RepoActivFile :public RepoActiv {

public:
	/*
		constructor repository(default)
		*/
	RepoActivFile(string fName) : RepoActiv(), fName{ fName }
	{
		loadFromFile();
	}

	/*
	constructor repository(cu obiect dat) -> sterge copia obiectului
	*/
	RepoActivFile(const RepoActivFile & ot) = delete;

	/*
	pre:activ(adresa unui obiect Activitate)
	post: adauga in repository obiectul
	error: AddException daca deja exista un obiect cu acel tip si titlu
	*/
	void add(const Activitate& activ) override;

	/*
	pre:titlu(string), tip(string)
	post: sterge din repository obiectul 
	error: DelException daca nu exista un obiect cu acel tip si titlu
	*/
	void del(const string titlu, const string tip) override;

	/*
	pre:activ(adresa unui obiect Activitate)
	post: actualizeaza un obiect din repositroy
	error: UptException daca nu exista un obiect cu acel tip si titlu
	*/
	void update(const Activitate & activ) override;

private:
	void loadFromFile();
	void writeToFile();
	vector<Activitate> activitati;
	vector<Activitate> lista;
	string fName;
};