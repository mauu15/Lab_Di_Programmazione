// NoteCountObserver.h
#ifndef LAB_DI_PROGRAMMAZIONE_NOTECOUNTOBSERVER_H
#define LAB_DI_PROGRAMMAZIONE_NOTECOUNTOBSERVER_H

#include "Observer.h"
#include <iostream>

class NoteCountObserver : public Observer {
public:
    void update(int noteCount) override {
        std::cout << "Numero di note nella collezione: " << noteCount << std::endl;
    }
};

// Classe necessaria per implementare la funzione update dell'interfaccia Observer, che stampa a video il numero di note presenti nella collezione

#endif //LAB_DI_PROGRAMMAZIONE_NOTECOUNTOBSERVER_H
