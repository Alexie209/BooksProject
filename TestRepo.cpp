//
// Created by Alexie on 5/18/2021.
//

#include "TestRepo.h"
#include "CartePoezie.h"
#include "CarteProza.h"
#include "RepoException.h"
#include <cassert>
void TestRepo::testGetAll() {
    Repo repo;
    for(auto & i : this->carti)
    {
        repo.addCarte(i);
    }

    vector<Carte*> carti = repo.getAll();
    assert(carti.size() == this->carti.size());
    for(int i = 0 ;i<this->carti.size() ;i ++)
    {
        assert(*carti[i] == *this->carti[i]);
    }

}

void TestRepo::testGetSize() {
    Repo repo;
    assert(repo.getSize() == 0);

    for(auto & i : this->carti)
    {
        repo.addCarte(i);
    }
    assert(repo.getSize() == this->carti.size());
}

void TestRepo::testGet() {
    Repo repo;
    for(int i =0 ;i<this->carti.size();i++)
    {
        repo.addCarte(this->carti[i]);
    }

    vector<Carte*> carti = repo.getAll();
    for(int i=0;i<this->carti.size();i++)
    {
        assert(*repo.get(i) ==*this->carti[i]);
    }
    try
    {
        repo.get(-1);
        assert(false);
    }
    catch(RepoException& e) {}
    catch (...)
    {
        assert(false);
    }
    try {
        repo.get(repo.getSize());
        assert(false);
    }
    catch (RepoException& e) {
        
    }
    catch (...)
    {
        assert(false);
    }
}

void TestRepo::testFind() {
    Repo repo;
    for(int i =0 ;i<this->carti.size();i++)
    {
        repo.addCarte(this->carti[i]);
    }
    for(int i=0;i<this->carti.size();i++)
    {
        assert(repo.find(this->carti[i]) == i);
    }
    CartePoezie* cPo = new CartePoezie(1,"Scrisoarea I", "Mihai Eminescu",
                                       10,"editura1");
    assert(repo.find(cPo) == -1);
}

void TestRepo::testAddCarte() {
    Repo repo;
    for(auto & i : this->carti)
    {
        repo.addCarte(i);
    }
    CartePoezie* cPo = new CartePoezie(1,"Scrisoarea I", "Mihai Eminescu",
                                       10,"editura1");
    repo.addCarte(cPo);
    assert(repo.getSize() == this->carti.size() + 1);
    assert(*repo.get(repo.getSize() - 1) == *cPo);
}

void TestRepo::testDeleteCarte() {
    Repo repo;
    for(auto & i : this->carti)
    {
        repo.addCarte(i);
    }
    repo.deleteCarte(this->carti[0]);
    assert(repo.getSize() == 1);
    assert(repo.find(this->carti[1]) != -1);

    CartePoezie* cPo = new CartePoezie(1,"Scrisoarea I", "Mihai Eminescu",
                                       10,"editura1");
    try{
        repo.deleteCarte(cPo);
    }
    catch (RepoException& e) {}
    catch (...)
    {
        assert(false);
    }
    assert(repo.getSize() == 1);
    assert(repo.find(this->carti[1]) != -1);
}

TestRepo::TestRepo() {
    CarteProza* c1 = new CarteProza(1, "Marile Sperante", "Charles Dickens",
                                    50, 350);
    CartePoezie* c2 = new CartePoezie(2, "Luceafarul", "Mihai Eminescu",
                                      23,"Casa Buna");
    this->carti.push_back(c1);
    this->carti.push_back(c2);
}

TestRepo::~TestRepo() {
    for(auto & i : this->carti)
    {
        delete i;
        i = NULL;
    }
    this->carti.clear();
}

void TestRepo::testAll() {
    this->testGetAll();
    this->testGetSize();
    this->testGet();
    this->testFind();
    this->testAddCarte();
    this->testDeleteCarte();
}
