//
// Created by Giuse on 17/10/2022.
//

#ifndef MAIN_CPP_AULA_H
#define MAIN_CPP_AULA_H


#include <string>
#include "Eccezioni.h"
class Aula {
public:
    Aula(const std::string& ="",const char = 0,const std::string& ="",const int = 0,const int = 0);

    void setIdAula(const std::string&);
    std::string getIdAula()const;

    void setTipoAula(const char);
    char getTipo() const;

    void setDenominazione(const std::string&);
    std::string getDenominazione()const;

    void setMaxCapienza(const int);
    int getMaxCapienza() const;

    void setCapienzaEsame(const int);
    int getCapienzaEsame() const;
private:
    std::string _id_aula;
    char _tipo;
    std::string _denominazione;
    int _capienza_max;
    int _capienza_esame;
};


#endif //MAIN_CPP_AULA_H
