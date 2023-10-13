//
// Created by Giuse on 17/10/2022.
//

#ifndef MAIN_CPP_PERSONA_H
#define MAIN_CPP_PERSONA_H
#include <string>
#include "Eccezioni.h"
class Persona {
public:
    explicit Persona(const std::string& ="",const std::string& ="",const std::string& ="",const std::string& ="");
    virtual ~Persona() = default;

    bool ControllaMatricola(const std::string&);
    virtual void setMatricola(const std::string&); //polimorfismo per il set e il get della matricola
    std::string getMatricola() const;

    void setName(const std::string&);
    std::string getName() const;

    void setLastName(const std::string&);
    std::string getLastName() const;

    bool ControllaEmail(const std::string&);
    void setEmail(const std::string&); // creare una funzione di controllo per il corretto formato
    std::string getEmail() const;

protected:
    std::string _matricola;
private:
    std::string _nome;
    std::string _cognome;
    std::string _email;
};


#endif //MAIN_CPP_PERSONA_H
