//
// Created by Alexie on 5/18/2021.
//
#pragma once
#ifndef PROIECT_TESTCARTE_H
#define PROIECT_TESTCARTE_H
#include "Carte.h"
#include <cassert>
class TestCarte {
private:
    static void testImplicitConstructor();
    static void testConstructorWithParameters();
    static void testCopyConstructor();
    static void testClone();
    static void testGetCod();
    static void testSetCod();
    static void testGetTitlu();
    static void testSetTitlu();
    static void testGetAutor();
    static void testSetAutor();
    static void testGetPret();
    static void testSetPret();
    static void testAssignmentOperator();
    static void testEqualityOperator();
    static void testToString();
public:
    void testAll();
};


#endif //PROIECT_TESTCARTE_H
