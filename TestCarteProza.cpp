//
// Created by Alexie on 5/18/2021.
//

#include "TestCarteProza.h"
#include <cassert>
void TestCarteProza::testImplicitConstructor() {
    CarteProza c;
    assert(c.getCod() == 0);
    assert(c.getTitlu().empty());
    assert(c.getAutor().empty());
    assert(c.getPret() == 0);
    assert(c.getNrPagini() == 0);
}

void TestCarteProza::testAll() {
    this->testImplicitConstructor();
    this->testConstructorWithParameters();
    this->testCopyConstructor();
    this->testClone();
    this->testGetNrPagini();
    this->testSetNrPagini();
    this->testAssignmentOperator();
    this->testEqualityOperator();
    this->testToString();
}

void TestCarteProza::testConstructorWithParameters() {
    CarteProza c(1,"Marile Sperante", "Charles Dickens", 50, 350);
    assert(c.getCod() == 1);
    assert(c.getTitlu() == "Marile Sperante");
    assert(c.getAutor() == "Charles Dickens");
    assert(c.getPret() == 50);
    assert(c.getNrPagini() == 350);
}

void TestCarteProza::testCopyConstructor() {
    CarteProza c1(1,"Marile Sperante", "Charles Dickens", 50, 350);
    CarteProza c2(c1);
    assert(c2.getCod() == c1.getCod());
    assert(c2.getTitlu() == c1.getTitlu());
    assert(c2.getAutor() == c1.getAutor());
    assert(c2.getPret() == c1.getPret());
    assert(c2.getNrPagini() == c1.getNrPagini());
}

void TestCarteProza::testClone() {
    CarteProza c(1,"Marile Sperante", "Charles Dickens", 50, 350);
    CarteProza* cClone = (CarteProza*)c.clone();
    assert(c == *cClone);
    assert(&c != cClone);
}

void TestCarteProza::testGetNrPagini() {
    CarteProza c(1,"Marile Sperante", "Charles Dickens", 50, 350);
    assert(c.getNrPagini() == 350);
}

void TestCarteProza::testSetNrPagini() {
    CarteProza c;
    c.setNrPagini(200);
    assert(c.getNrPagini() == 200);
}

void TestCarteProza::testAssignmentOperator() {
    CarteProza c1(1,"Marile Sperante", "Charles Dickens", 50, 350);
    CarteProza c2;
    c2 = c1;
    assert(c2.getCod() == c1.getCod());
    assert(c2.getTitlu() == c1.getTitlu());
    assert(c2.getAutor() == c1.getAutor());
    assert(c2.getPret() == c1.getPret());
    assert(c2.getNrPagini() == c1.getNrPagini());
}

void TestCarteProza::testEqualityOperator() {
    CarteProza c1(1,"Marile Sperante", "Charles Dickens", 50, 350);
    CarteProza c2 = c1;
    assert(c1 == c2);
    c2.setNrPagini(200);
    assert(!(c1 == c2));
    c2.setNrPagini(c1.getNrPagini());
    assert(c1 == c2);
}

void TestCarteProza::testToString() {
    CarteProza c(1,"Marile Sperante", "Charles Dickens", 50, 350);
    assert(c.toString() == "1, Marile Sperante, Charles Dickens, 50, 350");
    assert(c.toString(true) == "Proza, 1, Marile Sperante, Charles Dickens, 50, 350");
}
