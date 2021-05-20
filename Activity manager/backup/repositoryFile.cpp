#include "repositoryFile.h"


void RepoActivFile::loadFromFile() {
	std::ifstream fin(fName);
	if (!fin.is_open()){throw FileException();
	}
	while (!fin.eof())
	{
		string tip,titlu,descriere;
		int durata;
		fin >> titlu;
		if (fin.eof())
			break;
		fin >> descriere;
		fin >> tip;
		fin >> durata;
		Activitate activ{ titlu,descriere,tip,durata};
		RepoActiv::add(activ);
	}
	fin.close();
}

void RepoActivFile::writeToFile()
{
	std::ofstream fout(fName);
	if (!fout.is_open()){throw(FileException());
	}
	for (auto& a : getAll())
	{
		fout << a.getTitlu() << std::endl;
		fout << a.getDescriere() << std::endl;
		fout << a.getTip() << std::endl;
		fout << a.getDurata() << std::endl<<std::endl;
	}
	fout.close();
}


void RepoActivFile::add(const Activitate& activ) 
{
	RepoActiv::add(activ);
	
	writeToFile();
}


void RepoActivFile::del(const string titlu, const string tip)
{
	RepoActiv::del(titlu, tip);
	writeToFile();
}

void RepoActivFile::update(const Activitate& activ)
{
	RepoActiv::update(activ);
	writeToFile();
}
