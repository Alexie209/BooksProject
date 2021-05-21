//
// Created by Alexie on 5/18/2021.
//

#include "TestCartePoezie.h"
#include <cassert>
void TestCartePoezie::testImplicitConstructor() {
    CartePoezie c;
    assert(c.getCod() == 0);
    assert(c.getTitlu().empty());
    assert(c.getAutor().empty());
    assert(c.getPret() == 0);
    assert(c.getEditura().empty());
}

void TestCartePoezie::testConstructorWithParameters() {
    CartePoezie c(1,"Marile Sperante", "Charles Dickens", 50, "editura1");
    assert(c.getCod() == 1);
    assert(c.getTitlu() == "Marile Sperante");
    assert(c.getAutor() == "Charles Dickens");
    assert(c.getPret() == 50);
    assert(c.getEditura() == "editura1");
}

void TestCartePoezie::testCopyConstructor() {
    CartePoezie c1(1,"Marile Sperante", "Charles Dickens", 50, "editura 1");
    CartePoezie c2(c1);
    assert(c2.getCod() == c1.getCod());
    assert(c2.getTitlu() == c1.getTitlu());
    assert(c2.getAutor() == c1.getAutor());
    assert(c2.getPret() == c1.getPret());
    assert(c2.getEditura() == c1.getEditura());
}

void TestCartePoezie::testClone() {
    CartePoezie c(1,"Marile Sperante", "Charles Dickens", 50, "editura1");
    CartePoezie* cClone = (CartePoezie*)c.clone();
    assert(c == *cClone);
    assert(&c != cClone);
}

void TestCartePoezie::testGetEditura() {
    CartePoezie c(1,"Marile Sperante", "Charles Dickens", 50, "editura1");
    assert(c.getEditura() == "editura1");
}

void TestCartePoezie::testSetEditura() {
    CartePoezie c;
    c.setEditura("editura1");
    assert(c.getEditura() == "editura1");
}

void TestCartePoezie::testAssignmentOperator() {
    CartePoezie c1(1,"Marile Sperante", "Charles Dickens", 50, "editura1");
    CartePoezie c2;
    c2 = c1;
    assert(c2.getCod() == c1.getCod());
    assert(c2.getTitlu() == c1.getTitlu());
    assert(c2.getAutor() == c1.getAutor());
    assert(c2.getPret() == c1.getPret());
    assert(c2.getEditura() == c1.getEditura());
}

void TestCartePoezie::testEqualityOperator() {
    CartePoezie c1(1,"Marile Sperante", "Charles Dickens", 50, "editura1");
    CartePoezie c2 = c1;
    assert(c1 == c2);
    c2.setEditura("edit2");
    assert(!(c1 == c2));
    c2.setEditura(c1.getEditura());
    assert(c1 == c2);
}

void TestCartePoezie::testToString() {
    CartePoezie c(1,"Marile Sperante", "Charles Dickens", 50, "editura1");
    assert(c.toString() == "1, Marile Sperante, Charles Dickens, 50, editura1");
    assert(c.toString(true) == "Poezie, 1, Marile Sperante, Charles Dickens, 50, editura1");
}

void TestCartePoezie::testAll() {
    this->testImplicitConstructor();
    this->testConstructorWithParameters();
    this->testCopyConstructor();
    this->testGetEditura();
    this->testSetEditura();
    this->testClone();
    this->testAssignmentOperator();
    this->testEqualityOperator();
    this->testToString();
}
