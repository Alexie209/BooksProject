//
// Created by Alexie on 5/18/2021.
//

#ifndef PROIECT_REPOEXCEPTION_H
#define PROIECT_REPOEXCEPTION_H

#endif //PROIECT_REPOEXCEPTION_H
class RepoException : public runtime_error {
private:
    const char* message;
public:
    RepoException(const char* msg) : runtime_error(msg), message(msg)
    {}

    const char* what()
    {
        return message;
    }
};