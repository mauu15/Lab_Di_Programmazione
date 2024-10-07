// Collection.h
#ifndef LAB_DI_PROGRAMMAZIONE_COLLECTION_H
#define LAB_DI_PROGRAMMAZIONE_COLLECTION_H

#include <string>
#include <vector>
#include <algorithm>
#include "Note.h"
#include "Observer.h"

class Collection {
private:
    std::string name;
    std::vector<Note*> notes;
    std::vector<Observer*> observers;

    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update(notes.size());
        }
    } //funzione che notifica gli osservatori

public:
    explicit Collection(std::string name);

    void addNote(Note* note);
    void removeNote(Note* note);
    int getNoteCount() const;

    const std::string& getName() const;
    const std::vector<Note*>& getNotes() const;

    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
};

#endif //LAB_DI_PROGRAMMAZIONE_COLLECTION_H
