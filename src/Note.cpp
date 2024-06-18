#include "Note.h"

Note::Note() : title(""), content("") {}

Note::Note(const std::string &title, const std::string &content) : title(title), content(content) {}

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
#include "Note.h"
