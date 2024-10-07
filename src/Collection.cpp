// Collection.cpp
#include "Collection.h"

#include <utility>

Collection::Collection(std::string name) : name(std::move(name)) {}

const std::string& Collection::getName() const {
    return name;
}

void Collection::addNote(Note* note) {
    notes.push_back(note);
    notifyObservers();
}

void Collection::removeNote(Note* note) {
    notes.erase(std::remove(notes.begin(), notes.end(), note), notes.end());
    notifyObservers();
}

const std::vector<Note*>& Collection::getNotes() const {
    return notes;
}

int Collection::getNoteCount() const {
    return notes.size();
}

void Collection::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void Collection::removeObserver(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}