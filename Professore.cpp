//
// Created by Giuse on 17/10/2022.
//

#include "Professore.h"

void Professore::setMatricola(const std::string & matri) {
    if(ControllaMatricola(matri))
        _matricola = "d"+matri;
}

void Professore::setHourLez(const int orelez) {
    _hlez = orelez;
}

int Professore::getHourLez() const {
    return _hlez;
}

void Professore::setHourLab(const int orelab) {
    _hlab = orelab;
}

int Professore::getHourLab() const {
    return _hlab;
}

void Professore::setHourEs(const int oreEs) {
    _hese = oreEs;
}

int Professore::getHourEs() const {
    return _hese;
}

Professore::Professore(const std::string & matri, const std::string & name, const std::string & surname, const std::string & mail, int hle, int hla,int he):
    Persona(matri,name,surname,mail)
    {
    setMatricola(matri);
    setHourEs(he);
    setHourLab(hla);
    setHourLez(hle);
}
