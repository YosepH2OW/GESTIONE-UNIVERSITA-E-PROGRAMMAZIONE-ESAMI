//
// Created by Giuse on 30/10/2022.
//

#ifndef PERSONA_H_INDISPONIBILE_H
#define PERSONA_H_INDISPONIBILE_H

#include <vector>

#include "Periodo.h"
class Indisponibile {
public:
    explicit Indisponibile(const std::string& = "");

    std::string getMatricola() const;

    void setIndisponibile(const Periodo&);
    std::vector<Periodo>& getPeriodo();
private:
    std::string matricola_docente;
    std::vector<Periodo> indisponibilita;
};


#endif //PERSONA_H_INDISPONIBILE_H
