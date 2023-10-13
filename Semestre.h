//
// Created by Giuse on 20/10/2022.
//

#ifndef PERSONA_H_SEMESTRE_H
#define PERSONA_H_SEMESTRE_H

#include <vector>
#include <string>
#include "Eccezioni.h"
class Semestre {
public:
    Semestre(std::vector<std::string>&);

    static bool ControlloCodice(const std::string&);

    void setCorsoSemestre(const std::string&);
    std::vector<std::string> getCorsiSemestre()const;

private:
    std::vector<std::string> _corsi_semestre;
};


#endif //PERSONA_H_SEMESTRE_H
