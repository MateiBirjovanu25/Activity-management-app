/*
#include "vector_dinamic.h"

void Lista::push_back(const Activitate& activ)
{
	if (cp == n)
	{
		Activitate* aux = new Activitate[cp * 2];
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

void Lista::erase(const int poz)
{
	for (int i = poz;i < n - 1;i++)
	{
		elems[i] = elems[i + 1];
	}
	n--;
}

int Lista::size() const
{
	return n;
}

void Lista::operator=(const Lista& ot)
{
	n = ot.n;
	cp = ot.cp;
	Activitate* elems_new = new Activitate[cp];
	for (int i = 0;i < n;i++)
	{
		elems_new[i] = ot.elems[i];
	}
	delete elems;
	elems = elems_new;
}


Lista<TElem>::Lista(const Lista& ot)
{
	*this = ot;
}

Lista<TElem>::~Lista()
{
	delete[] elems;
}

Iterator<TElem> Lista<TElem>::begin()
{
	return Iterator{ *this};
}

Iterator Lista::end()
{
	return Iterator{ *this,n};
}

Activitate& Lista::at(int poz) const
{
	return elems[poz];
}






Activitate Iterator::operator*()
{
	return vec.elems[poz];
}

Iterator Iterator::operator++()
{
	poz++;
	return *this;
}

bool Iterator::operator==(const Iterator& ot)
{
	return poz == ot.poz;
}

bool Iterator::operator!=(const Iterator& ot)
{
	return !(*this == ot);
}
*/