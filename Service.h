//
// Created by Alexie on 5/19/2021.
//

#ifndef PROIECT_SERVICE_H
#define PROIECT_SERVICE_H
#include "Repo.h"
#include "CartePoezie.h"
#include "CarteProza.h"
class Service {
private:
    Repo* repo;
public:
    Service();
    Service(Repo* repo);
    ~Service();

    vector<Carte*> getAll();
    vector<Carte*> getAllProza();
    vector<Carte*> getAllPoezie();

    void addCarteProza(int cod, string titlu, string autor, int pret, int nr_pagini);
    void addCartePoezie(int cod, string titlu, string autor, int pret, string editura);
    void deleteCarte(int cod);

    vector<Carte*> sortByPrice();
    vector<Carte*> sortByPriceProza();
    vector<Carte*> sortByPricePoezie();
    vector<Carte*> filterByAuthor(string author);
    vector<Carte*> searchByPrice(int lowerBound, int upperBound);
};
bool compareByPrice(Carte* c1, Carte* c2);



#endif //PROIECT_SERVICE_H
