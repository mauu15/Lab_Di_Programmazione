
#ifndef LAB_DI_PROGRAMMAZIONE_NOTE_H
#define LAB_DI_PROGRAMMAZIONE_NOTE_H

#include <string>

class Collection;

class Note {
private:
    std::string title;
    std::string content;
    bool isFavorite{};
    bool isLocked{};
    Collection* collection{};

public:

    Note(std::string title, std::string content);

    std::string getTitle() const;
    std::string getContent() const;

    void setTitle(const std::string &title);
    void setContent(const std::string &content);

    bool getIsFavorite() const;
    void setIsFavorite(bool isFavorite);

    bool getIsLocked() const;
    void setIsLocked(bool isLocked);

    Collection *getCollection() const;
    void setCollection(Collection* collection);
};

#endif //LAB_DI_PROGRAMMAZIONE_NOTE_H
