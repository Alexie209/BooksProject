//
// Created by Alexie on 5/18/2021.
//

#include "RepoFile.h"
#include <fstream>
#include "CarteProza.h"
#include "CartePoezie.h"
#include "RepoException.h"
#include "ValidationException.h"
#include "ReadFromFileException.h"
RepoFile::RepoFile(string fileName) {
    this->fileName = fileName;
    this->loadFromFile();
}

RepoFile::~RepoFile() {

}

void RepoFile::setFileName(string fileName) {
    this->fileName = fileName;
}

void RepoFile::addCarte(Carte *c) {
    Repo::addCarte(c);
    this->saveToFile();
}

void RepoFile::deleteCarte(Carte *c) {
    Repo::deleteCarte(c);
    this->saveToFile();
}

void RepoFile::loadFromFile() {
    ifstream f(this->fileName);
    if(f.is_open())
    {
        this->empty();
        string linie;
        string delim = ", ";

        try {
            while(getline(f, linie))
            {
                if(linie. substr(0,5) == "Proza")
                {
                    linie = linie.erase(0,7);

                    int pos = linie.find(delim);
                    int cod = stoi(linie.substr(0, pos));
                    linie = linie.erase(0, pos+2);

                    pos = linie.find(delim);
                    string titlu = linie.substr(0, pos);
                    linie= linie.erase(0, pos+2);

                    pos = linie.find(delim);
                    string autor = linie.substr(0,pos);
                    linie = linie.erase(0, pos+2);

                    pos = linie.find(delim);
                    int pret = stoi(linie.substr(0, pos));
                    linie = linie.erase(0,pos+2);

                    int nr_pagini = stoi(linie);

                    CarteProza* cPr = new CarteProza(cod, titlu, autor, pret, nr_pagini);
                    this->validatorProza.validate(cPr);
                    this->carti.push_back(cPr);
                }
            else
                {
                    if(linie.substr(0, 6) == "Poezie")
                    {
                        linie = linie.erase(0,8);

                        int pos =linie.find(delim);
                        int cod = stoi(linie.substr(0,pos));
                        linie = linie.erase(0, pos+2);

                        pos = linie.find(delim);
                        string titlu = linie.substr(0, pos);
                        linie= linie.erase(0, pos+2);

                        pos = linie.find(delim);
                        string autor = linie.substr(0,pos);
                        linie = linie.erase(0, pos+2);

                        pos = linie.find(delim);
                        int pret = stoi(linie.substr(0, pos));
                        linie = linie.erase(0,pos+2);

                        string editura = linie;

                        CartePoezie* cPo = new CartePoezie(cod, titlu, autor, pret, editura);
                        this->validatorPoezie.validate(cPo);
                        this->carti.push_back(cPo);
                    }
                }
            }
        }
        catch (...)
        {
            throw ReadFromFileException("formatul datelor din fisier este invalid!");
        }
        f.close();
    } else{
        throw ReadFromFileException ("fisierul nu exista! ");
    }
}

void RepoFile::saveToFile() {
    ofstream f(this->fileName);
    if(f.is_open())
    {
        for(Carte* carte : this->carti)
        {
            f << carte->toString(true) << endl;
        }
    }
}
