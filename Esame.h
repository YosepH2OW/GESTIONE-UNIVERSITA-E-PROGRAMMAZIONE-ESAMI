//
// Created by Giuse on 17/10/2022.
//

#ifndef MAIN_CPP_ESAME_H
#define MAIN_CPP_ESAME_H


#include <string>
#include "Eccezioni.h"
class Esame {
public:
    Esame(const int=0,const int=0,const int=0,const char& ='0',const char ='0',const int=0);

    void setDurata(const int);
    int getDurata() const;

    void setIngresso(const int);
    int getIngresso() const;

    void setUscita(const int);
    int getUscita() const;

    void setModalita(const std::string&);
    std::string getModalita() const;

    void setLuogo(const char);
    char getLuogo() const;

    void setNumeroIscritti(const int);
    int getNumeroIscritti() const;

private:
    int _durata;
    int _t_ingresso; // tempi in minuti
    int _t_uscita;
    std::string _modalita;
    char _luogo;
    int _numero_iscritti;
};


#endif //MAIN_CPP_ESAME_H
