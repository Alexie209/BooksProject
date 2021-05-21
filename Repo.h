//
// Created by Alexie on 5/18/2021.
//

#ifndef PROIECT_REPO_H
#define PROIECT_REPO_H
#include "Carte.h"
#include <vector>
#include "ValidatorCartePoezie.h"
#include "ValidatorCarteProza.h"

class Repo {
protected:
    vector<Carte*> carti;
    ValidatorCarteProza validatorProza;
    ValidatorCartePoezie validatorPoezie;
public:
    Repo();
    ~Repo();

    vector<Carte*> getAll();
    int getSize();
    Carte* get(int index);
    int find(Carte* c);

    virtual void addCarte(Carte* c);

    virtual void deleteCarte(Carte* c);

    void empty();
};


#endif //PROIECT_REPO_H
