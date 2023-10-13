//
// Created by Giuse on 17/10/2022.
//

#include "Corso.h"

Corso::Corso(const std::string & id, const std::string & title, const int cfu, const int orelez, const int ores, const int orelab):
_titolo(title),_cfu(cfu),_ore_lez(orelez),_ore_ese(ores),_ore_lab(orelab) {
    setIdCorso(id);
}

void Corso::setIdCorso(const std::string & codice) {
    if(Anno_Accademico::ControlloCodice(codice)){
        _id_corso = codice;
    }
    else
        throw IdCorsoErrato();
}

std::string Corso::getIdCorso() const {
    return _id_corso;
}

void Corso::setTitolo(const std::string & titolo) {
    _titolo = titolo;
}

std::string Corso::getTitolo() const {
    return _titolo;
}

void Corso::setCfu(const int crediti) {
    if( crediti>0 && (crediti % 1) == 0 )
        _cfu = crediti;
    else
        throw CfuErrato();
}

int Corso::getCfu() const {
    return _cfu;
}

void Corso::setHoursLez(const int hl) {
    _ore_lez = hl;
}

int Corso::getHoursLez() const {
    return _ore_lez;
}

void Corso::setHoursLab(const int hlab) {
    _ore_lab = hlab;
}

int Corso::getHoursLab() const {
    return _ore_lab;
}

void Corso::setHoursEs(const int hes) {
    _ore_ese = hes;
}

int Corso::getHoursEs() const {
    return _ore_ese;
}

void Corso::setAnnoAccademico(const Anno_Accademico & AnnoAccademico) {
    _Anno.push_back(AnnoAccademico);
}

std::vector<Anno_Accademico>& Corso::getAnnoAccademico() {
    return _Anno;
}




