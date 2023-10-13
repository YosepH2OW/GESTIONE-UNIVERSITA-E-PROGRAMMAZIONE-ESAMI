//
// Created by Giuse on 17/10/2022.
//

#include "Aula.h"

Aula::Aula(const std::string & Id, const char tipo, const std::string & denominazione, const int cap_max, const int cap_es):
_id_aula(Id),_tipo(tipo),_denominazione(denominazione),_capienza_max(cap_max),_capienza_esame(cap_es) {}

void Aula::setIdAula(const std::string & Id) {
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

std::string Aula::getIdAula() const {
    return _id_aula;
}

void Aula::setDenominazione(const std::string & denominazione) {
_denominazione = denominazione;
}

std::string Aula::getDenominazione() const {
    return _denominazione;
}

void Aula::setMaxCapienza(const int cap_max) {
_capienza_max = cap_max;
}

int Aula::getMaxCapienza() const {
    return _capienza_max;
}

void Aula::setCapienzaEsame(const int cap_es) {
_capienza_esame = cap_es;
}

int Aula::getCapienzaEsame() const {
    return _capienza_esame;
}

void Aula::setTipoAula(const char tipo) {
_tipo = tipo;
}

char Aula::getTipo() const {
    return _tipo;
}
