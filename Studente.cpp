//
// Created by Giuse on 17/10/2022.
//

#include "Studente.h"

void Studente::setMatricola(const std::string & matri) {
    if(ControllaMatricola(matri))
        _matricola = "s"+matri;
}

Studente::Studente(const std::string & matri, const std::string & name, const std::string & surname, const std::string & mail) :
Persona(matri,name,surname,mail){
    setMatricola(matri);
}
