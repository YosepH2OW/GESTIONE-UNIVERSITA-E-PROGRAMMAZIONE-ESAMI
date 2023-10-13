//
// Created by Giuse on 03/11/2022.
//

#include "Giorno_Sessione.h"

void Giorno_Sessione::setFasciaOraria(const Fascia_Oraria & fascia) {
    _fasce_orarie.push_back(fascia);
}

std::vector<Fascia_Oraria> Giorno_Sessione::getFasceOrarie() const {
    return _fasce_orarie;
}
