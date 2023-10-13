//
// Created by Giuse on 17/10/2022.
//

#ifndef MAIN_CPP_CORSO_DI_STUDIO_H
#define MAIN_CPP_CORSO_DI_STUDIO_H

#include "Semestre.h"

class Corso_di_Studio {
public:
    Corso_di_Studio(const std::string&,const std::string &,const std::vector<Semestre>&,const std::vector<std::string>&);

    void setIdCorsoStudio(const std::string&);
    std::string getIdCorsoStudio() const;

    void setDegree(const std::string&);
    std::string getDegree() const;

    void setSemestre(const Semestre&);
    std::vector<Semestre> getSemestre() const;

    void setCorsiSpenti(const std::string&);
    std::vector<std::string> getCorsiSpenti()const;

private:
    std::string _id_corso_studi;
    std::string _degree;
    std::vector<Semestre> _Semestre; //una classe semestre che contiene a sua volta un vettore di stringhe per i corsi
    std::vector<std::string> _corsi_spenti;
};


#endif //MAIN_CPP_CORSO_DI_STUDIO_H
