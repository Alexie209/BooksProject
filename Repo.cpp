//
// Created by Alexie on 5/18/2021.
//

#include "Repo.h"
#include "RepoException.h"
#include "CarteProza.h"
#include "CartePoezie.h"
Repo::Repo() {

}

Repo::~Repo() {
    this->empty();
}

vector<Carte *> Repo::getAll() {
    vector<Carte*> cartiCopie;
    for(int i=0;i<this->carti.size(); i++)
    {
        cartiCopie.push_back(this->carti[i]->clone());
    }
    return cartiCopie;
}

int Repo::getSize() {
    return this->carti.size();
}

Carte *Repo::get(int index) {
    if (index < 0 || index >= this->carti.size())
    {
        throw RepoException("Index invalid! ");
    }
    return this->carti[index]->clone();
}

int Repo::find(Carte *c) {
    for(int i=0;i<this->carti.size(); i++)
    {
        if(*this->carti[i] == *c)
        {
            return i;
        }
    }
    return -1;
}

void Repo::addCarte(Carte *c) {
    if(typeid(*c) == typeid(CarteProza))
    {
        this->validatorProza.validate(c);
    }
    if(typeid(*c) == typeid(CartePoezie))
    {
        this->validatorPoezie.validate(c);
    }
    if(this->find(c) != -1)
    {
        throw RepoException("Carte nu poate fi adaugata deoarece exista deja! ");
    }
    this->carti.push_back(c->clone());
}

void Repo::deleteCarte(Carte *c) {
    bool found = false;
    for(int i=0;i<this->carti.size();i++)
    {
//        if(*this->carti[i] == *c)
        if(**(this->carti.begin() + i) == *c)
        {
            delete this->carti[i];
            this->carti.erase(this->carti.begin() + i);
            i--;
            found = true;
            break;
        }
    }
    if(!found)
    {
        throw RepoException("Cartea nu poate fi stearsa deoarece nu exista! ");
    }
}

void Repo::empty() {
    for(int i=0;i<this->carti.size();i++)
    {
        if(this->carti[i] != NULL)
        {
            delete this->carti[i];
            this->carti[i] = NULL;
        }
    }
    this->carti.clear();
}

