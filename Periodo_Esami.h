//
// Created by Giuse on 30/10/2022.
//

#ifndef PERSONA_H_PERIODO_ESAMI_H
#define PERSONA_H_PERIODO_ESAMI_H
#include <vector>
#include "Periodo.h"
class Periodo_Esami {
public:
    Periodo_Esami(const std::string& = "");

    void setAnno(const std::string&);
     std::string getAnno()const;

    void setPeriodo(const Periodo&);
    std::vector<Periodo>& getPeriodi();
private:
    std::string anno_accademico;
    std::vector<Periodo> periodo;
};


#endif //PERSONA_H_PERIODO_ESAMI_H
