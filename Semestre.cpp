//
// Created by Giuse on 20/10/2022.
//

#include "Semestre.h"

bool Semestre::ControlloCodice(const std::string & code) {
    bool flag= false;
    int count = 0;

    if (code.size()==7)
        if(code.substr(0,2)=="01") {
            for (int i = 0; i < 4; ++i) {
                if((int)code.substr(2,4)[i]>=65 && (int)code.substr(2,4)[i]<=90)//se coincide con un carattere ASCII compreso fra 65 e 90
                    count++;
            }
            if(count == 4)
                flag = true;
        }

    return flag;
}

void Semestre::setCorsoSemestre(const std::string & codice) {
    if(ControlloCodice(codice))
        _corsi_semestre.push_back(codice);

    else
        throw IdCorsoErrato();
}

std::vector<std::string> Semestre::getCorsiSemestre() const {
    return _corsi_semestre;
}

Semestre::Semestre(std::vector<std::string> & corsi_semestre):_corsi_semestre(corsi_semestre) {}
