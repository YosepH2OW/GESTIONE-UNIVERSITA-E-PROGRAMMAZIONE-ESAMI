//
// Created by Giuse on 03/11/2022.
//

#include "Fascia_Oraria.h"

void Fascia_Oraria::setFasciaOraria(const int fascia) {
    switch (fascia) {

        case 1:
            _fascia_oraria = "8:00-10:00";
            break;
        case 2:
            _fascia_oraria = "10:00-12:00";
            break;
        case 3:
            _fascia_oraria = "12:00-14:00";
            break;
        case 4:
            _fascia_oraria = "14:00-16:00";
            break;
        case 5:
            _fascia_oraria = "16:00-18:00";
            break;
        case 6:
            _fascia_oraria = "18:00-20:00";
            break;
        default:
            throw FasciaOrariaErrata();
            break;
    }
}

std::string Fascia_Oraria::getFasciaOraria() const {
    return _fascia_oraria;
}

void Fascia_Oraria::setElencoEsame(const Elenco_Esame & prova) {
    Esami.push_back(prova);
}

std::vector<Elenco_Esame> Fascia_Oraria::getElencoEsami() const {
    return Esami;
}
