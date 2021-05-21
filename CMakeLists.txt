cmake_minimum_required(VERSION 3.19)
project(proiect)

set(CMAKE_CXX_STANDARD 14)

add_executable(proiect main.cpp
        Carte.cpp
        Carte.h
        TestCarte.cpp
        TestCarte.h
        CarteProza.cpp
        CarteProza.h
        TestCarteProza.cpp
        TestCarteProza.h
        CartePoezie.cpp
        CartePoezie.h
        TestCartePoezie.cpp
        TestCartePoezie.h
        ValidationException.h
        ValidatorCarte.cpp
        ValidatorCarte.h
        ValidatorCarteProza.cpp
        ValidatorCarteProza.h
        ValidatorCartePoezie.h
        ValidatorCartePoezie.cpp
        TestValidatorCarte.cpp
        TestValidatorCarte.h
        Repo.cpp
        Repo.h
        RepoException.h
        TestRepo.cpp
        TestRepo.h
        RepoFile.cpp
        RepoFile.h
        ReadFromFileException.h
        TestRepoFile.cpp
        TestRepoFile.h
        Service.h
        Service.cpp
        TestService.cpp
        TestService.h
        UI.h
        UI.cpp)

