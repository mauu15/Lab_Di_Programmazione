// Collection.cpp
#include "Collection.h"

#include <utility>

Collection::Collection(std::string  name) : name(std::move(name)) {}

const std::string& Collection::getName() const {
    return name;
}

void Collection::addNote(Note* note) {
    notes.push_back(note);
}

void Collection::removeNote(Note* note) {
    notes.erase(std::remove(notes.begin(), notes.end(), note), notes.end());
}

const std::vector<Note*>& Collection::getNotes() const {
    return notes;
}

int Collection::getNoteCount() const {
    return notes.size();
}