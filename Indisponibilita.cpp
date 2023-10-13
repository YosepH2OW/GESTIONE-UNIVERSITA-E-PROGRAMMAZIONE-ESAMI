//
// Created by Giuse on 30/10/2022.
//

#include "Indisponibilita.h"

void Indisponibilita::setIndisponibilita(const Indisponibile & indisponibileN) {
    indisponibilita.push_back(indisponibileN);
}

void Indisponibilita::setAnnoAccademico(const std::string & anno) {
    if (anno.size()==9){
        if (anno[4]=='-'){
            if (stoi(anno.substr(0,4))<2023 && std::stoi(anno.substr(0,4))+1 == std::stoi(anno.substr(5,4)))
                 anno_accademico=anno;
            else
                throw AnnoErrato();
        }
        else
            throw AnnoErrato();
    }
    else
        throw AnnoErrato();
}

std::vector<Indisponibile> &Indisponibilita::getIndisponibili() {
    return indisponibilita;
}

std::string Indisponibilita::getAnno() const {
    return anno_accademico;
}
