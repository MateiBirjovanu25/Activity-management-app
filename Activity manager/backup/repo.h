#pragma once
#include <map>
#include <vector>
#include "domain.h"
#include <string>
#include "exceptions.h"
#include <random> // std::default_random_engine
#include <chrono> // std::chrono::system_clock
using std::map;
using std::vector;
using std::string;

class RepoAbs
{
public:
	
	RepoAbs() = default;

	RepoAbs(const RepoAbs& ot) = delete;

	virtual void add(const Activitate& activ) = 0;

	virtual void del(const string titlu, const string tip) = 0;
	
	virtual void update(const Activitate& activ) = 0;
	
	virtual Activitate search(const string titlu, const string tip) = 0;

	virtual vector<Activitate> getAll()  = 0;

	virtual void addList(string& titlu, string& tip) = 0;

	virtual void deleteList() = 0;

	virtual vector<Activitate> getList()  = 0;

	virtual float pacanica() = 0;

	virtual ~RepoAbs() = default;
};

class Repo : public RepoAbs
{
public:

	Repo(): proc{0.5}{}

	Repo(const Repo& ot) = delete;

	virtual void add(const Activitate& activ) override;

	virtual void del(const string titlu, const string tip) override;

	virtual void update(const Activitate& activ) override;

	virtual Activitate search(const string titlu, const string tip) override;

	virtual vector<Activitate> getAll() override;

	/*
	pre:titlu(string), tip(string)
	post: adauga in lista obiectul
	error: SrcException daca nu exista un obiect cu acel tip si titlu
	*/
	void addList(string& titlu, string& tip) override;

	/*
	pre: -
	post: sterge toate elementele din lista
	*/
	void deleteList() override;

	/*
	pre:-
	post: returneaza un vector cu obiecte Activitate
	*/
	vector<Activitate> getList() override;

	float pacanica() override;

private:
	map<int, Activitate> activitati;
	vector<Activitate> lista;
	int n=0;
	float proc;
};



