//
// Created by Giuse on 17/10/2022.
//

#ifndef MAIN_CPP_ECCEZIONI_H
#define MAIN_CPP_ECCEZIONI_H

#include <exception>

class PersonaInesistente: public std::exception {
private:
    const char *message;
public:
    PersonaInesistente();
    const char * what() const noexcept;
};

class IdVersioneErrato: public std::exception {
private:
    const char *message;
public:
    IdVersioneErrato();
    const char * what() const noexcept;
};

class IdCorsoErrato: public std::exception {
private:
    const char *message;
public:
    IdCorsoErrato();
    const char * what() const noexcept;
};

class MatricolaErrata: public std::exception {
private:
    const char *message;
public:
    MatricolaErrata();
    const char * what() const noexcept;
};

class EmailErrata: public std::exception {
private:
    const char *message;
public:
    EmailErrata();
    const char * what() const noexcept;
};

class NumeroSettimaneErrato: public std::exception {
private:
    const char *message;
public:
    NumeroSettimaneErrato();
    const char * what() const noexcept;
};

class AnnoErrato: public std::exception {
private:
    const char *message;
public:
    AnnoErrato();
    const char * what() const noexcept;
};

class FasciaOrariaErrata: public std::exception {
private:
    const char *message;
public:
    FasciaOrariaErrata();
    const char * what() const noexcept;
};

class ModalitaEsameErrata: public std::exception {
private:
    const char *message;
public:
    ModalitaEsameErrata();
    const char * what() const noexcept;
};

class LuogoEsameErrato: public std::exception {
private:
    const char *message;
public:
    LuogoEsameErrato();
    const char * what() const noexcept;
};

class NumeroIscrittiErrato: public std::exception {
private:
    const char *message;
public:
    NumeroIscrittiErrato();
    const char * what() const noexcept;
};

class IdAulaErrato: public std::exception {
private:
    const char *message;
public:
    IdAulaErrato();
    const char * what() const noexcept;
};

class DataErrata: public std::exception {
private:
    const char *message;
public:
    DataErrata();
    const char * what() const noexcept;
};

class IdCorsoStudiErrato: public std::exception {
private:
    const char *message;
public:
    IdCorsoStudiErrato();
    const char * what() const noexcept;
};

class DegreeErrato: public std::exception {
private:
    const char *message;
public:
    DegreeErrato();
    const char * what() const noexcept;
};

class CfuErrato: public std::exception {
private:
    const char *message;
public:
    CfuErrato();
    const char * what() const noexcept;
};

class OrariIncompatibili: public std::exception {
private:
    const char *message;
public:
    OrariIncompatibili();
    const char * what() const noexcept;
};

class CorsoInesistente: public std::exception {
private:
    const char *message;
public:
    CorsoInesistente();
    const char * what() const noexcept;
};

class NumeroVersioniIncompatibile: public std::exception {
private:
    const char *message;
public:
    NumeroVersioniIncompatibile();
    const char * what() const noexcept;
};

class AulaInesistente: public std::exception {
private:
    const char *message;
public:
    AulaInesistente();
    const char * what() const noexcept;
};
#endif //MAIN_CPP_ECCEZIONI_H
