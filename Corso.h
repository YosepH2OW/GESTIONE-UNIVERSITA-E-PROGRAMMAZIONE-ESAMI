//
// Created by Giuse on 17/10/2022.
//

#ifndef MAIN_CPP_CORSO_H
#define MAIN_CPP_CORSO_H

#include "Anno_Accademico.h"

class Corso {
public:
    Corso(const std::string& = "",const std::string& = "",const int = 0,const int = 0,const int = 0,const int = 0);

    void setIdCorso(const std::string&);
    std::string getIdCorso()const;

    void setTitolo(const std::string&);
    std::string getTitolo()const;

    void setCfu(const int);
    int getCfu()const;

    void setHoursLez(const int);
    int getHoursLez()const;

    void setHoursLab(const int);
    int getHoursLab()const;

    void setHoursEs(const int);
    int getHoursEs()const;

    void setAnnoAccademico(const Anno_Accademico&);
    std::vector<Anno_Accademico>& getAnnoAccademico();
private:
    std::string _id_corso;
    std::string _titolo;
    int _cfu;
    int _ore_lez;
    int _ore_lab;
    int _ore_ese;
    std::vector<Anno_Accademico> _Anno;

};


#endif //MAIN_CPP_CORSO_H
