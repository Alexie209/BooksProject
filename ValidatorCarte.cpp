//
// Created by Alexie on 5/18/2021.
//

#include "ValidatorCarte.h"
#include "ValidationException.h"
#include <exception>
#include <cstring>

using namespace std;
ValidatorCarte::ValidatorCarte() {

}

ValidatorCarte::~ValidatorCarte() {

}

void ValidatorCarte::validate(Carte *c) {
    string errorMessage = "";
    if(c->getTitlu().empty())
    {
        errorMessage += "Titlul cartii nu poate fi string gol!\n";
    }
    for(char l: c->getTitlu())
    {
        if(!isspace(l) && !isalpha(l))
        {
            errorMessage += "Titlul cartii poate sa contina doar litere!\n";
            break;
        }
    }
    if(c->getAutor().empty())
    {
        errorMessage += "Numele autorului nu poate fi string gol!\n";
    }
    for(char l: c->getAutor())
    {
        if(!isspace(l) && !isalpha(l))
        {
            errorMessage += "Numele autorului poate sa contina doar litere!\n";
            break;
        }
    }
    if(c->getPret() <= 0)
    {
        errorMessage += "Pretul cartii trebuie sa fie strict pozitiv!\n";
    }
    if(errorMessage.length() > 0)
    {
        throw ValidationException(errorMessage);
    }
}
