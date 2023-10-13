//
// Created by Giuse on 17/10/2022.
//

#include "Esame.h"

Esame::Esame(const int durata, const int ingresso, const int uscita, const char& modalita, const char luogo, const int iscritti)
: _durata(durata),_t_ingresso(ingresso),_t_uscita(uscita),_luogo(luogo),_numero_iscritti(iscritti){ setModalita(&modalita);}

void Esame::setDurata(const int  durata) {
_durata = durata;
}

int Esame::getDurata() const {
    return _durata;
}

void Esame::setIngresso(const int ingresso) {
_t_ingresso=ingresso;
}

int Esame::getIngresso() const {
    return _t_ingresso;
}

void Esame::setUscita(const int uscita) {
_t_uscita = uscita;
}

int Esame::getUscita() const {
    return _t_uscita;
}

void Esame::setModalita(const std::string& modalita) {
    if(modalita == "S"||modalita == "O"||modalita == "P"||modalita=="SO") {
        _modalita=modalita;
    }
    else
        throw ModalitaEsameErrata();
}

std::string Esame::getModalita() const {
    return _modalita;
}

void Esame::setLuogo(const char L) {
    if (L == 'L' || L == 'A')
        _luogo = L;
    else
        throw LuogoEsameErrato();
}

char Esame::getLuogo() const {
    return _luogo;
}

void Esame::setNumeroIscritti(const int n_iscritti) {
    if( n_iscritti>0 && (n_iscritti % 1) == 0 ) // controllo numero intero e positivo
        _numero_iscritti = n_iscritti;
    else
        throw NumeroIscrittiErrato();
}

int Esame::getNumeroIscritti() const {
    return _numero_iscritti;
}
