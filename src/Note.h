
#ifndef LAB_DI_PROGRAMMAZIONE_NOTE_H
#define LAB_DI_PROGRAMMAZIONE_NOTE_H

#include <string>

class Note {
private:
    std::string title;
    std::string content;

public:
    Note();
    Note(const std::string &title, const std::string &content);

    std::string getTitle() const;
    std::string getContent() const;

    void setTitle(const std::string &title);
    void setContent(const std::string &content);
};

#endif //LAB_DI_PROGRAMMAZIONE_NOTE_H
