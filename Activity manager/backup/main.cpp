#include <QtWidgets/QApplication>
#include "GUI.h"
#include "repositoryFile.h"
#include "tests.h"
#include "repository.h"
#include <vector>
#include <string>
using std::vector;
using std::string;

int main(int argc, char *argv[])
{
    testDomain();
    testRepo();
    testServ();
    testValid();
    testFile();
    testUndo();
    QApplication a(argc, argv);
    RepoActivFile repo{ "activitati.txt" };
    Validator valid;
    ServActiv servo{ repo,valid };
    GUI gui{ servo };
    gui.show();
    return a.exec();
}
