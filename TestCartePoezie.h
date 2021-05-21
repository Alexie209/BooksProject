//
// Created by Alexie on 5/18/2021.
//

#ifndef PROIECT_TESTCARTEPOEZIE_H
#define PROIECT_TESTCARTEPOEZIE_H
#include "CartePoezie.h"

class TestCartePoezie {
private:
    static void testImplicitConstructor();
    static void testConstructorWithParameters();
    static void testCopyConstructor();
    static void testClone();
    static void testGetEditura();
    static void testSetEditura();
    static void testAssignmentOperator();
    static void testEqualityOperator();
    static void testToString();
public:
    void testAll();
};


#endif //PROIECT_TESTCARTEPOEZIE_H
