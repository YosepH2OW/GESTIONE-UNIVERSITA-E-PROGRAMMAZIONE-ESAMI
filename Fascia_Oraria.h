//
// Created by Giuse on 03/11/2022.
//

#ifndef PERSONA_H_FASCIA_ORARIA_H
#define PERSONA_H_FASCIA_ORARIA_H

#include <vector>

#include "Elenco_Esame.h"
class Fascia_Oraria {
public:
    void setFasciaOraria(int);
    std::string getFasciaOraria()const;

    void setElencoEsame(const Elenco_Esame&);
    std::vector<Elenco_Esame> getElencoEsami()const;
private:
    std::string _fascia_oraria;
    std::vector<Elenco_Esame> Esami;
};


#endif //PERSONA_H_FASCIA_ORARIA_H
