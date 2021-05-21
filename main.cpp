#include <iostream>
#include "TestCarte.h"
#include "TestCarteProza.h"
#include "TestCartePoezie.h"
#include "TestValidatorCarte.h"
#include "TestRepo.h"
#include "TestRepoFile.h"
#include "TestService.h"
#include "Service.h"
#include "UI.h"

using namespace std;
int main() {
    TestCarte testCarte;
    testCarte.testAll();

    TestCarteProza testCarteProza;
    testCarteProza.testAll();

    TestCartePoezie testCartePoezie;
    testCartePoezie.testAll();

    TestValidatorCarte testValidatorCarte;
    testValidatorCarte.testAll();

    TestRepo testRepo;
    testRepo.testAll();

    TestRepoFile testRepoFile;
    testRepoFile.testAll();

    TestService testService;
    testService.testAll();

    RepoFile* repo = new RepoFile("C:\\Users\\Alexie\\CLionProjects\\proiect\\carti.txt");
    Repo* repo1 = new Repo;
    Service service(repo);
    UI ui(service);

    ui.runMenu();
    return 0;
}
