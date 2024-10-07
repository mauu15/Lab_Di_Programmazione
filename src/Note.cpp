#include "Note.h"

#include <utility>

Note::Note(std::string title, std::string content)
        : title(std::move(title)), content(std::move(content)), isFavorite(false), isLocked(false), collection(nullptr) {

}


std::string Note::getTitle() const {
    return title;
}

std::string Note::getContent() const {
    return content;
}

void Note::setTitle(const std::string &inTitle) {
    this->title = inTitle;
}

void Note::setContent(const std::string &inContent) {
    this->content = inContent;
}


bool Note::getIsFavorite() const {
    return isFavorite;
}

void Note::setIsFavorite(bool inIsFavorite) {
    this->isFavorite = inIsFavorite;
}

bool Note::getIsLocked() const {
    return isLocked;
}

void Note::setIsLocked(bool inIsLocked) {
    this->isLocked = inIsLocked;
}

Collection* Note::getCollection() const {
    return collection;
}

void Note::setCollection(Collection* inCollection) {
    this->collection = inCollection;
}


