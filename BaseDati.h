//
// Created by Giuse on 18/10/2022.
//

#ifndef PERSONA_H_BASEDATI_H
#define PERSONA_H_BASEDATI_H

#include "Studente.h"
#include "Professore.h"
#include "Aula.h"
#include "Corso.h"
#include "Corso_di_Studio.h"

#include <fstream>
#include <iomanip>

class BaseDati {
public:
// carico dati da database file in base dati
    void setStudente(std::fstream&);
    void setProfessore(std::fstream&);
    void setAula(std::fstream&);
    void setCorso(std::fstream&);
    void setCorsoStudi(std::fstream&);
// aggiunta dati e inserimento dati da base dati nei database file
    void addStudente(std::ifstream&,std::fstream&);
    void addProfessore(std::ifstream&,std::fstream&);
    void addAula(std::ifstream&,std::fstream&);
    void addCorso(std::ifstream&,std::fstream&);
    void addCorsoStudi(std::ifstream&,std::fstream&);
// update dati e inserimento dati
    void updatePersona(std::ifstream&,std::fstream&);
    void updateAule(std::ifstream&,std::fstream&);
    void inserimentoCorsi(std::ifstream&,std::fstream&);
//print da database a database file
    template<typename T>
    void printPersone(const std::vector<T>&,std::fstream&)const;
    void printAule(const std::vector<Aula>&,std::fstream&)const;
    void printCourses(std::vector<Corso>&,std::fstream&)const;
    void printCoursoStudio(std::vector<Corso_di_Studio>&,std::fstream&)const;
//utili
    const std::string& incrementCourseCode (std::string&);
    void setCorsoSpento(const std::string&);
private:
    std::vector<Studente> _Studente;
    std::vector<Professore> _Professore;
    std::vector<Aula> _Aula;
    std::vector<Corso> _Corso;
    std::vector<Corso_di_Studio> _Corso_di_Studio;
};


#endif //PERSONA_H_BASEDATI_H
