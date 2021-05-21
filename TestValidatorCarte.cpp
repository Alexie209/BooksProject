//
// Created by Alexie on 5/18/2021.
//

#include "TestValidatorCarte.h"
#include <cassert>
#include "ValidationException.h"
#include "CarteProza.h"
#include "CartePoezie.h"
void TestValidatorCarte::testValidatorCarte() {
    ValidatorCarte val;
    Carte* c1 = new Carte(1,"Marile sperante","Charles Dickens", 50);
    try {
        val.validate(c1);
    }
    catch (...) {
        assert(true);
    }
    Carte* c2 = new Carte(2, "", "Charles Dickens", 50);
    try {
        val.validate(c2);
        assert(false);
    }
    catch (ValidationException& e) {}
    catch (...) {
        assert(false);
    }
    Carte* c3 = new Carte(3,"Marile Sperante", "Charles_Dickens", 50);
    try {
        val.validate(c3);
        assert(false);
    }
    catch (ValidationException& e) {}
    catch (...) {
        assert(false);
    }

    Carte* c4 = new Carte(4,"Marile Sperante", "Charles Dickens", -1);
    try {
        val.validate(c4);
        assert(false);
    }
    catch (ValidationException& e) {}
    catch (...){
        assert(false);
    }
    Carte* c5 = new Carte(5, "Marile sperante", "Charles Dickens", 0);
    try {
        val.validate(c5);
        assert(false);
    }
    catch (ValidationException& e) {}
    catch (...){
        assert(false);
    }
    delete c1;
    delete c2;
    delete c3;
    delete c4;
    delete c5;
}

void TestValidatorCarte::testValidatorCarteProza() {
    ValidatorCarteProza val;
    CarteProza* c1 = new CarteProza(1,"Marile Sperante", "Charles Dickens", 50, 350);
    try{
        val.validate(c1);
    }
    catch (...)
    {
        assert(true);
    }

    CarteProza* c2 = new CarteProza(1,"Marile Sperante", "Charles Dickens", 50, -1);
    try {
        val.validate(c2);
        assert(false);
    }
    catch (ValidationException& e) {}
    catch (...)
    {
        assert(false);
    }

    CarteProza* c3 = new CarteProza(1,"Marile Sperante", "Charles Dickens", 50, 0);
    try {
        val.validate(c3);
        assert(false);
    }
    catch (ValidationException& e) {}
    catch (...)
    {
        assert(false);
    }
    delete c1;
    delete c2;
    delete c3;
}

void TestValidatorCarte::testValidatorCartePoezie() {
    ValidatorCartePoezie val;
    CartePoezie* c1 = new CartePoezie(1,"Marile Sperante", "Charles Dickens",
                                      50, "editura1");
    try {
        val.validate(c1);
    }
    catch (...)
    {
        assert(true);
    }

    CartePoezie* c2 = new CartePoezie(1,"Marile Sperante", "Charles Dickens",
                                      50, "");
    try {
        val.validate(c2);
        assert(false);
    }
    catch (ValidationException& e) {}
    catch (...)
    {
        assert(false);
    }
}

TestValidatorCarte::TestValidatorCarte() = default;

TestValidatorCarte::~TestValidatorCarte() = default;

void TestValidatorCarte::testAll() {
    this->testValidatorCarte();
    this->testValidatorCarteProza();
    this->testValidatorCartePoezie();
}
