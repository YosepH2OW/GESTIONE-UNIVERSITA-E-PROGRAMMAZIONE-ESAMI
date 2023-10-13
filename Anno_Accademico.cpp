//
// Created by Giuse on 17/10/2022.
//

#include "Anno_Accademico.h"

Anno_Accademico::Anno_Accademico( const Esame & prova,const std::vector<std::string> & raggruppamenti,const std::vector<Versione>& versioni, const std::string& anno, const bool attivo, const int num_versioni):
        _Prova(prova),_raggruppamenti(raggruppamenti),_Versione(versioni),
        _anno_accademico(anno),_attivo(attivo),_versioni_in_parallelo(num_versioni){
    if(num_versioni!=_Versione.capacity())
        throw NumeroVersioniIncompatibile();
}


void Anno_Accademico::setAnnoAccademico(const std::string & anno) {
    if (anno.size()==9){
        if (anno[4]=='-'){
            if (stoi(anno.substr(0,4))<2023 && std::stoi(anno.substr(0,4))+1 == std::stoi(anno.substr(5,4)))
                _anno_accademico=anno;
            else
                throw AnnoErrato();
        }
        else
            throw AnnoErrato();
    }
    else
        throw AnnoErrato();
}

std::string Anno_Accademico::getAnnoAccademico() const{
    return _anno_accademico;
}

void Anno_Accademico::setAttivo(const bool active) {
_attivo = active;
}

bool Anno_Accademico::getAttivo() const {
    return _attivo;
}

void Anno_Accademico::setNumVers(const int vers) {
    _versioni_in_parallelo = vers;
}

int Anno_Accademico::getNumVers() const {
    return _versioni_in_parallelo;
}



void Anno_Accademico::setEsame(const Esame & esame) {
    _Prova = esame;
}

Esame& Anno_Accademico::getEsame(){
    return _Prova;
}

void Anno_Accademico::setRaggruppamento(const std::string & Id_raggruppato) {
    //funzione controllo stringa codice corso
    if(ControlloCodice(Id_raggruppato))
        _raggruppamenti.push_back(Id_raggruppato);
    else
        throw IdCorsoErrato();

}

std::vector<std::string>& Anno_Accademico::getRaggruppamenti(){
    return _raggruppamenti;
}



bool Anno_Accademico::ControlloCodice(const std::string& code) {
    bool flag= false;
    int count = 0;

    if (code.size()==7)
        if(code.substr(0,2)=="01") {
            for (int i = 0; i < code.substr(2,6).length(); ++i) {
                if((int)code.substr(2,6)[i]>=65||(int)code.substr(2,6)[i]<=90)//se coincide con un carattere ASCII da 65 a 90
                    count++;
            }
            if(count == code.substr(2,6).length() )
                flag = true;
        }

    return flag;
}

void Anno_Accademico::setVersione(const Versione & versx) {

    _Versione.push_back(versx);

    if(_Versione.capacity()>_versioni_in_parallelo)
        throw NumeroVersioniIncompatibile();
}

std::vector<Versione>& Anno_Accademico::getVersione() {
    return _Versione;
}




