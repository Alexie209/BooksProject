//
// Created by Alexie on 5/18/2021.
//

#include "CarteProza.h"

CarteProza::CarteProza() : Carte() {
    this->nr_pagini = 0;
}

CarteProza::CarteProza(int cod, string titlu, string autor, int pret, int nr_pagini) : Carte(cod,
                                                                                             titlu,
                                                                                             autor,
                                                                                             pret) {
    this->nr_pagini = nr_pagini;
}

CarteProza::CarteProza(const CarteProza &c) : Carte((Carte &) c) {
    this->nr_pagini = c.nr_pagini;
}

CarteProza::~CarteProza() {

}

int CarteProza::getNrPagini() {
    return this->nr_pagini;
}

void CarteProza::setNrPagini(int nrPagini) {
    this->nr_pagini = nrPagini;
}

Carte *CarteProza::clone() {
    return new CarteProza(this->cod, this->titlu, this->autor, this->pret, this->nr_pagini);
}

CarteProza &CarteProza::operator=(const CarteProza &c) {
    if(&c != this)
    {
        Carte::operator=(c);
        this->setNrPagini(c.nr_pagini);
    }
    return *this;
}

bool CarteProza::operator==(const CarteProza &c) {
    return Carte::operator==(c) && this->nr_pagini == c.nr_pagini;
}

string CarteProza::toString(bool forFile) {
    string result =Carte::toString() + ", " + to_string(this->nr_pagini);
    if(forFile)
    {
        result = "Proza, " + result;
    }
    return result;
}
