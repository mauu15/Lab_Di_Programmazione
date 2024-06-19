#ifndef LAB_DI_PROGRAMMAZIONE_COLLECTION_H
#define LAB_DI_PROGRAMMAZIONE_COLLECTION_H

#include <string>
#include <vector>
#include <algorithm>
#include "Note.h"

class Collection {
private:
    std::string name;
    std::vector<Note*> notes;

public:
    explicit Collection(std::string  name);

    void addNote(Note* note);
    void removeNote(Note* note);
    int getNoteCount() const;

    const std::string& getName() const;
    const std::vector<Note*>& getNotes() const;
};

#endif //LAB_DI_PROGRAMMAZIONE_COLLECTION_H
