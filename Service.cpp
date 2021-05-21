//
// Created by Alexie on 5/19/2021.
//

#include <algorithm>
#include "Service.h"
#include "CarteProza.h"
#include "CartePoezie.h"
Service::Service() {

}

Service::Service(Repo *repo) {
    this->repo = repo;
}

Service::~Service() {

}

vector<Carte *> Service::getAll() {
    return this->repo->getAll();
}

void Service::addCarteProza(int cod, string titlu, string autor, int pret, int nr_pagini) {
    CarteProza* c = new CarteProza(cod, titlu, autor, pret, nr_pagini);
    this->repo->addCarte(c);
}

void Service::addCartePoezie(int cod, string titlu, string autor, int pret, string editura) {
    CartePoezie* c = new CartePoezie(cod, titlu, autor, pret, editura);
    this->repo->addCarte(c);
}

void Service::deleteCarte(int cod) {
    vector<Carte*> carti =this->repo->getAll();
    for(int i=0;i<this->repo->getSize();i++)
    {
        if(carti[i]->getCod() == cod)
        {
            this->repo->deleteCarte(carti[i]);
            return;
        }
    }
}

bool compareByPrice(Carte* c1, Carte* c2) {
    return c1->getPret() < c2->getPret();
}

vector<Carte *> Service::sortByPrice() {
    vector<Carte*> carti = this->repo->getAll();
    sort(carti.begin(), carti.end(), compareByPrice);
    return carti;
}

vector<Carte *> Service::filterByAuthor(string author) {
    vector<Carte*> carti = this->repo->getAll();
    vector<Carte*> result;
    for(Carte* c : carti)
    {
        if(c->getAutor() == author)
        {
            result.push_back(c->clone());
        }
    }
    return result;
}

vector<Carte *> Service::searchByPrice(int lowerBound, int upperBound) {
    vector<Carte*> carti = this->repo->getAll();
    vector<Carte*> result;
    for(Carte* c: carti)
    {
        if(c->getPret() >= lowerBound && c->getPret() <= upperBound)
        {
            result.push_back(c->clone());
        }
    }
    return result;
}

vector<Carte*> Service::getAllProza() {
    vector<Carte*> result;
    vector<Carte*> carti = this->repo->getAll();
    for(Carte* c : carti)
    {
        if(typeid(*c) == typeid(CarteProza))
        {
            result.push_back(c->clone());
        }
    }
    return result;
}

vector<Carte*> Service::getAllPoezie() {
    vector<Carte*> result;
    vector<Carte*> carti = this->repo->getAll();
    for(Carte* c : carti)
    {
        if(typeid(*c) == typeid(CartePoezie))
        {
            result.push_back(c->clone());
        }
    }
    return result;
}

vector<Carte *> Service::sortByPriceProza() {
    vector<Carte*> carti = this->getAllProza();
    sort(carti.begin(), carti.end(), compareByPrice);
    return carti;
}

vector<Carte *> Service::sortByPricePoezie() {
    vector<Carte*> carti = this->getAllPoezie();
    sort(carti.begin(), carti.end(), compareByPrice);
    return carti;
}



