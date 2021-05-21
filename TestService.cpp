//
// Created by Alexie on 5/19/2021.
//

#include <cassert>
#include "TestService.h"
#include "Repo.h"
#include "Service.h"


void TestService::testGetAll() {
    Repo* repo = new Repo();
    Service serv(repo);

    CarteProza* c1 = new CarteProza(1,"Marile Sperante", "Charles Dickens", 50, 350);
    CartePoezie* c2 = new CartePoezie(2,"Luceafarul","Mihai Eminescu", 20, "Corint");
    serv.addCarteProza(c1->getCod(),c1->getTitlu(),c1->getAutor(),c1->getPret(),c1->getNrPagini());
    serv.addCartePoezie(c2->getCod(),c2->getTitlu(),c2->getAutor(),c2->getPret(),c2->getEditura());
    vector<Carte*> carti = serv.getAll();
    assert(*carti[0] == *c1);
    assert(*carti[1] == *c2);
}

void TestService::testAddCarteProza() {
    Repo* repo = new Repo();
    Service service(repo);

    CarteProza* c = new CarteProza(1,"Marile Sperante", "Charles Dickens", 50, 350);
    service.addCarteProza(c->getCod(),c->getTitlu(),c->getAutor(),c->getPret(),c->getNrPagini());
    assert(*service.getAll()[0] == *c);
}

void TestService::testAddCartePoezie() {
    Repo* repo = new Repo();
    Service service(repo);

    CartePoezie* c2 = new CartePoezie(2,"Luceafarul","Mihai Eminescu", 20, "Corint");
    service.addCartePoezie(c2->getCod(),c2->getTitlu(),c2->getAutor(),c2->getPret(),c2->getEditura());
    assert(*service.getAll()[0] == *c2);
}

void TestService::testDeleteCarte() {
    Repo* repo = new Repo();
    Service service(repo);

    CartePoezie* c2 = new CartePoezie(2,"Luceafarul","Mihai Eminescu", 20, "Corint");
    service.addCartePoezie(c2->getCod(),c2->getTitlu(),c2->getAutor(),c2->getPret(),c2->getEditura());

    service.deleteCarte(1);
    vector<Carte*> carti = service.getAll();
    assert(carti.size() == 1);

    service.deleteCarte(c2->getCod());

}

TestService::TestService() = default;

TestService::~TestService() = default;

void TestService::testAll() {
    this->testGetAll();
    this->testAddCarteProza();
    this->testAddCartePoezie();
    this->testDeleteCarte();
    this->testSortByPrice();
    this->testFilterByAuthor();
    this->testSearchByPrice();
    this->testGetAllProza();
    this->testGetAllPoezie();
    this->testSortByPriceProza();
    this->testSortByPricePoezie();
}

void TestService::testSortByPrice() {
    Repo* repo = new Repo();
    Service service(repo);

    CarteProza* c1 = new CarteProza(1,"Marile Sperante", "Charles Dickens", 50, 350);
    CartePoezie* c2 = new CartePoezie(2,"Luceafarul","Mihai Eminescu", 20, "Corint");
    CarteProza* c3 = new CarteProza(3, "Ion", "Liviu Rebreanu", 70, 201);

    service.addCarteProza(c1->getCod(), c1->getTitlu(), c1->getAutor(), c1->getPret(), c1->getNrPagini());
    service.addCartePoezie(c2->getCod(), c2->getTitlu(), c2->getAutor(), c2->getPret(), c2->getEditura());
    service.addCarteProza(c3->getCod(), c3->getTitlu(), c3->getAutor(), c3->getPret(), c3->getNrPagini());

    vector<Carte*> sortResult = service.sortByPrice();
    assert(*sortResult[0] == *c2);
    assert(*sortResult[1] == *c1);
    assert(*sortResult[2] == *c3);
}
void TestService::testSortByPriceProza() {
    Repo* repo = new Repo();
    Service service(repo);

    CarteProza* c1 = new CarteProza(1,"Marile Sperante", "Charles Dickens", 50, 350);
    CartePoezie* c2 = new CartePoezie(2,"Luceafarul","Mihai Eminescu", 20, "Corint");
    CarteProza* c3 = new CarteProza(3, "Ion", "Liviu Rebreanu", 70, 201);
    CartePoezie* c4 = new CartePoezie(4, "Scrisoarea I", "Mihai Eminescu", 17, "Casa Buna");
    CarteProza* c5 = new CarteProza(5, "Moara cu norc", "Ioan Slavici", 63, 233);

    service.addCarteProza(c1->getCod(), c1->getTitlu(), c1->getAutor(), c1->getPret(), c1->getNrPagini());
    service.addCartePoezie(c2->getCod(), c2->getTitlu(), c2->getAutor(), c2->getPret(), c2->getEditura());
    service.addCarteProza(c3->getCod(), c3->getTitlu(), c3->getAutor(), c3->getPret(), c3->getNrPagini());
    service.addCartePoezie(c4->getCod(), c4->getTitlu(), c4->getAutor(), c4->getPret(), c4->getEditura());
    service.addCarteProza(c5->getCod(), c5->getTitlu(), c5->getAutor(), c5->getPret(), c5->getNrPagini());

    vector<Carte*> sortResult = service.sortByPriceProza();
    assert(sortResult.size() == 3);
    assert(*sortResult[0] == *c1);
    assert(*sortResult[1] == *c5);
    assert(*sortResult[2] == *c3);
}

void TestService::testSortByPricePoezie() {
    Repo* repo = new Repo();
    Service service(repo);

    CarteProza* c1 = new CarteProza(1,"Marile Sperante", "Charles Dickens", 50, 350);
    CartePoezie* c2 = new CartePoezie(2,"Luceafarul","Mihai Eminescu", 20, "Corint");
    CarteProza* c3 = new CarteProza(3, "Ion", "Liviu Rebreanu", 70, 201);
    CartePoezie* c4 = new CartePoezie(4, "Scrisoarea I", "Mihai Eminescu", 17, "Casa Buna");
    CarteProza* c5 = new CarteProza(5, "Moara cu norc", "Ioan Slavici", 63, 233);

    service.addCarteProza(c1->getCod(), c1->getTitlu(), c1->getAutor(), c1->getPret(), c1->getNrPagini());
    service.addCartePoezie(c2->getCod(), c2->getTitlu(), c2->getAutor(), c2->getPret(), c2->getEditura());
    service.addCarteProza(c3->getCod(), c3->getTitlu(), c3->getAutor(), c3->getPret(), c3->getNrPagini());
    service.addCartePoezie(c4->getCod(), c4->getTitlu(), c4->getAutor(), c4->getPret(), c4->getEditura());
    service.addCarteProza(c5->getCod(), c5->getTitlu(), c5->getAutor(), c5->getPret(), c5->getNrPagini());

    vector<Carte*> sortResult = service.sortByPricePoezie();
    assert(sortResult.size() == 2);
    assert(*sortResult[0] == *c4);
    assert(*sortResult[1] == *c2);
}

void TestService::testFilterByAuthor() {
    Repo* repo = new Repo();
    Service service(repo);

    CarteProza* c1 = new CarteProza(1,"Marile Sperante", "Charles Dickens", 50, 350);
    CartePoezie* c2 = new CartePoezie(2,"Luceafarul","Mihai Eminescu", 20, "Corint");
    CarteProza* c3 = new CarteProza(3, "Ion", "Liviu Rebreanu", 70, 201);
    CartePoezie* c4 = new CartePoezie(4, "Scrisoarea I", "Mihai Eminescu", 17, "Casa Buna");

    service.addCarteProza(c1->getCod(), c1->getTitlu(), c1->getAutor(), c1->getPret(), c1->getNrPagini());
    service.addCartePoezie(c2->getCod(), c2->getTitlu(), c2->getAutor(), c2->getPret(), c2->getEditura());
    service.addCarteProza(c3->getCod(), c3->getTitlu(), c3->getAutor(), c3->getPret(), c3->getNrPagini());
    service.addCartePoezie(c4->getCod(), c4->getTitlu(), c4->getAutor(), c4->getPret(), c4->getEditura());

    vector<Carte*> filterResult = service.filterByAuthor("Mihai Eminescu");
    assert(filterResult.size() == 2);
    assert(*filterResult[0] == *c2);
    assert(*filterResult[1] == *c4);

    vector<Carte*> filterResult2 = service.filterByAuthor("Liviu Rebreanu");
    assert(filterResult2.size() == 1);
    assert(*filterResult2[0] == *c3);

    vector<Carte*> filterResult3 = service.filterByAuthor("Charles Dickens");
    assert(filterResult3.size() == 1);
    assert(*filterResult3[0] == *c1);
}

void TestService::testSearchByPrice() {
    Repo* repo = new Repo();
    Service service(repo);

    CarteProza* c1 = new CarteProza(1,"Marile Sperante", "Charles Dickens", 50, 350);
    CartePoezie* c2 = new CartePoezie(2,"Luceafarul","Mihai Eminescu", 20, "Corint");
    CarteProza* c3 = new CarteProza(3, "Ion", "Liviu Rebreanu", 70, 201);
    CartePoezie* c4 = new CartePoezie(4, "Scrisoarea I", "Mihai Eminescu", 17, "Casa Buna");

    service.addCarteProza(c1->getCod(), c1->getTitlu(), c1->getAutor(), c1->getPret(), c1->getNrPagini());
    service.addCartePoezie(c2->getCod(), c2->getTitlu(), c2->getAutor(), c2->getPret(), c2->getEditura());
    service.addCarteProza(c3->getCod(), c3->getTitlu(), c3->getAutor(), c3->getPret(), c3->getNrPagini());
    service.addCartePoezie(c4->getCod(), c4->getTitlu(), c4->getAutor(), c4->getPret(), c4->getEditura());

    vector<Carte*> searchResult = service.searchByPrice(0, 15);
    assert(searchResult.size() == 0);

    vector<Carte*> searchResult2 = service.searchByPrice(71, 100);
    assert(searchResult2.size() == 0);

    vector<Carte*> searchResult3 = service.searchByPrice(60, 100);
    assert(searchResult3.size() == 1);
    assert(*searchResult3[0] == *c3);

    vector<Carte*> searchResult4 = service.searchByPrice(20, 75);
    assert(searchResult4.size() == 3);
    assert(*searchResult4[0] == *c1);
    assert(*searchResult4[1] == *c2);
    assert(*searchResult4[2] == *c3);
}

void TestService::testGetAllProza() {
    Repo* repo = new Repo();
    Service service(repo);

    CarteProza* c1 = new CarteProza(1,"Marile Sperante", "Charles Dickens", 50, 350);
    CartePoezie* c2 = new CartePoezie(2,"Luceafarul","Mihai Eminescu", 20, "Corint");
    CarteProza* c3 = new CarteProza(3, "Ion", "Liviu Rebreanu", 70, 201);
    CartePoezie* c4 = new CartePoezie(4, "Scrisoarea I", "Mihai Eminescu", 17, "Casa Buna");

    service.addCarteProza(c1->getCod(), c1->getTitlu(), c1->getAutor(), c1->getPret(), c1->getNrPagini());
    service.addCartePoezie(c2->getCod(), c2->getTitlu(), c2->getAutor(), c2->getPret(), c2->getEditura());
    service.addCarteProza(c3->getCod(), c3->getTitlu(), c3->getAutor(), c3->getPret(), c3->getNrPagini());
    service.addCartePoezie(c4->getCod(), c4->getTitlu(), c4->getAutor(), c4->getPret(), c4->getEditura());

    vector<Carte*> cartiProza = service.getAllProza();
    assert(cartiProza.size() == 2);
    assert(*cartiProza[0] == *c1);
    assert(*cartiProza[1] == *c3);
}

void TestService::testGetAllPoezie() {
    Repo* repo = new Repo();
    Service service(repo);

    CarteProza* c1 = new CarteProza(1,"Marile Sperante", "Charles Dickens", 50, 350);
    CartePoezie* c2 = new CartePoezie(2,"Luceafarul","Mihai Eminescu", 20, "Corint");
    CarteProza* c3 = new CarteProza(3, "Ion", "Liviu Rebreanu", 70, 201);
    CartePoezie* c4 = new CartePoezie(4, "Scrisoarea I", "Mihai Eminescu", 17, "Casa Buna");

    service.addCarteProza(c1->getCod(), c1->getTitlu(), c1->getAutor(), c1->getPret(), c1->getNrPagini());
    service.addCartePoezie(c2->getCod(), c2->getTitlu(), c2->getAutor(), c2->getPret(), c2->getEditura());
    service.addCarteProza(c3->getCod(), c3->getTitlu(), c3->getAutor(), c3->getPret(), c3->getNrPagini());
    service.addCartePoezie(c4->getCod(), c4->getTitlu(), c4->getAutor(), c4->getPret(), c4->getEditura());

    vector<Carte*> cartiPoezie = service.getAllPoezie();
    assert(cartiPoezie.size() == 2);
    assert(*cartiPoezie[0] == *c2);
    assert(*cartiPoezie[1] == *c4);
}


