//
// Created by Alexie on 5/18/2021.
//

#ifndef PROIECT_TESTVALIDATORCARTE_H
#define PROIECT_TESTVALIDATORCARTE_H
#include "ValidatorCarte.h"
#include "ValidatorCarteProza.h"
#include "ValidatorCartePoezie.h"

class TestValidatorCarte {
private:
    static void testValidatorCarte();
    static void testValidatorCarteProza();
    static void testValidatorCartePoezie();
public:
    TestValidatorCarte();
    ~TestValidatorCarte();
    void testAll();
};


#endif //PROIECT_TESTVALIDATORCARTE_H
