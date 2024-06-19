#include "Note.h"

#include <utility>

Note::Note(std::string  title, std::string  content)
        : title(std::move(title)), content(std::move(content)), isFavorite(false), isLocked(false) {}


std::string Note::getTitle() const {
    return title;
}

std::string Note::getContent() const {
    return content;
}

void Note::setTitle(const std::string &title) {
    this->title = title;
}

void Note::setContent(const std::string &content) {
    this->content = content;
}


bool Note::getIsFavorite() const {
    return isFavorite;
}

void Note::setIsFavorite(bool isFavorite) {
    this->isFavorite = isFavorite;
}

bool Note::getIsLocked() const {
    return isLocked;
}

void Note::setIsLocked(bool isLocked) {
    this->isLocked = isLocked;
}