//
// Created by Giuse on 17/10/2022.
//

#ifndef MAIN_CPP_ANNO_ACCADEMICO_H
#define MAIN_CPP_ANNO_ACCADEMICO_H


#include "Versione.h"
#include "Esame.h"
#include "Data.h"

class Anno_Accademico {
public:
    Anno_Accademico(const Esame&,const std::vector<std::string>&,const std::vector<Versione>& ,const std::string& ="",const bool = true, const int = 0);

    void setAnnoAccademico(const std::string&);
    std::string getAnnoAccademico() const;

    void setAttivo(const bool);
    bool getAttivo()const;

    void setNumVers(const int);
    int getNumVers()const;

    void setVersione(const Versione&);
    std::vector<Versione>& getVersione();

    void setEsame(const Esame&);
    Esame& getEsame();

    void setRaggruppamento(const std::string&);
    std::vector<std::string>& getRaggruppamenti();

    static bool ControlloCodice(const std::string&);

private:
    std::string _anno_accademico;
    bool _attivo;
    int _versioni_in_parallelo;
    std::vector<Versione> _Versione;
    Esame _Prova;
    std::vector<std::string> _raggruppamenti;
};


#endif //MAIN_CPP_ANNO_ACCADEMICO_H
