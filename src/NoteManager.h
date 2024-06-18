
#ifndef LAB_DI_PROGRAMMAZIONE_NOTEMANAGER_H
#define LAB_DI_PROGRAMMAZIONE_NOTEMANAGER_H


#include "Note.h"
#include <vector>

class NoteManager {
private:
    std::vector<Note> notes;

public:
    void addNote(const Note& note);
    void deleteNoteByTitle(const std::string& title);
    Note* findNoteByTitle(const std::string& title);
    std::vector<Note> searchNotesByContent(const std::string& content) const;
    std::vector<Note> getAllNotes() const;
};


#endif //LAB_DI_PROGRAMMAZIONE_NOTEMANAGER_H
