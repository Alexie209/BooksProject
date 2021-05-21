//
// Created by Alexie on 5/18/2021.
//

#ifndef PROIECT_VALIDATORCARTEPOEZIE_H
#define PROIECT_VALIDATORCARTEPOEZIE_H
#include "ValidatorCarte.h"

class ValidatorCartePoezie : public ValidatorCarte{
public:
    ValidatorCartePoezie();
    ~ValidatorCartePoezie();
    void validate(Carte* c) override;
};


#endif //PROIECT_VALIDATORCARTEPOEZIE_H
