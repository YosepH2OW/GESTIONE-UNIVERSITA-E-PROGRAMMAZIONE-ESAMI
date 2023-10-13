//
// Created by Giuse on 18/10/2022.
//



#include "BaseDati.h"

using namespace std;


void BaseDati::setStudente(fstream& db_studenti) {
    string matricola,nome,cognome, email,acapo;
    char buffer;
//istream& getline (istream&  is, string& str, char delim)
    db_studenti >> buffer;
    while (db_studenti){

        getline(db_studenti,matricola,';');
        if(matricola.size()==7)
            matricola = matricola.substr(1,6); // esclusa la 's'
        getline(db_studenti,nome,';');
        getline(db_studenti,cognome,';');
        getline(db_studenti,email,';');
        getline(db_studenti,acapo);

        Studente studente(matricola,nome,cognome,email);
        _Studente.push_back(studente);
    }
}

void BaseDati::addStudente(ifstream & studentList, fstream & db_studenti){
// leggi ultima matricola, se presente costruisci la consecutiva che non sia uguale a una dei professori, se assente parti da 1 se non uguale ai prof.
//poi salva tutto in db file
    string matricola,nome,cognome, email,acapo;
    int id_prof = 0, id_stud = 0;
    stringstream buf_matricola;


    while (!studentList.eof()){
        if(!_Studente.empty())
            id_stud = stoi(_Studente.back().getMatricola().substr(1,6));
      /*  if(!_Professore.empty())
            id_prof=stoi(_Professore.back().getMatricola());*/


        if(id_prof>id_stud)
            buf_matricola << setfill ('0') << setw (6) << to_string(++id_prof);

        else
            buf_matricola << setfill ('0') << setw (6) << to_string(++id_stud);


        matricola=buf_matricola.str();
        buf_matricola = (stringstream)"";
        getline(studentList,nome,';');
        getline(studentList,cognome,';');
        getline(studentList,email,';');
        getline(studentList,acapo,'\n');

        Studente studente(matricola,nome,cognome,email);
        _Studente.push_back(studente);

        if(matricola!="000001"&&id_stud!=0)
            db_studenti << endl;
        db_studenti << studente.getMatricola() << ';' << studente.getName() << ';' << studente.getLastName() << ';' << studente.getEmail() << ';';
    }

}

void BaseDati::setProfessore(fstream & db_professori) {
    string matricola,nome,cognome, email,acapo;
    char buffer;
//istream& getline (istream&  is, string& str, char delim)
    db_professori >> buffer;
    while (db_professori){

        getline(db_professori,matricola,';');
        if(matricola.size()==7)
            matricola = matricola.substr(1,6); // esclusa la 'd'
        getline(db_professori,nome,';');
        getline(db_professori,cognome,';');
        getline(db_professori,email,';');
        getline(db_professori,acapo);

        Professore prof(matricola,nome,cognome,email);
        _Professore.push_back(prof);
    }
}

void BaseDati::addProfessore(ifstream & proflist, fstream & db_prof) {
    string matricola,nome,cognome, email,acapo;
    int id_prof = 0, id_stud = 0;
    stringstream buf_matricola;


    while (proflist){
       /* if(!_Studente.empty())
            id_stud = stoi(_Studente.back().getMatricola());*/
        if(!_Professore.empty())
            id_prof=stoi(_Professore.back().getMatricola().substr(1,6));


        if(id_prof>id_stud)
            buf_matricola << setfill ('0') << setw (6) << to_string(++id_prof);

        else
            buf_matricola << setfill ('0') << setw (6) << to_string(++id_stud);


        matricola=buf_matricola.str();
        buf_matricola = (stringstream)"";
        getline(proflist,nome,';');
        getline(proflist,cognome,';');
        getline(proflist,email,';');
        getline(proflist,acapo,'\n');

        Professore prof(matricola,nome,cognome,email);
        _Professore.push_back(prof);

        if(matricola!="000001"&&id_prof!=0)
            db_prof << endl;
        db_prof << prof.getMatricola() << ';' << prof.getName() << ';' << prof.getLastName() << ';' << prof.getEmail() << ';';
    }

}

void BaseDati::setAula(fstream & db_aule) {
    string idaula,tipo,denominazione,capienza_max,capienza_esame,acapo;
    char buffer;

    db_aule >> buffer;
    while(db_aule){
        getline(db_aule,idaula,';');
        if(idaula.size()==3)
            idaula = buffer+idaula;
        getline(db_aule,tipo,';');
        getline(db_aule,denominazione,';');
        getline(db_aule,capienza_max,';');
        getline(db_aule,capienza_esame,';');
        getline(db_aule,acapo);

        Aula aula(idaula,tipo[0],denominazione, stoi(capienza_max), stoi(capienza_esame));
        _Aula.push_back(aula);
    }
}

void BaseDati::addAula(ifstream & aulalist, fstream & db_aule) {
    string idaula,tipo,denominazione,capienza_max,capienza_esame,acapo;
    int code = 0;
    stringstream buf_code;

    while (aulalist) {

        if (!_Aula.empty())
            code = stoi(_Aula.back().getIdAula().substr(1, 3));

        buf_code <<'A'<< setfill ('0') << setw (3) << to_string(++code);

        idaula=buf_code.str();
        buf_code = (stringstream)"";
        getline(aulalist,tipo,';');
        getline(aulalist,denominazione,';');
        getline(aulalist,capienza_max,';');
        getline(aulalist,capienza_esame,';');
        getline(aulalist,acapo);

        Aula aula(idaula,tipo[0],denominazione, stoi(capienza_max), stoi(capienza_esame));
        _Aula.push_back(aula);

        if(idaula!="A001")
            db_aule << endl;

        db_aule << aula.getIdAula() << ';'<< aula.getTipo() << ';'<< aula.getDenominazione() << ';'
                << aula.getMaxCapienza() << ';'<< aula.getCapienzaEsame() << ';';
    }
}

void BaseDati::setCorso(fstream & db_corsi) {
    string c,idcorso,title,cfu,orelez,ores,orelab;
    string anno,attivo,num_versioni,idtitolare,idversione,idassegnato;
    bool flag = true;
    Professore titolare;
    vector<Professore> assegnati;
    vector<Versione> versioni;
    string durata_esame,t_ingresso,t_uscita,modalita,luogo,numero_iscritti_esame;
    string idcorsi,idcorsoN;
    vector<string> raggruppamenti;

    char buffer;

    db_corsi >> buffer;
    while(db_corsi){
        if(_Corso.empty())
            getline(db_corsi,c,';'); //'c'
        getline(db_corsi,idcorso,';');
        getline(db_corsi,title,';');
        getline(db_corsi,cfu,';');
        getline(db_corsi,orelez,';');
        getline(db_corsi,ores,';');
        getline(db_corsi,orelab,'\n');

        Corso corso (idcorso,title, stoi(cfu),stoi(orelez),stoi(ores),stoi(orelab));
       // _Corso.push_back(corso); bisogna farlo alla fine quando ho legato anche anno accademico a corso

        getline(db_corsi,c,';'); //'a'
        while(c=="a"||c=="\na") {

            getline(db_corsi, anno, ';');
            getline(db_corsi, attivo, ';');
            if (attivo=="spento")
                flag = false;
            getline(db_corsi, num_versioni, ';');

            for (int i = 0; i < stoi(num_versioni) ; ++i) {
                if(c!="]},")
                    getline(db_corsi, c, '{'); //'['
                getline(db_corsi, idtitolare, ',');
                getline(db_corsi, idversione, ',');
                getline(db_corsi, c, '{'); //[
                getline(db_corsi, idtitolare, ',');
                idtitolare = idtitolare.substr(1,6);
                getline(db_corsi, orelez, ',');
                getline(db_corsi, ores, ',');
                getline(db_corsi, orelab, '}');

                for (auto &item: _Professore) {
                    if ('d'+idtitolare == item.getMatricola()) {
                        item.setHourLez(stoi(orelez));
                        item.setHourEs(stoi(ores));
                        item.setHourLab(stoi(orelab));

                        titolare = item;
                    }
                }

                getline(db_corsi, c, '{');// ',' oppure ']}];' oppure nel caso di più versioni ']},'
                while (c != "]}];" && c !="]},") {
                    getline(db_corsi, idassegnato, ',');
                    idassegnato = idassegnato.substr(1,6);
                    getline(db_corsi, orelez, ',');
                    getline(db_corsi, ores, ',');
                    getline(db_corsi, orelab, '}');
                    getline(db_corsi, c, '{');// ',' oppure ']}];'

                    for (auto &item: _Professore) {
                        if ('d'+idassegnato == item.getMatricola()) {
                            item.setHourLez(stoi(orelez));
                            item.setHourEs(stoi(ores));
                            item.setHourLab(stoi(orelab));

                            assegnati.push_back(item);
                        }
                    }
                }
                //set vector versione
                Versione versione(titolare,assegnati,idversione);
                versioni.push_back(versione);
                assegnati.clear();
            }
            //ESAME
            getline(db_corsi, durata_esame, ',');
            getline(db_corsi, t_ingresso, ',');
            getline(db_corsi, t_uscita, ',');
            getline(db_corsi, modalita, ',');
            getline(db_corsi, luogo, ',');
            getline(db_corsi, numero_iscritti_esame, '}');

            Esame prova(stoi(durata_esame), stoi(t_ingresso), stoi(t_uscita), modalita[0], luogo[0],
                        stoi(numero_iscritti_esame));

            getline(db_corsi, c, '{');//';'

            //RAGGRUPPAMENTI
            getline(db_corsi, idcorsi, '}');
            if (!idcorsi.empty()) {
                for (int i = 0; i < idcorsi.length(); i += 8) {
                    idcorsoN = idcorsi.substr(i, 7);
                    raggruppamenti.push_back(idcorsoN);
                }
            }
            getline(db_corsi,c,';'); //'a'

            //set vector annoaccademico
            Anno_Accademico accademico(prova,raggruppamenti,versioni,anno,flag,stoi(num_versioni));
            corso.setAnnoAccademico(accademico);
            raggruppamenti.clear();
            versioni.clear();
        }
        // corso push_back in dabase
        _Corso.push_back(corso);
    }
}

void BaseDati::addCorso(ifstream & corsoList, fstream & db_corsi) {

    bool flag = true, trovato = false;
    int oretotlez=0,oretotes,oretotlab;
    string code;
    string c, idcorso, title, cfu, orelez, ores, orelab,orelezcorso,orescorso,orelabcorso;
    string anno, attivo, num_versioni, idtitolare, idversione, idassegnato;
    string idcorsi, idcorsoN;
    string durata_esame, t_ingresso, t_uscita, modalita, luogo, numero_iscritti_esame;
    Professore titolare;
    vector<Professore> assegnati;
    vector<Versione> versioni;
    vector<string> raggruppamenti;

    while (corsoList) {

        if (!_Corso.empty()) {
            code = _Corso.back().getIdCorso().substr(2, 5);
            code = "01" + incrementCourseCode(code);
        } else
            code = "01AAAAA";

        c="\n";

        while (c == "\n") {
            getline(corsoList, anno, ';');
            getline(corsoList, title, ';');
            getline(corsoList, cfu, ';');
            getline(corsoList, orelezcorso, ';');
            getline(corsoList, orescorso, ';');
            getline(corsoList, orelabcorso, ';');

            Corso corso(code, title, stoi(cfu), stoi(orelezcorso), stoi(orescorso), stoi(orelabcorso));

            getline(corsoList, num_versioni, ';');

            for (int i = 0; i < stoi(num_versioni); ++i) {
                if (c != "]},")
                    getline(corsoList, c, '{'); //'['
                getline(corsoList, idtitolare, ',');
                getline(corsoList, idversione, ',');
                getline(corsoList, c, '{'); //[
                getline(corsoList, idtitolare, ',');
                idtitolare = idtitolare.substr(1, 6);
                getline(corsoList, orelez, ',');
                getline(corsoList, ores, ',');
                getline(corsoList, orelab, '}');

                for (auto &item: _Professore) {
                    if ('d'+idtitolare == item.getMatricola()) {
                        item.setHourLez(stoi(orelez));
                        item.setHourEs(stoi(ores));
                        item.setHourLab(stoi(orelab));

                        oretotlez = stoi(orelez);
                        oretotes = stoi(ores);
                        oretotlab = stoi(orelab);

                        titolare = item;
                        trovato = true;

                        break;
                    }
                }

                if(!trovato)
                    throw PersonaInesistente();


                getline(corsoList, c, '{');// ',' oppure ']}];' oppure nel caso di più versioni ']},'
                while (c != "]}];" && c != "]},") {
                    getline(corsoList, idassegnato, ',');
                    idassegnato = idassegnato.substr(1, 6);
                    getline(corsoList, orelez, ',');
                    getline(corsoList, ores, ',');
                    getline(corsoList, orelab, '}');
                    getline(corsoList, c, '{');// ',' oppure ']}];'

                    trovato = false;
                    for (auto &item: _Professore) {
                        if ('d'+idassegnato == item.getMatricola()) {
                            item.setHourLez(stoi(orelez));
                            item.setHourEs(stoi(ores));
                            item.setHourLab(stoi(orelab));

                            oretotlez += stoi(orelez);
                            oretotes += stoi(ores);
                            oretotlab += stoi(orelab);

                            assegnati.push_back(item);
                            trovato = true;
                            break;
                        }
                    }

                    if(!trovato)
                        throw PersonaInesistente();

                }
                //set vector versione
                Versione versione(titolare, assegnati, idversione);
                versioni.push_back(versione);
                assegnati.clear();
            }

            if(stoi(orelezcorso)!= oretotlez || stoi(orescorso)!= oretotes || stoi(orelabcorso)!= oretotlab)
                throw OrariIncompatibili();

            //ESAME
            getline(corsoList, durata_esame, ',');
            getline(corsoList, t_ingresso, ',');
            getline(corsoList, t_uscita, ',');
            getline(corsoList, modalita, ',');
            getline(corsoList, luogo, ',');
            getline(corsoList, numero_iscritti_esame, '}');

            Esame prova(stoi(durata_esame), stoi(t_ingresso), stoi(t_uscita), modalita[0], luogo[0],
                        stoi(numero_iscritti_esame));

            getline(corsoList, c, '{');//';'

            //RAGGRUPPAMENTI
            getline(corsoList, idcorsi, '}');
            if (!idcorsi.empty()) {
                for (int i = 0; i < idcorsi.length(); i += 8) {
                    idcorsoN = idcorsi.substr(i, 7);

                    trovato = false;
                    for (auto &item: _Corso) {
                        if(idcorsoN == item.getIdCorso())
                            trovato = true;
                    }

                    if(!trovato)
                        throw CorsoInesistente();

                    raggruppamenti.push_back(idcorsoN);
                }
            }

            corsoList.get(c[0]);//'\n'

            //set vector annoaccademico
            Anno_Accademico accademico(prova, raggruppamenti, versioni, anno, flag, stoi(num_versioni));
            corso.setAnnoAccademico(accademico);


            if (!_Corso.empty())
                db_corsi <<endl;

            _Corso.push_back(corso);

            db_corsi <<"c;"<< code <<';'<<title<<';'<<cfu<<';'<<orelezcorso<<';'<<orescorso<<';'<<orelabcorso<<"\n"
            <<"a;"<<anno<<';'<<"attivo"<<';'<<num_versioni<<";[";

            for (int i = 0; i < stoi(num_versioni); ++i) {
                db_corsi << "{" << versioni[i].getTitolare().getMatricola() <<','<<versioni[i].getCodiceVersione()
                <<",[{"<< versioni[i].getTitolare().getMatricola() <<','<<versioni[i].getTitolare().getHourLez()
                <<','<<versioni[i].getTitolare().getHourEs() <<','<<versioni[i].getTitolare().getHourLab()<<'}';

                for(int j = 0; j< corso.getAnnoAccademico()[0].getVersione()[i].getAssegnati().size();++j){
                    db_corsi << ",{" << versioni[i].getAssegnati()[j].getMatricola() <<','<<versioni[i].getAssegnati()[j].getHourLez()
                    <<','<<versioni[i].getAssegnati()[j].getHourEs() <<','<<versioni[i].getAssegnati()[j].getHourLab()<<'}';
                }

                if(i < stoi(num_versioni)-1)
                db_corsi << "]},";
            }

            db_corsi <<"]}];{" << prova.getDurata() <<','<< prova.getIngresso() <<','<< prova.getUscita() <<','<< prova.getModalita() <<','<< prova.getLuogo() <<','<< prova.getNumeroIscritti()<<"};{";

            for(int j = 0; j< raggruppamenti.size()-1 && !raggruppamenti.empty();++j){
                db_corsi << raggruppamenti[j]<<',';
            }
            if(!raggruppamenti.empty())
                db_corsi <<raggruppamenti.back() <<'}';
            else
                db_corsi << '}';

            raggruppamenti.clear();
            versioni.clear();
        }
        //set corso in dabase file
    }
}



const string &BaseDati::incrementCourseCode(string & code) {
    bool esci = true;
    int i = 4;

    while(esci && i >= 0){

        if((int)code[i]<90&&(int)code[i]>=65) {
            code[i] = (int)code[i] + 1;
            esci = false;
        }
        else if ((int)code[i] == 90){
            code[i]=65;
            i--;
        }
    }

    return code;
}



void BaseDati::printCourses(std::vector<Corso>& corsi, fstream & db_corsi) const {
    int i = 0;
    for (auto & k : corsi) {
        if(i<=corsi.size() && i>0)
            db_corsi <<endl;
        db_corsi << "c;" << k.getIdCorso() << ';' << k.getTitolo() << ';' << k.getCfu() << ';' << k.getHoursLez() << ';' << k.getHoursEs() << ';'
                 << k.getHoursLab();

        for (int m = 0; m < k.getAnnoAccademico().size(); ++m) {


            db_corsi << "\na;" << k.getAnnoAccademico()[m].getAnnoAccademico() << ';' << (k.getAnnoAccademico()[m].getAttivo() ? "attivo":"spento") << ';' << k.getAnnoAccademico()[m].getNumVers() << ";[";

            for (int i = 0; i < k.getAnnoAccademico()[m].getNumVers() ; ++i) {

                db_corsi << "{" <<k.getAnnoAccademico()[m].getVersione()[i].getTitolare().getMatricola() << ','
                         << k.getAnnoAccademico()[m].getVersione()[i].getCodiceVersione()
                         << ",[{" <<k.getAnnoAccademico()[m].getVersione()[i].getTitolare().getMatricola() << ','
                         << k.getAnnoAccademico()[m].getVersione()[i].getTitolare().getHourLez()
                         << ',' << k.getAnnoAccademico()[m].getVersione()[i].getTitolare().getHourEs() << ','
                         << k.getAnnoAccademico()[m].getVersione()[i].getTitolare().getHourLab()
                         << '}';

                for (int j = 0; j < k.getAnnoAccademico()[0].getVersione()[i].getAssegnati().size(); ++j) {
                    db_corsi << ",{" << k.getAnnoAccademico()[m].getVersione()[i].getAssegnati()[j].getMatricola() << ','
                             << k.getAnnoAccademico()[m].getVersione()[i].getAssegnati()[j].getHourLez()
                             << ',' << k.getAnnoAccademico()[m].getVersione()[i].getAssegnati()[j].getHourEs() << ','
                             << k.getAnnoAccademico()[m].getVersione()[i].getAssegnati()[j].getHourLab() << '}';
                }

                if (i < k.getAnnoAccademico()[m].getNumVers() - 1)
                    db_corsi << "]},";
            }

            db_corsi << "]}];{" << k.getAnnoAccademico()[m].getEsame().getDurata() << ',' << k.getAnnoAccademico()[m].getEsame().getIngresso() << ',' << k.getAnnoAccademico()[m].getEsame().getUscita() << ','
                     << k.getAnnoAccademico()[m].getEsame().getModalita() << ',' << k.getAnnoAccademico()[m].getEsame().getLuogo() << ',' << k.getAnnoAccademico()[m].getEsame().getNumeroIscritti() << "};{";

            for (int j = 0; j < k.getAnnoAccademico()[m].getRaggruppamenti().size() - 1 && !k.getAnnoAccademico()[m].getRaggruppamenti().empty(); ++j) {
                db_corsi << k.getAnnoAccademico()[m].getRaggruppamenti()[j] << ',';
            }
            if (!k.getAnnoAccademico()[m].getRaggruppamenti().empty())
                db_corsi << k.getAnnoAccademico()[m].getRaggruppamenti().back() << '}';
            else
                db_corsi << '}';

            i++;
        }
    }
}


void BaseDati::inserimentoCorsi(ifstream & corsoList, fstream & db_corsi) {

    bool flag = true, trovato = false;
    int oretotlez=0,oretotes,oretotlab,orelezcorso,orescorso,orelabcorso;
    string code;
    string c, idcorso, title, cfu, orelez, ores, orelab;
    string anno, attivo, num_versioni, idtitolare, idversione, idassegnato;
    string idcorsi, idcorsoN;
    string durata_esame, t_ingresso, t_uscita, modalita, luogo, numero_iscritti_esame;
    size_t i,j;


    while (corsoList) {
        getline(corsoList, idcorso, ';');

        for (i=0;i<_Corso.size();++i) {
            if(_Corso[i].getIdCorso()==idcorso) {
                trovato = true;
                break;
            }
        }
        if (!trovato)
            throw CorsoInesistente();

        getline(corsoList, anno, ';');

        trovato = false;
        for (j=0;j<_Corso[i].getAnnoAccademico().size();++j) {
            if(_Corso[i].getAnnoAccademico()[j].getAnnoAccademico()==anno) {
                trovato = true;
                break;
            }
        }

        if(!trovato){
            _Corso[i].setAnnoAccademico(_Corso[i].getAnnoAccademico().back());
            j=_Corso[i].getAnnoAccademico().size()-1;
            _Corso[i].getAnnoAccademico()[j].setAnnoAccademico(anno);

        }

        //prendi valori diversi da "", cioè non vuoti e settali
        getline(corsoList, attivo, ';');
        if(!attivo.empty()) {
            if(attivo=="attivo")
                flag = true;
            if(attivo=="spento") {
                flag = false;
                setCorsoSpento(_Corso[i].getIdCorso());
            }
            _Corso[i].getAnnoAccademico()[j].setAttivo(flag);
        }
        getline(corsoList, num_versioni, ';');
        if(!num_versioni.empty())
            _Corso[i].getAnnoAccademico()[j].setNumVers(stoi(num_versioni));
        else
            num_versioni = to_string(_Corso[i].getAnnoAccademico()[j].getNumVers());

        for (int k = 0; k < stoi(num_versioni); ++k) {
            if (c != "]},")
                getline(corsoList, c, '{'); //'['
            getline(corsoList, idtitolare, ',');
            getline(corsoList, idversione, ',');
            if(!idversione.empty())
                _Corso[i].getAnnoAccademico()[j].getVersione()[k].setCodiceVersione(idversione);
            getline(corsoList, c, '{'); //[
            getline(corsoList, idtitolare, ',');
            idtitolare = idtitolare.substr(1, 6);
            if(!idtitolare.empty())
                _Corso[i].getAnnoAccademico()[j].getVersione()[k].getTitolare().setMatricola(idtitolare);
            getline(corsoList, orelez, ',');

            getline(corsoList, ores, ',');

            getline(corsoList, orelab, '}');

            for (auto &item: _Professore) {
                if ('d'+idtitolare == item.getMatricola()) {
                    if(!orelez.empty())
                        _Corso[i].getAnnoAccademico()[j].getVersione()[k].getTitolare().setHourLez(stoi(orelez));
                    else
                        orelez = to_string(_Corso[i].getAnnoAccademico()[j].getVersione()[k].getTitolare().getHourLez());
                    if(!ores.empty())
                        _Corso[i].getAnnoAccademico()[j].getVersione()[k].getTitolare().setHourEs(stoi(ores));
                    else
                        ores = to_string(_Corso[i].getAnnoAccademico()[j].getVersione()[k].getTitolare().getHourEs());
                    if(!orelab.empty())
                        _Corso[i].getAnnoAccademico()[j].getVersione()[k].getTitolare().setHourLab(stoi(orelab));
                    else
                        orelab = to_string(_Corso[i].getAnnoAccademico()[j].getVersione()[k].getTitolare().getHourLab());

                    oretotlez = stoi(orelez);
                    oretotes = stoi(ores);
                    oretotlab = stoi(orelab);

                    trovato = true;

                    break;
                }
            }

            if(!trovato)
                throw PersonaInesistente();


            getline(corsoList, c, '{');// ',' oppure ']}];' oppure nel caso di più versioni ']},'
            int m = 0;
            while (c != "]}];" && c != "]},") {

                getline(corsoList, idassegnato, ',');
                idassegnato = idassegnato.substr(1, 6);
                if(!idassegnato.empty())
                    _Corso[i].getAnnoAccademico()[j].getVersione()[k].getAssegnati()[m].setMatricola(idassegnato);
                getline(corsoList, orelez, ',');
                getline(corsoList, ores, ',');
                getline(corsoList, orelab, '}');
                getline(corsoList, c, '{');// ',' oppure ']}];'

                trovato = false;
                for (auto &item: _Professore) {
                    if ('d'+idassegnato == item.getMatricola()) {
                        if(!orelez.empty())
                            _Corso[i].getAnnoAccademico()[j].getVersione()[k].getAssegnati()[m].setHourLez(stoi(orelez));
                        else
                            orelez = to_string(_Corso[i].getAnnoAccademico()[j].getVersione()[k].getAssegnati()[m].getHourLez());
                        if(!ores.empty())
                            _Corso[i].getAnnoAccademico()[j].getVersione()[k].getAssegnati()[m].setHourEs(stoi(ores));
                        else
                            ores = to_string(_Corso[i].getAnnoAccademico()[j].getVersione()[k].getAssegnati()[m].getHourEs());
                        if(!orelab.empty())
                            _Corso[i].getAnnoAccademico()[j].getVersione()[k].getAssegnati()[m].setHourLab(stoi(orelab));
                        else
                            orelab = to_string(_Corso[i].getAnnoAccademico()[j].getVersione()[k].getAssegnati()[m].getHourLab());

                        oretotlez += stoi(orelez);
                        oretotes += stoi(ores);
                        oretotlab += stoi(orelab);

                        trovato = true;
                        break;
                    }
                }

                if(!trovato)
                throw PersonaInesistente();
                m++;


            }
            if(c == "]}];" && k != stoi(num_versioni)-1)
                throw NumeroVersioniIncompatibile();
                //se c= a parentesi fine ma k diverso da numeri versione throw NumeroVersioniIncompatibile con formato

            orelezcorso=_Corso[i].getHoursLez();
            orescorso=_Corso[i].getHoursEs();
            orelabcorso=_Corso[i].getHoursLab();
            if((orelezcorso)!= oretotlez || (orescorso)!= oretotes ||(orelabcorso)!= oretotlab)
                throw OrariIncompatibili();
            oretotlab = 0;
            oretotlez = 0;
            oretotes = 0;
        }


        //ESAME
        getline(corsoList, durata_esame, ',');
        if(!durata_esame.empty())
            _Corso[i].getAnnoAccademico()[j].getEsame().setDurata(stoi(durata_esame));
        getline(corsoList, t_ingresso, ',');
        if(!t_ingresso.empty())
            _Corso[i].getAnnoAccademico()[j].getEsame().setIngresso(stoi(t_ingresso));
        getline(corsoList, t_uscita, ',');
        if(!t_uscita.empty())
            _Corso[i].getAnnoAccademico()[j].getEsame().setUscita(stoi(t_uscita));
        getline(corsoList, modalita, ',');
        if(!modalita.empty())
            _Corso[i].getAnnoAccademico()[j].getEsame().setModalita(modalita);
        getline(corsoList, luogo, ',');
        if(!luogo.empty())
            _Corso[i].getAnnoAccademico()[j].getEsame().setLuogo(luogo[0]);
        getline(corsoList, numero_iscritti_esame, '}');
        if(!numero_iscritti_esame.empty())
            _Corso[i].getAnnoAccademico()[j].getEsame().setNumeroIscritti(stoi(numero_iscritti_esame));

        getline(corsoList, c, '{');//';'
        if (c==";") {
            //RAGGRUPPAMENTI
            getline(corsoList, idcorsi, '}');
            if (idcorsi.empty())
                _Corso[i].getAnnoAccademico()[j].getRaggruppamenti().clear();
            else {
                for (int m = 0; m < idcorsi.length(); m += 8) {
                    idcorsoN = idcorsi.substr(m, 7);
                    _Corso[i].getAnnoAccademico()[j].setRaggruppamento(idcorsoN);
                    trovato = false;
                    for (auto &item: _Corso) {
                        if (idcorsoN == item.getIdCorso())
                            trovato = true;
                    }

                   if (!trovato)
                        throw CorsoInesistente();
                }
            }
            getline(corsoList, c, '{');
        }
    }

    printCourses(_Corso, db_corsi);
}

template<typename T>
void BaseDati::printPersone(const vector<T>& persona, fstream & db_persone)const {
    for (auto & i:persona)
        db_persone << i.getMatricola() << ';' << i.getName() << ';' << i.getLastName() << ';' <<i.getEmail() << ';'<<endl;
}

void BaseDati::updatePersona(ifstream & personaList, fstream & db_persone) {
    string matricola,nome,cognome, email,acapo;
    size_t i;
    bool trovato = false;

    while(personaList){
        getline(personaList,matricola,';');
        if(matricola[0]=='s') {
            for (i = 0; i < _Studente.size(); ++i) {
                if (_Studente[i].getMatricola() == matricola) {
                    trovato = true;
                    break;
                }
            }
        }

        if(matricola[0]=='d') {
            for (i = 0; i < _Professore.size(); ++i) {
                if (_Professore[i].getMatricola() == matricola) {
                    trovato = true;
                    break;
                }
            }
        }

        if (!trovato)
            throw PersonaInesistente();

        getline(personaList,nome,';');
        if(!nome.empty() && matricola[0]=='d')
            _Professore[i].setName(nome);
        if(!nome.empty() && matricola[0]=='s')
            _Studente[i].setName(nome);
        getline(personaList,cognome,';');
        if(!cognome.empty() && matricola[0]=='d')
            _Professore[i].setLastName(cognome);
        if(!cognome.empty() && matricola[0]=='s')
            _Studente[i].setLastName(cognome);
        getline(personaList,email,';');
        if(!email.empty() && matricola[0]=='d')
            _Professore[i].setEmail(email);
        if(!email.empty() && matricola[0]=='s')
            _Studente[i].setEmail(email);
        getline(personaList,acapo,'\n');
    }
    if(matricola[0]=='s')
        printPersone(_Studente,db_persone);
    else
        printPersone(_Professore,db_persone);
}

void BaseDati::printAule(const vector<Aula> & aule, fstream & db_aule) const {
    for (auto const & a:aule)
    db_aule << a.getIdAula() << ';'<< a.getTipo() << ';'<< a.getDenominazione() << ';'
            << a.getMaxCapienza() << ';'<< a.getCapienzaEsame() << ';'<<endl;
}

void BaseDati::updateAule(ifstream & auleList, fstream & db_aule) {
    string idaula,tipo,denominazione,capienza_max,capienza_esame,acapo;
    bool trovato = false;
    size_t i;

    while (auleList){
        getline(auleList,idaula,';');

        for (i = 0; i < _Studente.size(); ++i) {
            if (_Aula[i].getIdAula() == idaula) {
                trovato = true;
                break;
            }
        }

        if(!trovato)
            throw AulaInesistente();

        getline(auleList,tipo,';');
        if(!tipo.empty())
            _Aula[i].setTipoAula(tipo[0]);
        getline(auleList,denominazione,';');
        if(!denominazione.empty())
            _Aula[i].setDenominazione(denominazione);
        getline(auleList,capienza_max,';');
        if(!capienza_max.empty())
            _Aula[i].setMaxCapienza(stoi(capienza_max));
        getline(auleList,capienza_esame,';');
        if(!capienza_esame.empty())
            _Aula[i].setCapienzaEsame(stoi(capienza_esame));
        getline(auleList,acapo,'\n');
    }

    printAule(_Aula,db_aule);
}

void BaseDati::setCorsoStudi(fstream & db_corsostudi) {

    string c,idstudi,degree,idcorsi,idN,idspenti,idM;
    stringstream corsi,spenti;
    vector<string> idcorsiN,idspentiM;
    vector<Semestre> semestre;
    char buffer;

    db_corsostudi>>buffer;
    while (db_corsostudi) {
        getline(db_corsostudi, idstudi, ';');
        getline(db_corsostudi, degree, ';');
        getline(db_corsostudi, c, '[');
        getline(db_corsostudi, idcorsi, ']');
        corsi << idcorsi;
        while (corsi) {
            getline(corsi, c, '{');
            do{
                getline(corsi, idN, ',');
                idcorsiN.push_back(idN);
            }while(idN.size()==7);

            idcorsiN.back().pop_back();
            Semestre semestre1(idcorsiN);
            semestre.push_back(semestre1);
        }

        getline(db_corsostudi,c,'[');
        getline(db_corsostudi,idspenti,']');
        spenti << idspenti;
        if(!idspenti.empty()) {
            do {
                getline(spenti, idM, ',');
                idspentiM.push_back(idM);
            } while (idN.size() == 7);

            idspentiM.back().pop_back();
            idspentiM.push_back(idM);
        }
        Corso_di_Studio studio(idstudi,degree,semestre,idspentiM);
        _Corso_di_Studio.push_back(studio);
    }
}

void BaseDati::addCorsoStudi(ifstream & corsoStudioList, fstream & db_corsostudi) {
    bool trovato = false,esci = false;
    int code = 0;
    string idcorsostudi;
    string c, degree, idcorsi, idN, idspenti, idM;
    stringstream corsi, spenti;
    vector<string> idcorsiN, idspentiM;
    vector<Semestre> semestre;
    stringstream buf_code;

    while (corsoStudioList) {

        if (!_Corso_di_Studio.empty())
            code = stoi(_Corso_di_Studio.back().getIdCorsoStudio().substr(1, 3));

        buf_code << 'C' << setfill('0') << setw(3) << to_string(++code);

        idcorsostudi = buf_code.str();
        buf_code = (stringstream) "";
        getline(corsoStudioList, degree, ';');
        getline(corsoStudioList, c, '[');
        getline(corsoStudioList, idcorsi, ']');
        corsi << idcorsi;
        while (corsi) {
            do {
                if(getline(corsi, idN, ',').eof())
                    break;
                if (idN.size()!=7) {
                    if (idN[7] == '}') {
                        idN.pop_back();
                        esci = true;
                    }
                    if (idN[0] == '{')
                        idN = idN.substr(1,7);
                }
                for (auto const & item:_Corso) {
                    if(item.getIdCorso() == idN) {
                        trovato = true;
                        break;
                    }
                }
                if(!trovato)
                    throw CorsoInesistente();

                idcorsiN.push_back(idN);
            } while (!esci);

            Semestre semestre1(idcorsiN);
            semestre.push_back(semestre1);
            esci = false;
        }

        getline(corsoStudioList, c, '[');
        getline(corsoStudioList, idspenti, ']');
        if(!idspenti.empty()) {
            spenti << idspenti;
            do {
                getline(spenti, idM, ',');
                idspentiM.push_back(idM);
            } while (idN.size() == 7);

            idspentiM.back().pop_back();
            idspentiM.push_back(idM);
        }

        Corso_di_Studio studio(idcorsostudi, degree, semestre, idspentiM);
        _Corso_di_Studio.push_back(studio);

        printCoursoStudio(_Corso_di_Studio, db_corsostudi);

    }
}

void BaseDati::printCoursoStudio(vector<Corso_di_Studio> &corsiStudio, fstream &db_corsi_studio) const {
    for (auto const &a: corsiStudio) {
        db_corsi_studio << a.getIdCorsoStudio() << ';' << a.getDegree() << ";[";
        for (int i = 0; i < a.getSemestre().size(); ++i) {
            db_corsi_studio <<'{';
            for (int j = 0; j < a.getSemestre()[i].getCorsiSemestre().size()-1; ++j) {
                db_corsi_studio << a.getSemestre()[i].getCorsiSemestre()[j] <<',';
            }
            db_corsi_studio << a.getSemestre()[i].getCorsiSemestre()[a.getSemestre()[i].getCorsiSemestre().size()] <<"},";
        }

        db_corsi_studio << "];[";

        for (int i = 0; i < a.getCorsiSpenti().size()-1; ++i) {
            db_corsi_studio << a.getCorsiSpenti()[i] << ',';
        }
        db_corsi_studio << a.getCorsiSpenti()[a.getCorsiSpenti().size()] << ']' <<endl;
    }
}

void BaseDati::setCorsoSpento(const string & idspento) {
    for (auto item: _Corso_di_Studio) {
        for (int i = 0; i < item.getSemestre().size(); ++i) {
            for (auto j: item.getSemestre()[i].getCorsiSemestre()) {
                if (j == idspento) {
                    j.erase();
                    item.setCorsiSpenti(idspento);
                }
            }
        }
    }
}
