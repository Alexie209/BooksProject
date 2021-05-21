//
// Created by Alexie on 5/19/2021.
//

#ifndef PROIECT_UI_H
#define PROIECT_UI_H


#include "Service.h"

class UI {
private:
    Service service;
    void displayMenu();
    void printCarti(vector<Carte*> carti);
    void uiShowAll();
    void uiShowAllProza();
    void uiShowAllPoezie();
    void uiAddCarteProza();
    void uiAddCartePoezie();
    void uiDeleteCarte();
    void uiSort();
    void uiSortByPrice();
    void uiSortByPriceProza();
    void uiSortByPricePoezie();
    void uiFilterByAuthor();
    void uiSearchByPrice();

public:
    UI();
    UI(Service& service);
    ~UI();

    void runMenu();
};


#endif //PROIECT_UI_H
