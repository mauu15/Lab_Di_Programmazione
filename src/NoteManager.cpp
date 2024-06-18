#include "NoteManager.h"
#include <algorithm>

void NoteManager::addNote(const Note& note) {
    notes.push_back(note);
}

void NoteManager::deleteNoteByTitle(const std::string& title) {
    notes.erase(std::remove_if(notes.begin(), notes.end(), [&title](const Note& note) {
        return note.getTitle() == title;
    }), notes.end());
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
