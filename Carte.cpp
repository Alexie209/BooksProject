//
// Created by Alexie on 5/18/2021.
//

#include "Carte.h"

Carte::Carte() {
    this->cod = 0;
    this->titlu = "";
    this->autor = "";
    this->pret = 0;
}

Carte::Carte(int cod, string titlu, string autor, int pret) {
    this->cod = cod;
    this->titlu = titlu;
    this->autor = autor;
    this->pret = pret;
}

Carte::Carte(Carte &c) {
    this->cod = c.cod;
    this->titlu = c.titlu;
    this->autor = c.autor;
    this->pret = c.pret;
}

Carte::~Carte() {

}

int Carte::getCod() {
    return this->cod;
}

void Carte::setCod(int cod) {
    this->cod = cod;
}

string Carte::getTitlu() {
    return this->titlu;
}

void Carte::setTitlu(string titlu) {
    this->titlu = titlu;
}

string Carte::getAutor() {
    return this->autor;
}

void Carte::setAutor(string autor) {
    this->autor = autor;
}

int Carte::getPret() {
    return this->pret;
}

void Carte::setPret(int pret) {
    this->pret = pret;
}

Carte *Carte::clone() {
    return new Carte(cod, titlu, autor, pret);
}

Carte &Carte::operator=(const Carte &c) {
    if(&c != this)
    {
        this->setCod(c.cod);
        this->setTitlu(c.titlu);
        this->setAutor(c.autor);
        this->setPret(c.pret);
    }
    return *this;
}

bool Carte::operator==(const Carte &c) {
    return this->cod == c.cod && this->titlu == c.titlu && this->autor == c.autor &&
        this->pret == c.pret;
}

string Carte::toString(bool forFile) {
    return to_string(this->cod) + ", " + this->titlu + ", " + this->autor + ", " + to_string(this->pret);
}
