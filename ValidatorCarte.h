//
// Created by Alexie on 5/18/2021.
//

#ifndef PROIECT_VALIDATORCARTE_H
#define PROIECT_VALIDATORCARTE_H
#include "Carte.h"

class ValidatorCarte {
public:
    ValidatorCarte();
    ~ValidatorCarte();

    virtual void validate(Carte* c);
};


#endif //PROIECT_VALIDATORCARTE_H
