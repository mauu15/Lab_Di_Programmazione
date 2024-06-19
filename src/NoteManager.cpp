#include "NoteManager.h"
#include <algorithm>

void NoteManager::addNote(const Note& note) {
    notes.push_back(note);
}

bool NoteManager::deleteNoteByTitle(const std::string &title) {
    for (auto it = notes.begin(); it != notes.end(); ++it) {
        if (it->getTitle() == title) {
            if (it->getIsLocked()) {
                return false; // Non cancella la nota se è bloccata
            }
            notes.erase(it);
            return true;
        }
    }
    return false;
}

Note* NoteManager::findNoteByTitle(const std::string& title) {
    for (auto& note : notes) {
        if (note.getTitle() == title) {
            return &note;
        }
    }
    return nullptr;
}

std::vector<Note> NoteManager::searchNotesByContent(const std::string& content) const {
    std::vector<Note> results;
    for (const auto& note : notes) {
        if (note.getContent().find(content) != std::string::npos) {
            results.push_back(note);
        }
    }
    return results;
}

std::vector<Note> NoteManager::getAllNotes() const {
    return notes;
}

std::vector<Note> NoteManager::getFavoriteNotes() const {
    std::vector<Note> favorites;
    for (const auto& note : notes) {
        if (note.getIsFavorite()) {
            favorites.push_back(note);
        }
    }
    return favorites;
}

void NoteManager::setFavorite(const std::string& title, bool isFavorite) {
    Note* note = findNoteByTitle(title);
    if (note) {
        note->setIsFavorite(isFavorite);
    }
}

void NoteManager::setLocked(const std::string& title, bool isLocked) {
    Note* note = findNoteByTitle(title);
    if (note) {
        note->setIsLocked(isLocked);
    }
}
