//
// Created by manie on 02/10/2020.
//

#ifndef LISTA_ESTATICA_STATICLISTEXCEPTION_H
#define LISTA_ESTATICA_STATICLISTEXCEPTION_H

#include <exception>
#include <string>

class StaticListException : std::exception{
private:
    std::string msg;
public:
    explicit StaticListException(const char* msg): msg(msg){}
    explicit StaticListException(const std::string& msg): msg(msg){}

    virtual ~StaticListException() throw(){}

    const char* what() const throw() override{
        return msg.c_str();
    }
};


#endif //LISTA_ESTATICA_STATICLISTEXCEPTION_H
