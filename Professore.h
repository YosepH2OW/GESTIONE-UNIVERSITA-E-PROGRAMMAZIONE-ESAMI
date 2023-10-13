//
// Created by Giuse on 17/10/2022.
//

#ifndef MAIN_CPP_PROFESSORE_H
#define MAIN_CPP_PROFESSORE_H

#include "Eccezioni.h"
#include "Persona.h"

class Professore: public Persona {
public:
    Professore(const std::string& ="",const std::string& ="",const std::string& ="",const std::string& ="",int = 0,int = 0,int = 0);
    virtual ~Professore() = default;

    void setMatricola(const std::string&) override;

    void setHourLez(const int);
    int getHourLez() const;

    void setHourLab(const int);
    int getHourLab() const;

    void setHourEs(const int);
    int getHourEs() const;


private:
    int _hlez;
    int _hlab;
    int _hese;
};


#endif //MAIN_CPP_PROFESSORE_H
