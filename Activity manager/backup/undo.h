#pragma once
#include "repositoryFile.h"
#include "repo.h"

class ActiuneUndo {
public:
	virtual void doUndo() = 0;
	virtual ~ActiuneUndo() {};
};


class UndoAdauga : public ActiuneUndo {
	Activitate activ;
	RepoAbs& repo;

public:
	UndoAdauga(RepoAbs& repo, const Activitate& activ): repo{repo},activ{activ}{}
	void doUndo() override {
		repo.del(activ.getTitlu(), activ.getTip());
	}
};


class UndoSterge : public ActiuneUndo {
	Activitate activ;
	RepoAbs& repo;

public:
	UndoSterge(RepoAbs& repo, const Activitate& activ) : repo{ repo }, activ{ activ }{}
	void doUndo() override {
		repo.add(activ);
	}
};


class UndoModifica : public ActiuneUndo {
	Activitate activ1;
	Activitate activ2;
	RepoAbs& repo;

public:
	UndoModifica(RepoAbs& repo, const Activitate& activ1, const Activitate& activ2) : repo{ repo }, activ1{ activ1 }, activ2{activ2}{}
	void doUndo() override {
		repo.del(activ1.getTitlu(),activ1.getTip());
		repo.add(activ2);
	}
};

