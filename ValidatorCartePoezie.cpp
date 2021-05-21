//
// Created by Alexie on 5/18/2021.
//

#include "ValidatorCartePoezie.h"
#include "ValidationException.h"
#include "CartePoezie.h"

ValidatorCartePoezie::ValidatorCartePoezie() {

}

ValidatorCartePoezie::~ValidatorCartePoezie() {

}

void ValidatorCartePoezie::validate(Carte *c) {
    string errorMessage ="";
    try {
        ValidatorCarte::validate(c);
    }
    catch (ValidationException& e)
    {
        errorMessage += e.what();
    }
    CartePoezie* cPo = (CartePoezie*)c;
    if(cPo->getEditura().empty())
    {
        errorMessage += "Editura cartii nu poate fi string gol!\n";
    }

    if(errorMessage.length() > 0)
    {
        throw ValidationException(errorMessage);
    }
}
