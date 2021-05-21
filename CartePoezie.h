//
// Created by Alexie on 5/18/2021.
//

#ifndef PROIECT_CARTEPOEZIE_H
#define PROIECT_CARTEPOEZIE_H
#include "Carte.h"

class CartePoezie : public Carte {
private:
    string editura;
public:
    CartePoezie();
    CartePoezie(int cod, string titlu, string autor, int pret, string editura);
    CartePoezie(const CartePoezie& c);
    ~CartePoezie();

    string getEditura();
    void setEditura(string editura);

    Carte* clone();

    CartePoezie& operator=(const CartePoezie& c);
    bool operator==(const CartePoezie& c);

    string toString(bool forFile = false);
};


#endif //PROIECT_CARTEPOEZIE_H
