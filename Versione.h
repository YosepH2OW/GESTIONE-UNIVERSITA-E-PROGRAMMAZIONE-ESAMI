//
// Created by Giuse on 26/10/2022.
//

#ifndef PERSONA_H_VERSIONE_H
#define PERSONA_H_VERSIONE_H

#include <vector>
#include "Professore.h"

class Versione {
public:
    Versione(const Professore&,const std::vector<Professore>&, const std::string& = "");

    void setTitolare(const Professore&);
    Professore& getTitolare();

    void setCodiceVersione (const std::string&);
    std::string getCodiceVersione() const;

    void setAssegnato(const Professore&);
    std::vector<Professore>& getAssegnati();
private:
    Professore _Prof_titolare;
    std::string _codice_versione;
    std::vector<Professore> _Prof_assegnati;
};


#endif //PERSONA_H_VERSIONE_H
