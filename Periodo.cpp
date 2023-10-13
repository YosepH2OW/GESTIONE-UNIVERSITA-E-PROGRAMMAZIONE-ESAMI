//
// Created by Giuse on 30/10/2022.
//

#include "Periodo.h"

Periodo::Periodo(const std::string & Inizio, const std::string & Fine): data_inizio(Inizio), data_fine(Fine) {

}

Data Periodo::getInizio() const{
    return data_inizio;
}

Data Periodo::getFine() const{
    return data_fine;
}

void Periodo::setInizio(const std::string & inizio) {
    data_inizio.setData(inizio);
}

void Periodo::setFine(const std::string &fine) {
    data_fine.setData(fine);
}
