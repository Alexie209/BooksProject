//
// Created by Alexie on 5/19/2021.
//

#include "TestRepoFile.h"
#include "CartePoezie.h"
#include "CarteProza.h"
#include "RepoException.h"
#include "ReadFromFileException.h"
#include <cassert>
void TestRepoFile::testAddCarte() {
    RepoFile repoFile = RepoFile(this->fileName);
    repoFile.setFileName(this->fileNameOut);
    CarteProza* c = new CarteProza(3,"Ion","Liviu Rebreanu",35,200);
    repoFile.addCarte(c);
    assert(repoFile.getSize() == this->carti.size() + 1);
    assert(*repoFile.get(repoFile.getSize() - 1) == *c);

}

void TestRepoFile::testDeleteCarte() {
    RepoFile repoFile = RepoFile(this->fileName);
    repoFile.setFileName(this->fileNameOut);
    repoFile.deleteCarte(this->carti[0]);
    assert(repoFile.getSize() == 1);
    assert(*repoFile.get(0) == *this->carti[1]);
    assert(repoFile.getSize() == 1);
    assert(*repoFile.get(0) == *this->carti[1]);
}

void TestRepoFile::testLoadFromFile() {
    RepoFile repoFile = RepoFile(this->fileName);
    assert(repoFile.getSize() == this->carti.size());
    for(int i=0;i<this->carti.size();i++)
    {
        assert(*repoFile.get(i) == *this->carti[i]);
    }
    repoFile.setFileName("fsdfdsfds.txt");
    try {
        repoFile.loadFromFile();
        assert(false);
    }
    catch (ReadFromFileException& e) {}
    catch (...)
    {
        assert(false);
    }
    repoFile.setFileName(this->fileNameInvalid);
    try {
        repoFile.loadFromFile();
    }
    catch (ReadFromFileException& e)
    {

    }
    catch (...) {
        assert(false);
    }
}

void TestRepoFile::testSaveToFile() {
    RepoFile repoFile = RepoFile(this->fileName);
    repoFile.setFileName(this->fileNameOut);
    CartePoezie* c = new CartePoezie(1,"Scrisoarea I", "Mihai Eminescu", 20, "ART");
    repoFile.addCarte(c);
    repoFile.saveToFile();
    repoFile.loadFromFile();
    assert(repoFile.getSize() == this->carti.size() + 1);
    vector<Carte*> carti =repoFile.getAll();
    for(int i=0;i<repoFile.getSize() - 1;i++)
    {
        assert(*carti[i] == *this->carti[i]);
    }
    assert(*carti[carti.size()-1] == *c);
}

TestRepoFile::TestRepoFile() {
    CarteProza* c1 = new CarteProza(1, "Marile Sperante", "Charles Dickens", 50, 350);
    CartePoezie* c2 = new CartePoezie(2, "Luceafarul", "Mihai Eminescu", 10, "Corint");
    this->carti.push_back(c1);
    this->carti.push_back(c2);

}

TestRepoFile::~TestRepoFile() = default;

void TestRepoFile::testAll() {
    this->testAddCarte();
    this->testDeleteCarte();
    this->testLoadFromFile();
    this->testSaveToFile();
}
