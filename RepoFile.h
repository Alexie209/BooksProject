//
// Created by Alexie on 5/18/2021.
//

#ifndef PROIECT_REPOFILE_H
#define PROIECT_REPOFILE_H
#include "Repo.h"

class RepoFile : public Repo {
private:
    string fileName;
public:
    explicit RepoFile(string fileName);
    ~RepoFile();

    void setFileName(string fileName);

    void addCarte(Carte* c) override;
    void deleteCarte(Carte* c) override;

    void loadFromFile();
    void saveToFile();
};


#endif //PROIECT_REPOFILE_H
