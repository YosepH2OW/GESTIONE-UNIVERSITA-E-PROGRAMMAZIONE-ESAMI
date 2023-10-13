//
// Created by Giuse on 30/10/2022.
//

#ifndef PERSONA_H_INDISPONIBILITA_H
#define PERSONA_H_INDISPONIBILITA_H


#include "Indisponibile.h"

class Indisponibilita {
public:
    void setAnnoAccademico(const std::string&);
    std::string getAnno()const;

    void setIndisponibilita(const Indisponibile&);
    std::vector<Indisponibile>& getIndisponibili();

private:
    std::string anno_accademico;
    std::vector<Indisponibile> indisponibilita;
};


#endif //PERSONA_H_INDISPONIBILITA_H
