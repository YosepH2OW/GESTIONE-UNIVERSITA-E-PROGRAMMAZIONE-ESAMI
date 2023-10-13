//
// Created by Giuse on 17/10/2022.
//

#ifndef MAIN_CPP_STUDENTE_H
#define MAIN_CPP_STUDENTE_H


#include "Persona.h"

class Studente: public Persona{
public:
    Studente(const std::string& ="",const std::string& ="",const std::string& ="",const std::string& ="");
    virtual ~Studente() = default;

    void setMatricola(const std::string&) override;

};


#endif //MAIN_CPP_STUDENTE_H
