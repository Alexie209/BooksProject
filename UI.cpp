//
// Created by Alexie on 5/19/2021.
//

#include "UI.h"
#include "RepoException.h"
#include "ValidationException.h"

void UI::displayMenu() {
    cout << "\n------------MENU------------\n";
    cout << "1. Adaugare carte proza\n";
    cout << "2. Adaugare carte poezie\n";
    cout << "3. Stergere carte\n";
    cout << "4. Ordonare carti (de poezie sau de proza) dupa pret\n";
    cout << "5. Filtrare carti dupa autor\n";
    cout << "6. Cautarea cartilor cu pretul cuprins intr-un interval dat\n";
    cout << "-----------------\n";
    cout << "a. Afisare toate cartile\n";
    cout << "a1. Afisare toate cartile de proza\n";
    cout << "a2. Afisare toate cartile de poezie\n";
    cout << "-----------------\n";
    cout << "x. Iesire\n";
    cout << "-----------------\n";
}

void UI::printCarti(vector<Carte *> carti) {
    cout<<endl;
    for(int i=0;i<carti.size();i++)
    {
        cout << carti[i]->toString() << endl;
    }
}

void UI::uiShowAll() {
    this->printCarti(this->service.getAll());
}

void UI::uiAddCarteProza() {
    cout<<"Dati codul: ";
    int cod;
    cin>>cod;

    cout<<"Dati titlul cartii: ";
    string titlu;
    cin.get();
    getline(cin, titlu);


    cout<<"Dati autorul cartii: ";
    string autor;
    getline(cin, autor);

    cout<<"Dati pretul cartii: ";
    int pret;
    cin>>pret;

    cout<<"Dati numarul de pagini: ";
    int nr_pagini;
    cin>>nr_pagini;
    cin.ignore();

    try {
        this->service.addCarteProza(cod, titlu, autor, pret, nr_pagini);
        cout<<"\nCartea a fost adaugata cu succes!\n";
    }
    catch (RepoException& e)
    {
        cout<<e.what()<<endl;
    }
    catch (ValidationException& e)
    {
        cout<<e.what()<<endl;
    }
}

void UI::uiAddCartePoezie() {
    cout<<"Dati codul: ";
    int cod;
    cin>>cod;

    cout<<"Dati titlul cartii: ";
    string titlu;
    cin.get();
    getline(cin, titlu);

    cout<<"Dati autorul cartii: ";
    string autor;
    getline(cin, autor);

    cout<<"Dati pretul cartii: ";
    int pret;
    cin>>pret;

    cout<<"Dati editura cartii: ";
    string editura;
    cin.ignore();
    getline(cin, editura);

    try {
        this->service.addCartePoezie(cod, titlu, autor, pret, editura);
        cout<<"\nCartea a fost adaugata cu succes!\n";
    }
    catch (RepoException& e)
    {
        cout<<e.what()<<endl;
    }
    catch (ValidationException& e)
    {
        cout<<e.what()<<endl;
    }
}

void UI::uiDeleteCarte() {
    cout<<"Dati codul cartii care se va sterge: ";
    int cod;
    cin>>cod;
    try {
        this->service.deleteCarte(cod);
        cout<<"\nCartea a fost stearsa cu succes!\n";
    }
    catch (RepoException& e) {
        cout << e.what() << endl;
    }
}

UI::UI() {

}

UI::UI(Service &service) {
    this->service = service;
}

UI::~UI() {

}

void UI::runMenu() {
    string option;
    while(true)
    {
        this->displayMenu();
        cout<<"Dati optiunea: ";
        cin>>option;
        cin.ignore();
        if(option == "1")
        {
            this->uiAddCarteProza();
        }
        else if(option == "2")
        {
            this->uiAddCartePoezie();
        }
        else if(option == "3")
        {
            this->uiDeleteCarte();
        }
        else if(option == "4")
        {
            this->uiSort();
        }
        else if(option == "5")
        {
            this->uiFilterByAuthor();
        }
        else if(option == "6")
        {
            this->uiSearchByPrice();
        }
        else if (option == "a")
        {
            this->uiShowAll();
        }
        else if(option == "a1")
        {
            this->uiShowAllProza();
        }
        else if(option == "a2")
        {
            this->uiShowAllPoezie();
        }
        else if (option == "x")
        {
            break;
        }
        else
        {
            cout<<"Optiune invalida! Reincercati!\n";
        }
    }
}
void UI::uiSort() {
    string option;
    while(true)
    {
        cout << "\n1. Ordonare carti proza\n";
        cout << "2. Ordonare carti poezie\n";
        cout << "3. Ordonare toate cartile\n";
        cout << "-----------------\n";
        cout << "x. Inapoi\n";
        cout << "-----------------\n";
        cout << "Dati optiunea: ";
        cin >> option;
        cin.ignore();
        if(option == "1")
        {
            this->uiSortByPriceProza();
        }
        else if(option == "2")
        {
            this->uiSortByPricePoezie();
        }
        else if(option == "3")
        {
            this->uiSortByPrice();
        }
        else if (option == "x")
        {
            break;
        }
        else
        {
            cout<<"Optiune invalida! Reincercati!\n";
        }

    }
}

void UI::uiSortByPrice() {
    cout<<endl;
    this->printCarti(this->service.sortByPrice());
    cout<<endl;
}

void UI::uiSortByPriceProza() {
    cout<<endl;
    this->printCarti(this->service.sortByPriceProza());
    cout<<endl;
}

void UI::uiSortByPricePoezie() {
    cout<<endl;
    this->printCarti(this->service.sortByPricePoezie());
    cout<<endl;
}


void UI::uiFilterByAuthor() {
    cout << "Dati numele autorului: ";
    string author;
    getline(cin, author);
    cout<<endl;
    this->printCarti(this->service.filterByAuthor(author));
    cout<<endl;
}

void UI::uiSearchByPrice() {
    int lowerBound, upperBound;
    cout << "Dati limita inferioara: ";
    cin >> lowerBound;
    do {
        cout << "Dati limita superioara: ";
        cin >> upperBound;
    }while (upperBound < lowerBound);
    cout<<endl;
    this->printCarti(this->service.searchByPrice(lowerBound, upperBound));
    cout<<endl;
}

void UI::uiShowAllProza() {
    cout<<endl;
    this->printCarti(this->service.getAllProza());
    cout<<endl;
}

void UI::uiShowAllPoezie() {
    cout<<endl;
    this->printCarti(this->service.getAllPoezie());
    cout<<endl;
}

