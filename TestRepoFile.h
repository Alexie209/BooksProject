//
// Created by Alexie on 5/19/2021.
//

#ifndef PROIECT_TESTREPOFILE_H
#define PROIECT_TESTREPOFILE_H
#include "RepoFile.h"
class TestRepoFile {
private:
    const string fileName = "C:\\Users\\Alexie\\CLionProjects\\proiect\\testCarteIn.txt";
    const string fileNameOut = "C:\\Users\\Alexie\\CLionProjects\\proiect\\testCarteOut.txt";
    const string fileNameInvalid = "C:\\Users\\Alexie\\CLionProjects\\proiect\\testInvalidCarte.txt";
    vector<Carte*> carti;


    void testAddCarte();
    void testDeleteCarte();

    void testLoadFromFile();
    void testSaveToFile();
public:
    TestRepoFile();
    ~TestRepoFile();
    void testAll();
};


#endif //PROIECT_TESTREPOFILE_H
