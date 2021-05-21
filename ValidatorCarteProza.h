//
// Created by Alexie on 5/18/2021.
//

#ifndef PROIECT_VALIDATORCARTEPROZA_H
#define PROIECT_VALIDATORCARTEPROZA_H
#include "ValidatorCarte.h"

class ValidatorCarteProza : public ValidatorCarte{
public:
    ValidatorCarteProza();
    ~ValidatorCarteProza();
    void validate(Carte *c);
};


#endif //PROIECT_VALIDATORCARTEPROZA_H
