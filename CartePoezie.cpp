//
// Created by Alexie on 5/18/2021.
//

#include "CartePoezie.h"

CartePoezie::CartePoezie() : Carte(){
    this->editura = "";
}

CartePoezie::CartePoezie(int cod, string titlu, string autor, int pret, string editura) :Carte(cod,
                                                                                               titlu,
                                                                                               autor,
                                                                                               pret) {
    this->editura = editura;
}

CartePoezie::CartePoezie(const CartePoezie &c) : Carte((Carte &) c){
    this->editura = c.editura;
}

CartePoezie::~CartePoezie() {

}

string CartePoezie::getEditura() {
    return this->editura;
}

void CartePoezie::setEditura(string editura) {
    this->editura = editura;
}

Carte *CartePoezie::clone() {
    return new CartePoezie(this->cod, this->titlu, this->autor, this->pret, this->editura);
}

CartePoezie &CartePoezie::operator=(const CartePoezie &c) {
    if(&c != this)
    {
        Carte::operator=(c);
        this->setEditura(c.editura);
    }
    return *this;
}

bool CartePoezie::operator==(const CartePoezie &c) {
    return Carte::operator==(c) && this->editura == c.editura;
}

string CartePoezie::toString(bool forFile) {
    string result = Carte::toString() + ", " + this->editura;
    if(forFile)
    {
        result = "Poezie, " + result;
    }
    return result;
}
