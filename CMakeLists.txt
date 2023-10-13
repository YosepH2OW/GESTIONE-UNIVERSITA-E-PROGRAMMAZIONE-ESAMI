cmake_minimum_required(VERSION 3.21)
project(Progetto_Algoritmi)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

add_executable(Progetto_Algoritmi main.cpp Aula.cpp Aula.h Corso_di_Studio.cpp Corso_di_Studio.h Corso.cpp Corso.h Professore.cpp Professore.h Studente.cpp Studente.h Eccezioni.cpp Eccezioni.h Persona.cpp Persona.h Esame.cpp Esame.h Data.cpp Data.h Anno_Accademico.cpp Anno_Accademico.h BaseDati.cpp BaseDati.h Semestre.cpp Semestre.h Versione.cpp Versione.h Periodo.cpp Periodo.h Periodo_Esami.cpp Periodo_Esami.h Indisponibilita.cpp Indisponibilita.h Indisponibile.cpp Indisponibile.h Scheduling.cpp Scheduling.h Elenco_Esame.cpp Elenco_Esame.h Fascia_Oraria.cpp Fascia_Oraria.h Giorno_Sessione.cpp Giorno_Sessione.h)
