//
// Created by Giuse on 30/10/2022.
//

#include "Indisponibile.h"

Indisponibile::Indisponibile(const std::string & matricolad):matricola_docente(matricolad) {

}

void Indisponibile::setIndisponibile(const Periodo & periodoN) {
    indisponibilita.push_back(periodoN);
}

std::string Indisponibile::getMatricola() const {
    return matricola_docente;
}

std::vector<Periodo>& Indisponibile::getPeriodo() {
    return indisponibilita;
}
