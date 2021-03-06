//
// Created by Alexie on 5/18/2021.
//

#ifndef PROIECT_READFROMFILEEXCEPTION_H
#define PROIECT_READFROMFILEEXCEPTION_H

#endif //PROIECT_READFROMFILEEXCEPTION_H
#include <exception>
#include <cstring>
using namespace std;
class ReadFromFileException : public exception {
private:
    char* message;
public:
    explicit ReadFromFileException(const char* message)
    {
        this->message = new char[strlen(message) + 1];
        strcpy_s(this->message, strlen(message) + 1, message);
    }

    ~ReadFromFileException()
    {
        if (this->message != NULL)
        {
            delete[] this->message;
        }
    }

    virtual const char* what()
    {
        return message;
    }
};