//
// Created by Giuse on 17/10/2022.
//

#include "Persona.h"

Persona::Persona(const std::string & matri, const std::string & name, const std::string & surname, const std::string & mail):_matricola(matri),_nome(name),_cognome(surname),_email(mail) {}

void Persona::setMatricola(const std::string & matri) {
    if(ControllaMatricola(matri))
        _matricola = matri;
    else
        throw MatricolaErrata();
}

std::string Persona::getMatricola() const {
    return _matricola;
}

void Persona::setName(const std::string &name) {
    _nome = name;
}

std::string Persona::getName() const {
    return _nome;
}

void Persona::setLastName(const std::string &surname) {
    _cognome = surname;
}

std::string Persona::getLastName() const {
    return _cognome;
}

void Persona::setEmail(const std::string & mail) {

    if(ControllaEmail(mail))
        _email = mail;
    else
        throw EmailErrata();
}

std::string Persona::getEmail() const {
    return _email;
}

bool Persona::ControllaEmail(const std::string & mail) {
    bool flag = false;
    std::size_t found,found2;

    found=mail.find_first_of('@');

    if(found!=std::string::npos){
        if(found>0){
            found2=mail.substr(found+1).find_last_of('.');
                if(found2!=std::string::npos)
                    if(found2<mail.length())
                        flag = true;
        }
    }

    return flag;
}

bool Persona::ControllaMatricola(const std::string & matri) {
    bool flag = false;

    if(matri.length()==6)
        if(matri.find_first_not_of( "0123456789" ) == std::string ::npos)
                flag = true;

    return flag;
}
