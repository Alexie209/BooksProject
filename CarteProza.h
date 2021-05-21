//
// Created by Alexie on 5/18/2021.
//

#ifndef PROIECT_CARTEPROZA_H
#define PROIECT_CARTEPROZA_H
#include "Carte.h"

class CarteProza : public Carte {
private:
    int nr_pagini;
public:
    CarteProza();
    CarteProza(int cod, string titlu, string autor, int pret, int nr_pagini);
    CarteProza(const CarteProza& c);
    ~CarteProza();

    int getNrPagini();
    void setNrPagini(int nrPagini);

    Carte* clone();

    CarteProza& operator=(const CarteProza& c);
    bool operator==(const CarteProza& c);

    string toString(bool forFile = false);
};


#endif //PROIECT_CARTEPROZA_H
