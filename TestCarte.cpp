//
// Created by Alexie on 5/18/2021.
//

#include "TestCarte.h"
#include <cassert>
void TestCarte::testImplicitConstructor() {
    Carte c;
    assert(c.getCod() == 0);
    assert(c.getTitlu().empty());
    assert(c.getAutor().empty());
    assert(c.getPret() == 0);
}

void TestCarte::testConstructorWithParameters() {
    Carte c(1,"Marile Sperante","Charles Dickens", 50);
    assert(c.getCod() == 1);
    assert(c.getTitlu() == "Marile Sperante");
    assert(c.getAutor() == "Charles Dickens");
    assert(c.getPret() == 50);
}

void TestCarte::testCopyConstructor() {
    Carte c1(1,"Marile Sperante","Charles Dickens", 50);
    Carte c2(c1);
    assert(c2.getCod() == c1.getCod());
    assert(c2.getTitlu() == c1.getTitlu());
    assert(c2.getAutor() == c1.getAutor());
    assert(c2.getPret() == c1.getPret());
}

void TestCarte::testClone() {
    Carte c(1,"Marile Sperante","Charles Dickens", 50);
    Carte* cClone = c.clone();
    assert(c == *cClone);
    assert(&c != cClone);
}

void TestCarte::testGetCod() {
    Carte c(1,"Marile Sperante","Charles Dickens", 50);
    assert(c.getCod() == 1);
}

void TestCarte::testSetCod() {
    Carte c;
    c.setCod(10);
    assert(c.getCod() == 10);
}

void TestCarte::testGetTitlu() {
    Carte c(1,"Marile Sperante","Charles Dickens", 50);
    assert(c.getTitlu() == "Marile Sperante");
}

void TestCarte::testSetTitlu() {
    Carte c;
    c.setTitlu("Marile Sperante");
    assert(c.getTitlu() == "Marile Sperante");
}

void TestCarte::testGetAutor() {
    Carte c(1,"Marile Sperante","Charles Dickens", 50);
    assert(c.getAutor() == "Charles Dickens");
}

void TestCarte::testSetAutor() {
    Carte c;
    c.setAutor("Charles Dickens");
    assert(c.getAutor() == "Charles Dickens");
}

void TestCarte::testGetPret() {
    Carte c(1,"Marile Sperante","Charles Dickens", 50);
    assert(c.getPret() == 50);
}

void TestCarte::testSetPret() {
    Carte c;
    c.setPret(50);
    assert(c.getPret() == 50);
}

void TestCarte::testAssignmentOperator() {
    Carte c1(1,"Marile Sperante","Charles Dickens", 50);
    Carte c2;
    c2 = c1;
    assert(c2.getCod() == c1.getCod());
    assert(c2.getTitlu() == c1.getTitlu());
    assert(c2.getAutor() == c1.getAutor());
    assert(c2.getPret() == c1.getPret());
}

void TestCarte::testEqualityOperator() {
    Carte c1(1,"Marile Sperante","Charles Dickens", 50);
    Carte c2 = c1;
    assert(c1 == c2);
    c2.setCod(2);
    assert(!(c1 == c2));
    c2.setCod(c1.getCod());
    assert(c1 == c2);
    c2.setTitlu("Luceafarul");
    assert(!(c1 == c2));
    c2.setTitlu(c1.getTitlu());
    assert(c1 == c2);
}

void TestCarte::testToString() {
    Carte c(1,"Marile Sperante","Charles Dickens", 50);
    assert(c.toString() == "1, Marile Sperante, Charles Dickens, 50");
}

void TestCarte::testAll() {
    this->testImplicitConstructor();
    this->testConstructorWithParameters();
    this->testCopyConstructor();
    this->testClone();
    this->testGetCod();
    this->testSetCod();
    this->testGetTitlu();
    this->testSetTitlu();
    this->testGetAutor();
    this->testSetAutor();
    this->testGetPret();
    this->testSetPret();
    this->testAssignmentOperator();
    this->testEqualityOperator();
    this->testToString();
}


