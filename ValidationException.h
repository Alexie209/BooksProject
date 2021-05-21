#include <utility>

//
// Created by Alexie on 5/18/2021.
//

#ifndef PROIECT_VALIDATIONEXCEPTION_H
#define PROIECT_VALIDATIONEXCEPTION_H
#include <exception>
using namespace std;
#endif //PROIECT_VALIDATIONEXCEPTION_H
class ValidationException: public exception{
private:
    string message;
public:
    ValidationException() :exception() {};
    ValidationException(string msj) :exception() { this->message = msj; };
    ~ValidationException() {};

    const char* what() const throw(){
        return message.c_str();
    }
};
