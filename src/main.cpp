#include <iostream>
#include "Note.h"
#include "NoteManager.h"

void printMenu() {
    std::cout << "=== Gestore di Note ===" << std::endl;
    std::cout << "1. Aggiungi nota" << std::endl;
    std::cout << "2. Cerca nota per titolo" << std::endl;
    std::cout << "3. Elimina nota per titolo" << std::endl;
    std::cout << "4. Mostra tutte le note" << std::endl;
    std::cout << "5. Aggiungi/Rimuovi preferiti" << std::endl;
    std::cout << "6. Mostra note preferite" << std::endl;
    std::cout << "7. Blocca/Sblocca nota" << std::endl;
    std::cout << "8. Esci" << std::endl;
    std::cout << "=======================" << std::endl;
    std::cout << "Scelta: ";
}

int main() {
    NoteManager manager;

    int choice;
    do {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string title, content;
                std::cout << "Inserisci il titolo della nota: ";
                std::cin.ignore(); // per evitare problemi con std::getline dopo std::cin
                std::getline(std::cin, title);
                std::cout << "Inserisci il contenuto della nota: ";
                std::getline(std::cin, content);

                Note note(title, content);
                manager.addNote(note);
                std::cout << "Nota aggiunta con successo." << std::endl;
                break;
            }
            case 2: {
                std::string searchTitle;
                std::cout << "Inserisci il titolo da cercare: ";
                std::cin.ignore(); // per evitare problemi con std::getline dopo std::cin
                std::getline(std::cin, searchTitle);

                Note* foundNote = manager.findNoteByTitle(searchTitle);
                if (foundNote) {
                    std::cout << "Nota trovata:" << std::endl;
                    std::cout << "Titolo: " << foundNote->getTitle() << std::endl;
                    std::cout << "Contenuto: " << foundNote->getContent() << std::endl;
                    std::cout << "Preferita: " << (foundNote->getIsFavorite() ? "Sì" : "No") << std::endl;
                    std::cout << "Bloccata: " << (foundNote->getIsLocked() ? "Sì" : "No") << std::endl;
                } else {
                    std::cout << "Nota non trovata." << std::endl;
                }
                break;
            }
            case 3: {
                std::string deleteTitle;
                std::cout << "Inserisci il titolo da eliminare: ";
                std::cin.ignore(); // per evitare problemi con std::getline dopo std::cin
                std::getline(std::cin, deleteTitle);

                bool result = manager.deleteNoteByTitle(deleteTitle);
                if (result) {
                    std::cout << "Nota eliminata con successo." << std::endl;
                } else {
                    std::cout << "Nota non trovata o è bloccata e non può essere eliminata." << std::endl;
                }
                break;
            }
            case 4: {
                auto notes = manager.getAllNotes();
                if (notes.empty()) {
                    std::cout << "Nessuna nota presente." << std::endl;
                } else {
                    std::cout << "Elenco delle note:" << std::endl;
                    for (const auto& note : notes) {
                        std::cout << "Titolo: " << note.getTitle() << ", Contenuto: " << note.getContent()
                                  << ", Preferita: " << (note.getIsFavorite() ? "Sì" : "No")
                                  << ", Bloccata: " << (note.getIsLocked() ? "Sì" : "No") << std::endl;
                    }
                }
                break;
            }
            case 5: {
                std::string title;
                std::cout << "Inserisci il titolo della nota da aggiungere/rimuovere dai preferiti: ";
                std::cin.ignore();
                std::getline(std::cin, title);

                Note* note = manager.findNoteByTitle(title);
                if (note) {
                    bool newFavoriteStatus = !note->getIsFavorite();
                    manager.setFavorite(title, newFavoriteStatus);
                    std::cout << "Lo stato di preferito della nota è stato aggiornato a "
                              << (newFavoriteStatus ? "Sì" : "No") << "." << std::endl;
                } else {
                    std::cout << "Nota non trovata." << std::endl;
                }
                break;
            }
            case 6: {
                auto favorites = manager.getFavoriteNotes();
                if (favorites.empty()) {
                    std::cout << "Nessuna nota preferita presente." << std::endl;
                } else {
                    std::cout << "Elenco delle note preferite:" << std::endl;
                    for (const auto& note : favorites) {
                        std::cout << "Titolo: " << note.getTitle() << ", Contenuto: " << note.getContent() << std::endl;
                    }
                }
                break;
            }
            case 7: {
                std::string title;
                std::cout << "Inserisci il titolo della nota da bloccare/sbloccare: ";
                std::cin.ignore();
                std::getline(std::cin, title);

                Note* note = manager.findNoteByTitle(title);
                if (note) {
                    bool newLockStatus = !note->getIsLocked();
                    manager.setLocked(title, newLockStatus);
                    std::cout << "La nota è stata " << (newLockStatus ? "bloccata" : "sbloccata") << "." << std::endl;
                } else {
                    std::cout << "Nota non trovata." << std::endl;
                }
                break;
            }
            case 8:
                std::cout << "Uscita dal programma..." << std::endl;
                break;
            default:
                std::cout << "Scelta non valida. Riprova." << std::endl;
                break;
        }
    } while (choice != 8);

    return 0;
}
