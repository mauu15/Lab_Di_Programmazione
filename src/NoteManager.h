
#ifndef LAB_DI_PROGRAMMAZIONE_NOTEMANAGER_H
#define LAB_DI_PROGRAMMAZIONE_NOTEMANAGER_H


#include "Note.h"
#include <vector>
#include "Collection.h"

class NoteManager {
private:
    std::vector<Note> notes;
    std::vector<Collection> collections;

public:
    void addNote(const Note& note);
    bool deleteNoteByTitle(const std::string& title);
    Note* findNoteByTitle(const std::string& title);
    std::vector<Note> searchNotesByContent(const std::string& content) const;
    std::vector<Note> getAllNotes() const;

    std::vector<Note> getFavoriteNotes() const;
    void setFavorite(const std::string& title, bool isFavorite);
    void setLocked(const std::string& title, bool isLocked);

    void addCollection(const std::string& name);
    Collection* findCollectionByName(const std::string& name);
};


#endif //LAB_DI_PROGRAMMAZIONE_NOTEMANAGER_H
