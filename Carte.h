//
// Created by Alexie on 5/18/2021.
//

#ifndef PROIECT_CARTE_H
#define PROIECT_CARTE_H
#include <string>
#include <iostream>
using namespace std;
class Carte {
protected:
    int cod;
    string titlu, autor;
    int pret;
public:
    Carte();
    Carte(int cod, string titlu, string autor, int pret);
    Carte(Carte &c);
    virtual ~Carte();

    int getCod();
    void setCod(int cod);
    string getTitlu();
    void setTitlu(string titlu);
    string getAutor();
    void setAutor(string autor);
    int getPret();
    void setPret(int pret);

    virtual Carte* clone();
    Carte& operator=(const Carte& c);
    bool operator==(const Carte& c);

    virtual string toString(bool forFile = false);
};


#endif //PROIECT_CARTE_H
