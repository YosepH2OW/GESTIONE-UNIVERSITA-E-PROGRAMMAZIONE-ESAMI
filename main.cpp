#include <iostream>

#define ERROR_PARAMETERS -1

#include "Eccezioni.h"
#include "BaseDati.h"
#include "Scheduling.h"

using namespace std;

enum class Choice {AGGIUNGI_STUDENTE = 1,AGGIUNGI_PROFESSORE,AGGIUNGI_AULA,AGGIUNGI_CORSO,AGGIUNGI_CORSO_STUDIO,AGGIORNA_STUDENTI,
        AGGIORNA_PROFESSORI,AGGIORNA_AULE,ORGANIZZAZIONE_CORSO,SET_EXAMPERIOD,SET_AVAILABILITY,SCHEDULING};

bool formatoComando(char **);

int switchCase (const char * argo1,const char * argo2);

int main(int argc, char * argv[]) {
    Choice choice;
    BaseDati baseDati;

    fstream studentFile{"db_studenti.txt", ios::out | ios::in | ios::app};
    if(!studentFile) {
        cerr << "studentFile could not be opened" << endl;
        exit(EXIT_FAILURE);
    }
    fstream profFile{"db_professori.txt", ios::out | ios::in | ios::app};
    if(!profFile) {
        cerr << "profFile could not be opened" << endl;
        exit(EXIT_FAILURE);
    }
    fstream aulaFile{"db_aule.txt", ios::out | ios::in | ios::app};
    if(!aulaFile) {
        cerr << "aulaFile could not be opened" << endl;
        exit(EXIT_FAILURE);
    }
    fstream corsoFile{"db_corsi.txt", ios::out | ios::in | ios::app};
    if(!corsoFile) {
        cerr << "corsoFile could not be opened" << endl;
        exit(EXIT_FAILURE);
    }
    fstream corsoStudiFile{"db_corsi_studio.txt", ios::out | ios::in | ios::app};
    if(!corsoStudiFile) {
        cerr << "corsoStudiFile could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    fstream periodiFile{"db_periodi_esami.txt", ios::out | ios::in | ios::app};
    if(!periodiFile) {
        cerr << "periodiFile could not be opened" << endl;
        exit(EXIT_FAILURE);
    }
    fstream indiDb{"db_indisponibilita.txt", ios::out | ios::in | ios::app};
    if(!indiDb) {
        cerr << "indiDb could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    baseDati.setStudente(studentFile);
    baseDati.setProfessore(profFile);
    baseDati.setAula(aulaFile);
    baseDati.setCorso(corsoFile);
    baseDati.setCorsoStudi(corsoStudiFile);

    Scheduling scheduling(baseDati);

    scheduling.setPeriodoEsami(periodiFile);
    scheduling.setIndisponibilita(indiDb);

    if(argc > 7 || argc < 3){
        cerr << "Errore nei parametri" << endl;
        return ERROR_PARAMETERS;
    }

    if(!formatoComando(argv)){
        cerr << "Errore nei parametri" << endl;
        return ERROR_PARAMETERS;
    }

    choice = static_cast<Choice>(switchCase(argv[1],argv[2]));

    switch (choice) {

        case Choice::AGGIUNGI_STUDENTE: {
            ifstream studentList{argv[2], ios::in};

            studentList.seekg(0); // per portare qualsiasi file dall'esterno

            studentFile.close();
            studentFile.open("db_studenti.txt", ios::out | ios::app);

            baseDati.addStudente(studentList, studentFile);

            studentFile.close();
            studentList.close();
            break;
        }
        case Choice::AGGIUNGI_PROFESSORE: {
            ifstream profList{argv[2], ios::in};

            profList.seekg(0); // per portare qualsiasi file dall'esterno

            profFile.close();
            profFile.open("db_professori.txt", ios::out | ios::app);

            baseDati.addProfessore(profList, profFile);

            profFile.close();
            profList.close();
            break;
        }
        case Choice::AGGIUNGI_AULA: {
            ifstream aulaList{argv[2], ios::in};

            aulaList.seekg(0); // per portare qualsiasi file dall'esterno

            aulaFile.close();
            aulaFile.open("db_aule.txt", ios::out | ios::app);

            baseDati.addAula(aulaList, aulaFile);

            aulaFile.close();
            aulaList.close();
            break;
        }
        case Choice::AGGIUNGI_CORSO: {
            ifstream corsoList{argv[2], ios::in};

            corsoList.seekg(0);

            corsoFile.close();
            corsoFile.open("db_corsi.txt", ios::out | ios::app);

            baseDati.addCorso(corsoList, corsoFile);

            corsoFile.close();
            corsoList.close();
            break;
        }
        case Choice::AGGIUNGI_CORSO_STUDIO:{
            ifstream corsoStudiList{argv[2], ios::in};

            corsoStudiList.seekg(0);

            corsoStudiFile.close();
            corsoStudiFile.open("db_corsi_studio.txt", ios::out | ios::trunc);

            baseDati.addCorsoStudi(corsoStudiList, corsoStudiFile);

            corsoStudiFile.close();
            corsoStudiList.close();
            break;
         }
        case Choice::AGGIORNA_STUDENTI:{
            ifstream studentList{argv[2], ios::in};

            studentList.seekg(0);

            studentFile.close();
            studentFile.open("db_studenti.txt", ios::out | ios::trunc);

            baseDati.updatePersona(studentList, studentFile);

            studentFile.close();
            studentList.close();
            break;
        }
        case Choice::AGGIORNA_PROFESSORI:{
            ifstream profList{argv[2], ios::in};

            profList.seekg(0);

            profFile.close();
            profFile.open("db_professori.txt", ios::out | ios::trunc);

            baseDati.updatePersona(profList, profFile);

            profFile.close();
            profList.close();
            break;
        }
        case Choice::AGGIORNA_AULE:{
            ifstream aulaList{argv[2], ios::in};

            aulaList.seekg(0);

            aulaFile.close();
            aulaFile.open("db_aule.txt", ios::out | ios::trunc);

            baseDati.updateAule(aulaList, aulaFile);

            aulaFile.close();
            aulaList.close();
            break;
        }
        case Choice::ORGANIZZAZIONE_CORSO:{
            ifstream corsoList{argv[2], ios::in};

            corsoList.seekg(0);

            corsoFile.close();
            corsoFile.open("db_corsi.txt", ios::out | ios::trunc);

            baseDati.inserimentoCorsi(corsoList, corsoFile);

            corsoFile.close();
            corsoList.close();
            break;
        }
        case Choice::SET_EXAMPERIOD: {
            string anno = argv[3];
            string periodo1 = argv[4],periodo2 = argv[5],periodo3 = argv[6];

            Periodo_Esami exam_period(anno);

            Periodo periodo_1(periodo1.substr(0,10),periodo1.substr(11,10));
            exam_period.setPeriodo(periodo_1);
            Periodo periodo_2(periodo2.substr(0,10),periodo2.substr(11,10));
            exam_period.setPeriodo(periodo_2);
            Periodo periodo_3(periodo3.substr(0,10),periodo3.substr(11,10));
            exam_period.setPeriodo(periodo_3);


            scheduling.setPeriodoEsame(exam_period);

            periodiFile.close();
            periodiFile.open("db_periodi_esami.txt", ios::out | ios::trunc);
            scheduling.addPeriodoEsami(periodiFile);

            periodiFile.close();
            break;
        }
        case Choice::SET_AVAILABILITY: {
            ifstream indiList{argv[4], ios::in};
            string anno = argv[3];

            indiList.seekg(0);

            indiDb.close();
            indiDb.open("db_indisponibilita.txt", ios::out | ios::trunc);

            scheduling.addIndisponibilita(anno,indiList, indiDb);

            indiDb.close();
            indiList.close();

            break;
        }
        case Choice::SCHEDULING: {
            char c;
            string argv3 = argv[3];
            size_t found = argv3.find_last_of('.');
            argv3 = argv3.substr(0,found-1);
            ofstream examFile1{argv3+"_s1.txt",ios ::out};
            ofstream examFile2{argv3+"_s2.txt",ios ::out};
            ofstream examFile3{argv3+"_s3.txt",ios ::out};

            string anno = argv[2];

            //ofstream warnings{argv3+"_s"+c+"_warnings.txt",ios ::out};
            break;
        }
    }

    return 0;
}

bool formatoComando(char ** argo){
    bool flag = false;

    if(argo[1][0]=='-'&&argo[1][2]==':') {
        if (argo[1][1] == 'a')
            if(argo[1][3]=='s'||argo[1][3]=='d'||argo[1][3]=='a'||argo[1][3]=='c'||argo[1][3]=='f')
                flag = true;
        if(argo[1][1] == 'u')
            if(argo[1][3]=='s'||argo[1][3]=='d'||argo[1][3]=='a')
                flag = true;
        if(argo[1][1] == 'i'&&argo[1][3]=='c')
            flag = true;
    }

    string argo1 = argo[1], argo2 = argo[2];
    if (argo1 == "-s" && argo2 =="current_a"|| argo2 =="set_availability" || argo1 == "-g") //se non funziona dividere in due if prendendo un carattere per volta
        flag = true;

    return flag;
}

int switchCase (const char * argo1,const char * argo2){
    int i = 0;
    if (argo1[1]=='a') {
        if (argo1[3] == 's')
            i = 1;
        if (argo1[3] == 'd')
            i = 2;
        if (argo1[3] == 'a')
            i = 3;
        if (argo1[3] == 'c')
            i = 4;
        if (argo1[3] == 'f')
            i = 5;
    }
    if (argo1[1]=='u') {
        if (argo1[3] == 's')
            i = 6;
        if (argo1[3] == 'd')
            i = 7;
        if (argo1[3] == 'a')
            i = 8;
    }

    if (argo1[1]=='i' && argo1[3]=='c')
        i = 9;

    if (argo1[1]=='s') {
        if (argo2[0] == 'c')
            i = 10;
        if (argo2[0] == 's')
            i = 11;
    }

    if (argo1[2]=='g')
        i = 12;

    return i;
}