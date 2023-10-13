//
// Created by Giuse on 03/11/2022.
//

#ifndef PERSONA_H_GIORNO_SESSIONE_H
#define PERSONA_H_GIORNO_SESSIONE_H

#include "Data.h"
#include "Fascia_Oraria.h"
class Giorno_Sessione: public Data{
public:
    void setFasciaOraria(const Fascia_Oraria&);
    std::vector<Fascia_Oraria> getFasceOrarie()const;
private:
    Data _giorno_sessione;
    std::vector<Fascia_Oraria> _fasce_orarie;
};


#endif //PERSONA_H_GIORNO_SESSIONE_H
