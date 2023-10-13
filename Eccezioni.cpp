//
// Created by Giuse on 17/10/2022.
//

#include "Eccezioni.h"

PersonaInesistente::PersonaInesistente():message("Errore, la persona inserita non esiste") {

}
const char* PersonaInesistente::what() const noexcept{
    return message;
}

IdVersioneErrato::IdVersioneErrato():message("Errore, il formato dell'id versione è errato")  {

}
const char* IdVersioneErrato::what() const noexcept{
    return message;
}

IdCorsoErrato::IdCorsoErrato():message("Errore, il formato dell'id corso è errato")  {

}
const char* IdCorsoErrato::what() const noexcept{
    return message;
}

MatricolaErrata::MatricolaErrata():message("Errore, il formato della matricola è errato") {

}
const char* MatricolaErrata::what() const noexcept{
    return message;
}

EmailErrata::EmailErrata():message("Errore, il formato della email è errato") {

}
const char* EmailErrata::what() const noexcept{
    return message;
}

NumeroSettimaneErrato::NumeroSettimaneErrato():message("Errore, il numero delle settimane è errato (6 per i primi due semestri,4 per il terzo)") {

}
const char* NumeroSettimaneErrato::what() const noexcept{
    return message;
}

AnnoErrato::AnnoErrato():message("Errore, il formato dell'anno è errato") {

}
const char* AnnoErrato::what() const noexcept{
    return message;
}

FasciaOrariaErrata::FasciaOrariaErrata():message("Errore, la fascia oraria è errata") {

}
const char* FasciaOrariaErrata::what() const noexcept{
    return message;
}

ModalitaEsameErrata::ModalitaEsameErrata():message("Errore, formato modalita è errato") {

}
const char* ModalitaEsameErrata::what() const noexcept{
    return message;
}

LuogoEsameErrato::LuogoEsameErrato():message("Errore, formato luogo esame è errato") {

}
const char* LuogoEsameErrato::what() const noexcept{
    return message;
}

NumeroIscrittiErrato::NumeroIscrittiErrato():message("Errore, il numero iscritti non è un intero positivo") {

}
const char* NumeroIscrittiErrato::what() const noexcept{
    return message;
}

IdAulaErrato::IdAulaErrato():message("Errore, formato id aula è errato") {

}
const char* IdAulaErrato::what() const noexcept{
    return message;
}

DataErrata::DataErrata():message("Errore, formato della data è errato") {

}
const char* DataErrata::what() const noexcept{
    return message;
}

IdCorsoStudiErrato::IdCorsoStudiErrato():message("Errore, formato id corso di studi è errato") {

}
const char* IdCorsoStudiErrato::what() const noexcept{
    return message;
}

DegreeErrato::DegreeErrato():message("Errore, formato degree è errato") {

}
const char* DegreeErrato::what() const noexcept{
    return message;
}

CfuErrato::CfuErrato():message("Errore, il numero cfu non è un intero positivo") {

}
const char* CfuErrato::what() const noexcept{
    return message;
}

OrariIncompatibili::OrariIncompatibili():message("Errore,gli orari del corso non coincidono con la somma degli orari dei professori")  {

}
const char* OrariIncompatibili::what() const noexcept{
    return message;
}

CorsoInesistente::CorsoInesistente():message("Errore,il corso non è presente nel database") {

}
const char* CorsoInesistente::what() const noexcept{
    return message;
}

NumeroVersioniIncompatibile::NumeroVersioniIncompatibile():message("Errore,il numero versioni indicato è incompatibile con quello successivamente scritto") {

}
const char* NumeroVersioniIncompatibile::what() const noexcept{
    return message;
}

AulaInesistente::AulaInesistente():message("Errore,l'aula non è presente nel database") {

}
const char* AulaInesistente::what() const noexcept{
    return message;
}