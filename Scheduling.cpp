//
// Created by Giuse on 30/10/2022.
//

#include "Scheduling.h"
#include <algorithm>
using namespace std;

Scheduling::Scheduling(BaseDati & baseDati1):
baseDati(&baseDati1) {}


std::vector<Periodo_Esami> Scheduling::getPeriodoEsami() const {
    return _periodo_esami;
}


std::vector<Indisponibilita> Scheduling::getIndisponibilita() const {
    return _indisponibilita;
}

void Scheduling::setPeriodoEsame(Periodo_Esami&  periodo1) {
    bool trovato = false;
    for (auto & item:_periodo_esami) {
        if(item.getAnno()==periodo1.getAnno()) {
            trovato = true;
            vector<Periodo> periodi = periodo1.getPeriodi();
            item.getPeriodi().swap(periodi);
        }
    }
    if(!trovato)
        _periodo_esami.push_back(periodo1);

}

void Scheduling::setPeriodoEsami(std::fstream & db_examperiod){
    string anno,inizio,fine,acapo,periodo;
    char buffer;

    db_examperiod >> buffer;
    while(db_examperiod){
        db_examperiod >> anno;
        if(anno.size()!=9)
            anno = buffer+anno;
        Periodo_Esami esami(anno);
        db_examperiod >> periodo;
        inizio = periodo.substr(0,10);
        fine = periodo.substr(11,10);
        Periodo periodo1(inizio,fine);
        esami.setPeriodo(periodo1);
        db_examperiod >> periodo;
        inizio = periodo.substr(0,10);
        fine = periodo.substr(11,10);
        Periodo periodo2(inizio,fine);
        esami.setPeriodo(periodo2);
        db_examperiod >> periodo;
        db_examperiod >> buffer;
        inizio = periodo.substr(0,10);
        fine = periodo.substr(11,10);
        Periodo periodo3(inizio,fine);
        esami.setPeriodo(periodo3);

        _periodo_esami.push_back(esami);

    }
}


bool compareAnnoDec(const Periodo_Esami &a, const Periodo_Esami &b) {
    string c = a.getAnno().substr(0,4), d = b.getAnno().substr(0,4);
    return (c<d);
}

void Scheduling::addPeriodoEsami(fstream & db_examperiod){
    int i = 0;
    sort(_periodo_esami.begin(), _periodo_esami.end(), compareAnnoDec);
    for (auto& item:_periodo_esami) {
        if(i<=_periodo_esami.size()-1 && i>0)
            db_examperiod <<endl;

        db_examperiod << item.getAnno() << " " << item.getPeriodi()[0].getInizio() << "_"
                      << item.getPeriodi()[0].getFine() << " " << item.getPeriodi()[1].getInizio()
                      << "_"
                      << item.getPeriodi()[1].getFine() << " " << item.getPeriodi()[2].getInizio()
                      << "_"
                      << item.getPeriodi()[2].getFine();

            i++;

    }
}

void Scheduling::setIndisponibile(Indisponibilita & indisponibile) {
    bool trovato = false;
    for (auto & item:_indisponibilita) {
        if(item.getAnno()==indisponibile.getAnno()) {
            trovato = true;
            vector<Indisponibile> periodi = indisponibile.getIndisponibili();
            item.getIndisponibili().swap(periodi);
        }
    }
    if(!trovato)
        _indisponibilita.push_back(indisponibile);

}

void Scheduling::setIndisponibilita(fstream & db_indisponibilta) {
    char buffer;
    int length,pos;
    bool end = true,anno_flag=true;
    string anno,matricola,periodo,inizio,fine,acapo;
    stringstream periodo_buff;
    Indisponibilita listaind;

    db_indisponibilta >> buffer;
    while (db_indisponibilta && end){
        if(anno_flag) {
            if (anno.size() != 9) {
                db_indisponibilta >> anno;
                anno = buffer + anno;
            }
            listaind.setAnnoAccademico(anno);
            anno_flag = false;
        }

        if(getline(db_indisponibilta, periodo).eof())
            end = false;
        periodo_buff=(stringstream)"";
        periodo_buff << periodo;
        if(periodo.empty()) {
            db_indisponibilta >> periodo;
            periodo_buff << periodo;
        }
        while (periodo_buff){
            bool misurato = true;
            getline(periodo_buff ,matricola,';');
            Indisponibile docenteIndisponibile(matricola);

            while (periodo_buff){
                if(length-pos!=21)
                    getline(periodo_buff, periodo, ';');
                else
                    getline(periodo_buff, periodo);

                pos=(int)periodo_buff.tellg();
                if(misurato) {
                    periodo_buff.seekg(0, periodo_buff.end);
                    length = (int)periodo_buff.tellg();
                    periodo_buff.seekg(pos, periodo_buff.beg);
                    misurato = false;
                }
                inizio = periodo.substr(0, 10);
                fine = periodo.substr(11, 10);
                Periodo periodo1(inizio, fine);
                docenteIndisponibile.setIndisponibile(periodo1);
                periodo = "";
            }

            periodo_buff=(stringstream)"";
            periodo_buff >> buffer;
            db_indisponibilta>>periodo;
            if(periodo.size()!=9 && !periodo.empty())
                periodo_buff=(stringstream)"";
            periodo_buff << periodo;
            listaind.getIndisponibili().push_back(docenteIndisponibile);

        }
        if(periodo.size()==9||periodo.empty()) {
            _indisponibilita.push_back(listaind);
            listaind.getIndisponibili().clear();
            anno_flag = true;
            anno = periodo;
        }
    }


}

bool compareAnnoDecInd(const Indisponibilita &a, const Indisponibilita &b) {
    string c = a.getAnno().substr(0,4), d = b.getAnno().substr(0,4);
    return (c<d);
}

bool compareMatri(const Indisponibile& a, const Indisponibile& b){
    string c = a.getMatricola(), d = b.getMatricola();
    return (c<d);
}

void Scheduling::addIndisponibilita(const std::string& anno,ifstream & indisponibilitaList,fstream & db_indisponibilta) {
    bool end = true;
    int length=0,pos=0;
    string buffer;
    string matricola,periodo,inizio,fine;
    stringstream periodo_buff;
    Indisponibilita listaind;

    listaind.setAnnoAccademico(anno);

    while (indisponibilitaList && end){

        if(getline(indisponibilitaList, periodo).eof())
            end = false;
        periodo_buff=(stringstream)"";
        periodo_buff << buffer+periodo;

        while (periodo_buff){
            bool misurato = true;
            getline(periodo_buff ,matricola,';');
            //funzione che cerca la matricola fra i prof...altrimenti throw
            Indisponibile docenteIndisponibile(matricola);

            while (periodo_buff){
                if(length-pos!=21)
                    getline(periodo_buff, periodo, ';');
                else
                    getline(periodo_buff, periodo);

                pos=(int)periodo_buff.tellg();
                if(misurato) {
                    periodo_buff.seekg(0, periodo_buff.end);
                    length = (int)periodo_buff.tellg();
                    periodo_buff.seekg(pos, periodo_buff.beg);
                    misurato = false;
                }

                inizio = periodo.substr(0, 10);
                fine = periodo.substr(11, 10);
                Periodo periodo1(inizio, fine);
                docenteIndisponibile.setIndisponibile(periodo1);
            }
            periodo_buff=(stringstream)"";
            periodo_buff >> buffer;
            listaind.getIndisponibili().push_back(docenteIndisponibile);
        }
    }

    setIndisponibile(listaind);


    int i = 0;

    sort(_indisponibilita.begin(), _indisponibilita.end(), compareAnnoDecInd);
    for (auto& item:_indisponibilita) {
        sort(item.getIndisponibili().begin(), item.getIndisponibili().end(), compareMatri);

        if(i<=_indisponibilita.size()-1 && i>0)
            db_indisponibilta <<endl;

        db_indisponibilta << item.getAnno();
        for (auto& Ind:item.getIndisponibili()) {

            db_indisponibilta <<'\n'<< Ind.getMatricola();

            for (auto &per:Ind.getPeriodo()) {
                db_indisponibilta<<";"<< per.getInizio() <<'|'<< per.getFine();
            }
        }
        i++;
    }
}



