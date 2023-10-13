//
// Created by Giuse on 03/11/2022.
//

#ifndef PERSONA_H_ELENCO_ESAME_H
#define PERSONA_H_ELENCO_ESAME_H

#include <string>
#include "Eccezioni.h"
class Elenco_Esame {
public:
    void setIdCorso(const std::string&);
    std::string getIdCorso()const;

    void setCodiceVersione (const std::string&);
    std::string getCodiceVersione() const;

    void setIdCorsoStudio(const std::string&);
    std::string getIdCorsoStudio() const;

    void setIdAula(const std::string&);
    std::string getIdAula()const;
private:
    std::string _id_corso;
    std::string _id_versione;
    std::string _id_corso_studi;
    std::string _id_aula;
};


#endif //PERSONA_H_ELENCO_ESAME_H
