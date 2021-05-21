//
// Created by Alexie on 5/18/2021.
//

#include "ValidatorCarteProza.h"
#include "ValidationException.h"
#include "CarteProza.h"
ValidatorCarteProza::ValidatorCarteProza() {

}

ValidatorCarteProza::~ValidatorCarteProza() {

}

void ValidatorCarteProza::validate(Carte *c) {
    string errorMessage = "";
    try {
        ValidatorCarte::validate(c);
    }
    catch (ValidationException& e) {
        errorMessage += e.what();
    }
    CarteProza* cPr = (CarteProza*)c;
    if(cPr->getNrPagini() <= 0)
    {
        errorMessage += "Numarul de pagini al cartii trebuie sa fie strict pozitiv!\n";
    }
    if(errorMessage.length() > 0)
    {
        throw ValidationException(errorMessage);
    }
}
