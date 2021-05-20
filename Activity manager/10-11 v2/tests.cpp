#include "tests.h"

void testDomain()
{
	Activitate activ {"sport","frumos","importanta",20};
	assert(activ.getDescriere() == "frumos");
	assert(activ.getTip() == "importanta");
	assert(activ.getTitlu() == "sport");
	assert(activ.getDurata() == 20);


	activ.setTip("a");
	activ.setDescriere("a");
	activ.setTitlu("a");
	activ.setDurata(1);

	assert(activ.getDescriere() == "a");
	assert(activ.getTip() == "a");
	assert(activ.getTitlu() == "a");
	assert(activ.getDurata() == 1);

}

void testRepo()
{
	RepoActiv repo;
	Activitate activ1{ "a","a","a",10 };
	repo.add(activ1);
	auto copie = repo.getAll();
	assert(copie.size() == 1);
	try 
	{
		repo.add(activ1);}
	catch (AddException)
	{
		assert(true);
	}
	//copie.clear();

	repo.search("a", "a");

	try 
	{
		repo.search("k", "k");assert(false);}
	catch(SrcExceptions)
	{
		assert(true);
	}

	Activitate activ2{ "a","b","a",20 };
	repo.update(activ2);


	repo.del("a", "a");
	auto copie2 = repo.getAll();
	assert(copie2.size() == 0);

	Activitate activ3{ "aa","aa","aa",10 };
	repo.add(activ3);
	string titlu = activ3.getTitlu();
	string tip = activ3.getTip();
	repo.addList(titlu, tip);

	Activitate activ4{ "k","k","k",10 };
	repo.add(activ4);
	titlu = activ4.getTitlu();
	tip = activ4.getTip();
	repo.addList(titlu, tip);

	vector<Activitate> rez;

	rez = repo.getList();

	assert(rez.size() == 2);

	repo.deleteList();

	rez = repo.getList();

	assert(rez.size() == 0);

	string a = "caine";
	string b = "maine";

	try 
	{
		repo.addList(a, b);}
	catch (SrcExceptions)
	{
		assert(true);
	}

	float paca = repo.pacanica();
	paca++;
}

void testServ()
{
	RepoActiv repo;
	Validator valid;
	ServActiv servo(repo,valid);
	servo.adaugare("a", "a", "important", 20);
	auto copie = servo.getActivitati();
	assert(copie.size() == 1);
	//copie.clear();

	servo.cautare("a", "important");

	try
	{
		servo.cautare("k", "k");}
	catch (SrcExceptions)
	{
		assert(true);
	}

	servo.modificare("a", "b", "important", 10);

	try
	{
		servo.modificare("g", "g", "important", 20);assert(false);}
	catch (UptExceptions)
	{
		assert(true);
	}
	


	servo.stergere("a", "important");
	auto copie2 = servo.getActivitati();
	assert(copie2.size() == 0);
	//copie2.clear();

	
	try
	{
		servo.stergere("g", "important");assert(false);}
	catch (DelException)
	{
		assert(true);
	}


	servo.adaugare("a", "a", "important", 20);
	servo.adaugare("b", "a", "important", 30);
	servo.adaugare("c", "a", "important", 20);
	
	auto rez = servo.filtrareDescriere("a");
	auto rez2 = servo.filtrareTip("b");
	assert(rez.size() == 3);
	assert(rez2.size() == 0);

	servo.stergere("a", "important");
	servo.stergere("b", "important");
	servo.stergere("c", "important");
	//std::cout << copie.size();
	//assert(copie.size() == 0);

	servo.adaugare("c", "c", "important", 20);
	servo.adaugare("b", "b", "important", 20);
	servo.adaugare("a", "a", "important", 20);

	auto copie6 = servo.sortTitlu();
	assert(copie6.size() == 3);
	assert(copie.at(0).getTitlu() == "a");

	auto copie7 = servo.sortDescriere();
	assert(copie7.size() == 3);
	assert(copie.at(0).getDescriere() == "a");


	servo.adaugare("ksa", "a", "important", 30);
	auto copie8 = servo.sortDurata();
	assert(copie8.size() == 4);
	assert(copie.at(0).getTitlu() == "a");
	
	servo.adaugare("d", "d", "important", 20);
	servo.adaugare("e", "e", "important", 20);
	servo.adaugare("f", "f", "important", 20);
	servo.adaugare("g", "g", "important", 20);
	servo.adaugare("h", "h", "important", 20);
	servo.adaugare("i", "i", "important", 20);
	servo.adaugare("j", "j", "important", 20);
	servo.adaugare("k", "k", "important", 20);
	servo.adaugare("l", "l", "important", 20);


	string a, b;
	a = "d";
	b = "important";
	servo.adaugareLista(a, b);

	a = "e";
	b = "important";
	servo.adaugareLista(a, b);
	
	vector<Activitate> rezu;
	rezu = servo.getList();

	assert(rezu.size() == 2);

	servo.stergereLista();

	rezu = servo.getList();

	assert(rezu.size() == 0);

	servo.generare(1);

	rezu = servo.getList();

	assert(rezu.size() == 1);

	string fis_test = "fistest";

	servo.exportare(fis_test);

	try 
	{
		servo.generare(20);assert(false);}
	catch (SrcExceptions){assert(true);}

	auto rezultat=servo.numarare();
	
	assert(rezultat.size() == 1);
}


void testValid()
{
	Validator valid;
	constexpr int durata = 10;
	Activitate a1{ "titlu","descriere","important",durata };
	valid.valid(a1);
	Activitate a2{"","descriere","important",durata };
	try 
	{
		valid.valid(a2);}
	catch (ValidException)
	{
		assert(true);
	}

	Activitate a3{ "aa","","important",durata };
	try
	{
		valid.valid(a3);}
	catch (ValidException)
	{
		assert(true);
	}

	Activitate a4{ "aa","aa","",durata };
	try
	{
		valid.valid(a4);}
	catch (ValidException)
	{
		assert(true);
	}

	Activitate a5{ "aa","aa","important",-4};
	try
	{
		valid.valid(a5);}
	catch (ValidException)
	{
		assert(true);
	}



}

void testFile()
{
	RepoActivFile repo{ "test.txt"};
	assert(repo.getAll().size() == 1);
	Activitate activ{ "tit","des","important",1 };
	repo.add(activ);
	Activitate activ2{ "tit","des2","important",2 };
	repo.update(activ2);
	repo.del(activ.getTitlu(), activ.getTip());
}

void testUndo()
{
	RepoActiv repo;
	Validator valid;
	ServActiv servo{ repo,valid };
	servo.adaugare("a", "a", "important", 1);
	servo.modificare("a", "b", "important", 2);
	servo.undo();
	servo.stergere("a", "important");
	servo.undo();
	servo.undo();
	try
	{
		servo.undo();}
	catch (UndoException)
	{
		assert(true);
	}
}