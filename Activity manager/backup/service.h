#pragma once
#include "repository.h"
#include "repositoryFile.h"
#include "repo.h"
#include "domain.h"
#include "Validator.h"
#include <random> // std::default_random_engine
#include <chrono> // std::chrono::system_clock
#include <fstream>
#include <map>
#include "undo.h"

class ServActiv
{
public:
	/*
	constructor repository(default)
	*/
	ServActiv() = default;

	/*
	constructor repository(cu repo dat)
	*/
	ServActiv(RepoAbs& repo2, Validator& valid2) noexcept : repo{ repo2 }, valid{valid2} {}

	/*
	constructor repository(cu obiect dat) -> sterge copia obiectului
	*/
	ServActiv(const ServActiv& ot) = delete;

	/*
	pre:activ(adresa unui obiect Activitate)
	post: adauga in repository obiectul
	error: AddException daca deja exista un obiect cu acel tip si titlu
	*/
	void adaugare(const string& titlu,const string& descriere,const string& tip,int durata);

	/*
	pre:titlu(string), tip(string)
	post: sterge din repository obiectul
	error: DelException daca nu exista un obiect cu acel tip si titlu
	*/
	void stergere(string titlu, string tip);

	/*
	pre:titlu(string), tip(string)
	post: returneaza un obiect Activitate
	error: SrcException daca nu exista un obiect cu acel tip si titlu
	*/
	Activitate cautare(string titlu, string tip);

	/*
	pre:activ(adresa unui obiect Activitate)
	post: actualizeaza un obiect din repositroy
	error: UptException daca nu exista un obiect cu acel tip si titlu
	*/
	void modificare(string titlu, string descriere, string tip, int durata);

	/*
	pre:-
	post: returneaza un vector cu obiecte Activitate
	*/
	vector<Activitate> getActivitati() ;

	/*
	pre:descriere(string)
	post: returneaza un vector cu obiecte Activitate al caror camp "descriere" coincide cu cea data
	*/
	vector<Activitate> filtrareDescriere(string descriere);

	/*
	pre:tip(string)
	post: returneaza un vector cu obiecte Activitate al caror camp "tip" coincide cu cea data
	*/
	vector<Activitate> filtrareTip(string tip);

	/*
	pre:-
	post: returneaza un vector cu obiecte Activitate sortate dupa titlu
	*/
	vector<Activitate> sortTitlu();

	/*
	pre:-
	post: returneaza un vector cu obiecte Activitate sortate dupa descriere
	*/
	vector<Activitate> sortDescriere();

	/*
	pre:-
	post: returneaza un vector cu obiecte Activitate sortate dupa tip si durata
	*/
	vector<Activitate> sortDurata();

	
	/*
	pre:titlu(string), tip(string)
	post: adauga in lista obiectul
	error: SrcException daca nu exista un obiect cu acel tip si titlu
	*/
	void adaugareLista(string& titlu,string& tip);
	
	/*
	pre:-
	post: returneaza un vector cu obiecte Activitate
	*/
	vector<Activitate> getList();

	/*
	pre: -
	post: sterge toate elementele din lista
	*/
	void stergereLista();

	/*
	pre: nr(int)
	post: adauga in lista nr elemente
	*/
	void generare(int nr);


	/*
	pre: fisier(string), numele unui fisier csv
	post: creeaza un fisier cvs si adauga in el elementele din lista
	*/
	void exportare(string& fisier);

	std::map<string, int> numarare() const noexcept;

	void undo();


private:
	RepoAbs& repo;
	Validator& valid;
	vector<std::unique_ptr<ActiuneUndo>> undoActions;
};