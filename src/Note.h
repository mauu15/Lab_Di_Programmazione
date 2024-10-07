
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

    void setTitle(const std::string &inTitle);
    void setContent(const std::string &inContent);

    bool getIsFavorite() const;
    void setIsFavorite(bool inIsFavorite);

    bool getIsLocked() const;
    void setIsLocked(bool inIsLocked);

    Collection *getCollection() const;
    void setCollection(Collection* inCollection);
};

#endif //LAB_DI_PROGRAMMAZIONE_NOTE_H
