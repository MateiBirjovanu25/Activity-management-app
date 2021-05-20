#include "Validator.h"
#include "exceptions.h"

void Validator::valid(const Activitate& activ) const
{
	if (activ.getDescriere() == "")
		throw ValidException();
	else if (activ.getTip() != "important" && activ.getTip() != "neimportant")
		throw ValidException();
	else if (activ.getDurata() <= 0)
		throw ValidException();
	else if (activ.getTitlu() == "")
		throw ValidException();
}