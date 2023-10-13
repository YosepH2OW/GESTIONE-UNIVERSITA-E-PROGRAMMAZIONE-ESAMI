//
// Created by Giuse on 03/11/2022.
//

#include "Elenco_Esame.h"


void Elenco_Esame::setIdCorso(const std::string & codice) {
        _id_corso = codice;

}

std::string Elenco_Esame::getIdCorso() const {
    return _id_corso;
}

void Elenco_Esame::setCodiceVersione(const std::string & Id) {
    bool flag = true;

    if (Id.length() == 4)
        if (Id[0] == 'P')
            if (Id.substr(1, 3).find_first_not_of("0123456789") == std::string::npos){
                _id_versione = Id;
                flag = false;
            }


    if(!flag)
        throw IdVersioneErrato();
}

std::string Elenco_Esame::getCodiceVersione() const {
    return _id_versione;
}

void Elenco_Esame::setIdCorsoStudio(const std::string& Id) {
    bool flag = true;

    if (Id.length() == 4)
        if (Id[0] == 'C')
            if (Id.substr(1, 3).find_first_not_of("0123456789") == std::string::npos){
                _id_corso_studi = Id;
                flag = false;
            }


    if(!flag)
        throw IdCorsoErrato();
}

std::string Elenco_Esame::getIdCorsoStudio() const {
    return _id_corso_studi;
}

void Elenco_Esame::setIdAula(const std::string & Id) {
    bool flag = true;

    if (Id.length() == 4)
        if (Id[0] == 'A')
            if (Id.substr(1, 3).find_first_not_of("0123456789") == std::string::npos){
                _id_aula = Id;
                flag = false;
            }


    if(!flag)
        throw IdAulaErrato();
}

std::string Elenco_Esame::getIdAula() const {
    return _id_aula;
}

