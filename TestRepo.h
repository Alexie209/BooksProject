//
// Created by Alexie on 5/18/2021.
//

#ifndef PROIECT_TESTREPO_H
#define PROIECT_TESTREPO_H
#include "Repo.h"
#include "Carte.h"
#include "ValidationException.h"

class TestRepo {
private:
    vector<Carte*> carti;
    void testGetAll();
    void testGetSize();
    void testGet();
    void testFind();
    void testAddCarte();
    void testDeleteCarte();
public:
    TestRepo();
    ~TestRepo();
    void testAll();
};


#endif //PROIECT_TESTREPO_H
