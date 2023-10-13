//
// Created by Giuse on 30/10/2022.
//

#include "Periodo_Esami.h"

void Periodo_Esami::setPeriodo(const Periodo & periodoN)  {
    if(periodo.size()<=1) {
        if (periodoN.getFine() - periodoN.getInizio() == 41) {
            periodo.push_back(periodoN);
        }
    }
    else if(periodo.size()==2) {
        if (periodoN.getFine() - periodoN.getInizio() == 27) {
            periodo.push_back(periodoN);
        }
    }
    else{
        throw NumeroSettimaneErrato();
    }
}

Periodo_Esami::Periodo_Esami(const std::string & anno):anno_accademico(anno){

}

void Periodo_Esami::setAnno(const std::string & anno) {
    anno_accademico = anno;
}

std::string Periodo_Esami::getAnno() const {
    return anno_accademico;
}

std::vector<Periodo>& Periodo_Esami::getPeriodi(){
    return periodo;
}
