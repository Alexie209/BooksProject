//
// Created by Alexie on 5/18/2021.
//

#ifndef PROIECT_TESTCARTEPROZA_H
#define PROIECT_TESTCARTEPROZA_H
#include "CarteProza.h"

class TestCarteProza {
private:
    static void testImplicitConstructor();
    static void testConstructorWithParameters();
    static void testCopyConstructor();
    static void testClone();
    static void testGetNrPagini();
    static void testSetNrPagini();
    static void testAssignmentOperator();
    static void testEqualityOperator();
    static void testToString();
public:
    void testAll();
};


#endif //PROIECT_TESTCARTEPROZA_H
