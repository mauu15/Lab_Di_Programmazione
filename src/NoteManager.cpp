#include "NoteManager.h"
#include "Collection.h"


void NoteManager::addNote(const Note& note) {
    notes.push_back(note);
    if (note.getCollection() != nullptr) {
        note.getCollection()->addNote(&notes.back());
    }
}

bool NoteManager::deleteNoteByTitle(const std::string& title) {
    auto it = std::find_if(notes.begin(), notes.end(), [&title](const Note& note) {
        return note.getTitle() == title && !note.getIsLocked();
    });
    if (it != notes.end()) {
        if (it->getCollection() != nullptr) {
            it->getCollection()->removeNote(&(*it));
        }
        notes.erase(it);
        return true; // Return true if deletion was successful
    }
    return false; // Return false if note with title was not found or was locked
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

void NoteManager::addCollection(const std::string& name) {
    collections.emplace_back(name);
}

Collection* NoteManager::findCollectionByName(const std::string& name) {
    for (auto& collection : collections) {
        if (collection.getName() == name) {
            return &collection;
        }
    }
    return nullptr;
}