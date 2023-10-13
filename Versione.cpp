//
// Created by Giuse on 26/10/2022.
//

#include "Versione.h"

Versione::Versione(const Professore & proftit, const std::vector<Professore> & assegnati, const std::string & idversione):
        _Prof_titolare(proftit), _Prof_assegnati(assegnati),_codice_versione(idversione){}

void Versione::setTitolare(const Professore & Titolare) {
    _Prof_titolare = Titolare;
}

Professore& Versione::getTitolare(){
    return _Prof_titolare;
}

void Versione::setCodiceVersione(const std::string & Id) {
    bool flag = true;

    if (Id.length() == 4)
        if (Id[0] == 'P')
            if (Id.substr(1, 3).find_first_not_of("0123456789") == std::string::npos){
                _codice_versione = Id;
                flag = false;
            }


    if(flag)
        throw IdVersioneErrato();

}

std::string Versione::getCodiceVersione() const {
    return _codice_versione;
}

void Versione::setAssegnato(const Professore & Assegnato) {
    _Prof_assegnati.push_back(Assegnato);
}

std::vector<Professore>& Versione::getAssegnati() {
    return _Prof_assegnati;
}


