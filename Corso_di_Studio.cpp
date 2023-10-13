//
// Created by Giuse on 17/10/2022.
//

#include "Corso_di_Studio.h"

void Corso_di_Studio::setIdCorsoStudio(const std::string& Id) {
    bool flag = true;

    if (Id.length() == 4)
        if (Id[0] == 'C')
            if (Id.substr(1, 3).find_first_not_of("0123456789") == std::string::npos){
                _id_corso_studi = Id;
                flag = false;
            }


    if(!flag)
        throw IdCorsoStudiErrato();
}

std::string Corso_di_Studio::getIdCorsoStudio() const {
    return _id_corso_studi;
}

void Corso_di_Studio::setDegree(const std::string& CS) {
        if(CS[0] == 'B' && CS[1]=='S'||CS[0] == 'M' && CS[1]=='S') {
            _degree[0] = CS[0];
            _degree[1] = CS[1];
        }
        else
            throw DegreeErrato();
}

std::string Corso_di_Studio::getDegree() const{
    return _degree;
}

void Corso_di_Studio::setCorsiSpenti(const std::string & codice_spento){
    if(Semestre::ControlloCodice(codice_spento))
        _corsi_spenti.push_back(codice_spento);

    else
        throw IdCorsoErrato();
}

std::vector<std::string> Corso_di_Studio::getCorsiSpenti() const {
    return _corsi_spenti;
}

void Corso_di_Studio::setSemestre(const Semestre & seimesi) {
    _Semestre.push_back(seimesi);
}

std::vector<Semestre> Corso_di_Studio::getSemestre()const{
    return _Semestre;
}

Corso_di_Studio::Corso_di_Studio(const std::string & idstudi,const std::string & degree, const std::vector<Semestre> & semestri,
                                 const std::vector<std::string> & spenti):
                                 _id_corso_studi(idstudi),_Semestre(semestri),_corsi_spenti(spenti){
    setDegree(degree);
}
