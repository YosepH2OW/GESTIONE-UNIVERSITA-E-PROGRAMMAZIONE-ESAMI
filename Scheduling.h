//
// Created by Giuse on 30/10/2022.
//

#ifndef PERSONA_H_SCHEDULING_H
#define PERSONA_H_SCHEDULING_H

#include "BaseDati.h"
#include "Periodo_Esami.h"
#include "Indisponibilita.h"
#include "Giorno_Sessione.h"

class Scheduling {
public:
    //set base dati
    explicit Scheduling(BaseDati&);
    //Periodi Esame
    void setPeriodoEsame(Periodo_Esami&);
    void setPeriodoEsami(std::fstream&);
    void addPeriodoEsami(std::fstream&);
    std::vector<Periodo_Esami> getPeriodoEsami() const;
    //Indisponibilita
    void setIndisponibile(Indisponibilita&);
    void setIndisponibilita(std::fstream&);
    void addIndisponibilita(const std::string&,std::ifstream&,std::fstream&);
    std::vector<Indisponibilita> getIndisponibilita ()const;
    //Scheduling sessione esami

private:
BaseDati *baseDati;
std::vector<Periodo_Esami> _periodo_esami;
std::vector<Indisponibilita> _indisponibilita;
std::vector<Giorno_Sessione> _giorno_sessione;
};


#endif //PERSONA_H_SCHEDULING_H
