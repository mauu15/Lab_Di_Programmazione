#include <iostream>
#include "Note.h"

int main() {
    Note myNote;
    myNote.setTitle("Prima Nota");
    myNote.setContent("Prova testo della prima nota");

    std::cout << "Titolo: " << myNote.getTitle() << std::endl;
    std::cout << "Contenuto: " << myNote.getContent() << std::endl;

    return 0;
}
