#pragma once
#include "domain.h"

template < typename TElem>
class Lista;

template < typename TElem>
class Iterator
{

private:
	Lista<TElem>& vec;
	int poz = 0;
public:
	/*
	constructor cu vector
	*/
	Iterator(Lista<TElem>& v) : vec{v} {}

	/*
	constructor cu vector si pozitie
	*/
	Iterator(Lista<TElem>& v, int poz) : vec{ v }, poz{poz} {}

	/*
	suprascriere operatir *
	*/
	Activitate operator*();

	/*
	suprascriere operatir ++
	*/
	Iterator operator++();

	/*
	suprascriere operatir ==
	*/
	bool operator==(const Iterator& ot);

	/*
	suprascriere operatir !=
	*/
	bool operator!=(const Iterator& ot);
};

template < typename TElem>
class Lista
{
private:
	int cp;
	int n;
	Activitate* elems;

public:
	/*
	constructor cu capacitate, nr elem, vector de elemente
	*/
	Lista() : cp{ 10 }, n{ 0 }, elems{ new Activitate[cp] }{} 

	/*
	suprascriere operatir =
	*/
	void operator=(const Lista<TElem>& ot);

	/*
	adauga elemente la final
	pre: activ: const Activitate&
	post: adauga un element la final
	*/
	void push_back(const Activitate& activ);

	/*
	constructor de copiere
	*/
	Lista(const Lista<TElem>& ot);

	/*
	deconstructor
	*/
	~Lista();

	/*
	sterge elentul din lista dupa indice
	pre: i: const int
	post: sterge elementul de pe pozitia i
	*/
	void erase(const int i);

	/*
	sterge elentul din lista dupa indice
	pre: i: const int
	post: sterge elementul de pe pozitia i
	*/
	int size() const noexcept;

	/*
	returneaza elementul de pozitia poz
	pre: poz: int
	post: returneaza elementul de pe pozitia poz
	*/
	Activitate& at(int poz) const noexcept;

	friend class Iterator<TElem>;

	/*
	returneaza un iterator pe prima poziti din vector
	pre: -
	post: returneaza un iterator pe prima poziti din vector
	*/
	Iterator<TElem> begin();

	/*
	returneaza un iterator pe ultima pozitie din vector
	pre: -
	post: returneaza un iterator pe ultima pozitie din vector
	*/
	Iterator<TElem> end();
};


template < typename TElem>
void Lista<TElem>::push_back(const Activitate& activ)
{
	if (cp == n)
	{
		Activitate* aux = new Activitate[cp * 2];
		if(aux!=nullptr)
		for (int i = 0;i < n;i++)
		{
			aux[i] = elems[i];
		}
		delete[] elems;
		elems = aux;
		cp *= 2;
	}
	elems[n++] = activ;
}

template < typename TElem>
void Lista<TElem>::erase(const int poz)
{
	for (int i = poz;i < n - 1;i++)
	{
		elems[i] = elems[i + 1];
	}
	n--;
}

template < typename TElem>
int Lista<TElem>::size() const noexcept
{
	return n;
}

template < typename TElem>
void Lista<TElem>::operator=(const Lista& ot)
{
	n = ot.n;
	cp = ot.cp;
	Activitate* elems_new = new Activitate[cp];
	for (int i = 0;i < n;i++)
	{
		elems_new[i] = ot.elems[i];
	}
	delete[] elems;
	elems = elems_new;
}

template < typename TElem>
Lista<TElem>::Lista(const Lista& ot)
{
	cp = ot.cp;
	n = ot.n;
	elems = new TElem[cp];
	for (int i = 0; i < n;i++)
	{
		elems[i] = ot.elems[i];
	}
}

template < typename TElem>
Lista<TElem>::~Lista()
{
	delete[] elems;
}

template < typename TElem>
Iterator<TElem> Lista<TElem>::begin()
{
	return Iterator<TElem>{ *this };
}

template < typename TElem>
Iterator<TElem> Lista<TElem>::end()
{
	return Iterator<TElem>{ *this,n };
}

template < typename TElem>
Activitate& Lista<TElem>::at(int poz) const noexcept
{
	return elems[poz];
}





template < typename TElem>
Activitate Iterator<TElem>::operator*()
{
	return vec.elems[poz];
}

template < typename TElem>
Iterator<TElem> Iterator<TElem>::operator++()
{
	poz++;
	return *this;
}

template < typename TElem>
bool Iterator<TElem>::operator==(const Iterator& ot)
{
	return poz == ot.poz;
}

template < typename TElem>
bool Iterator<TElem>::operator!=(const Iterator& ot)
{
	return !(*this == ot);
}


