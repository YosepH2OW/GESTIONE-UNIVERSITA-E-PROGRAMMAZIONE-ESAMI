//
// Created by Giuse on 30/10/2022.
//

#ifndef PERSONA_H_PERIODO_H
#define PERSONA_H_PERIODO_H

#include "Data.h"

class Periodo {
public:
    Periodo(const std::string& = "",const std::string& = "");

    void setInizio(const std::string&);
    Data getInizio() const;

    void setFine(const std::string&);
    Data getFine() const;

private:
    Data data_inizio;
    Data data_fine;
};


#endif //PERSONA_H_PERIODO_H
