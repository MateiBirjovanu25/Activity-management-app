#pragma once
#include <vector>
#include "domain.h"
#include "repo.h"
#include "exceptions.h"
#include <exception>
using std::vector;


class RepoActiv : public RepoAbs
{
public:
	/*
	constructor repository(default)
	*/
	RepoActiv() = default;

	/*
	constructor repository(cu obiect dat) -> sterge copia obiectului
	*/
	RepoActiv(const RepoActiv& ot) = delete;

	/*
	pre:activ(adresa unui obiect Activitate)
	post: adauga in repository obiectul
	error: AddException daca deja exista un obiect cu acel tip si titlu
	*/
	virtual void add(const Activitate& activ) override;

	/*
	pre:titlu(string), tip(string)
	post: sterge din repository obiectul
	error: DelException daca nu exista un obiect cu acel tip si titlu
	*/
	virtual void del(const string titlu, const string tip) override;

	/*
	pre:activ(adresa unui obiect Activitate)
	post: actualizeaza un obiect din repositroy
	error: UptException daca nu exista un obiect cu acel tip si titlu
	*/
	virtual void update(const Activitate& activ) override;

	/*
	pre:titlu(string), tip(string)
	post: returneaza un obiect Activitate
	error: SrcException daca nu exista un obiect cu acel tip si titlu
	*/
	Activitate search(const string titlu,const string tip) override;

	/*
	pre:-
	post: returneaza un vector cu obiecte Activitate
	*/
	virtual vector<Activitate> getAll()  override;


	/*
	pre:titlu(string), tip(string)
	post: adauga in lista obiectul
	error: SrcException daca nu exista un obiect cu acel tip si titlu
	*/
	void addList(string& titlu,string& tip) override;

	/*
	pre: -
	post: sterge toate elementele din lista
	*/
	void deleteList() noexcept override;

	/*
	pre:-
	post: returneaza un vector cu obiecte Activitate
	*/
	vector<Activitate> getList()  override;

	float pacanica() override;

private:
	vector<Activitate> activitati;
	vector<Activitate> lista;
};

