//
// Created by Alexie on 5/19/2021.
//

#ifndef PROIECT_TESTSERVICE_H
#define PROIECT_TESTSERVICE_H


class TestService {
private:
    static void testGetAll();
    static void testGetAllProza();
    static void testGetAllPoezie();
    static void testAddCarteProza();
    static void testAddCartePoezie();
    static void testDeleteCarte();
    static void testSortByPrice();
    static void testSortByPricePoezie();
    static void testSortByPriceProza();
    static void testFilterByAuthor();
    static void testSearchByPrice();
public:
    TestService();
    ~TestService();
    void testAll();
};


#endif //PROIECT_TESTSERVICE_H
