#include <gtest/gtest.h>
#include "../src/NoteManager.h"
#include "../src/NoteCountObserver.h"

TEST(NoteManagerTest, AddNote) {
    NoteManager manager;
    Note note("Titolo", "Contenuto");
    manager.addNote(note);

    ASSERT_EQ(manager.getAllNotes().size(), 1); // Verifica che la nota sia stata aggiunta correttamente.
    EXPECT_EQ(manager.getAllNotes()[0].getTitle(), "Titolo"); // Verifica che il titolo della nota sia corretto.
    EXPECT_EQ(manager.getAllNotes()[0].getContent(), "Contenuto"); // Verifica che il contenuto della nota sia corretto.
}

TEST(NoteManagerTest, DeleteLockedNote) {
    NoteManager manager;
    Note note1("Titolo1", "Contenuto1");
    manager.addNote(note1);
    manager.setLocked("Titolo1", true);

    bool result = manager.deleteNoteByTitle("Titolo1");
    EXPECT_FALSE(result); // Verifica che la nota non sia stata eliminata.

    Note* foundNote = manager.findNoteByTitle("Titolo1");
    EXPECT_NE(foundNote, nullptr); // Verifica che la nota esista ancora.
}

TEST(NoteManagerTest, FindNoteByTitle) {
    NoteManager manager;
    Note note1("Titolo1", "Contenuto1");
    Note note2("Titolo2", "Contenuto2");
    manager.addNote(note1);
    manager.addNote(note2);

    Note* foundNote = manager.findNoteByTitle("Titolo1");
    ASSERT_NE(foundNote, nullptr); // Verifica che la nota sia stata trovata.
    EXPECT_EQ(foundNote->getTitle(), "Titolo1"); // Verifica che il titolo della nota sia corretto.
    EXPECT_EQ(foundNote->getContent(), "Contenuto1"); // Verifica che il contenuto della nota sia corretto.
}

TEST(NoteManagerTest, SearchNotesByContent) {
    NoteManager manager;
    Note note1("Titolo1", "Questo è il contenuto della prima nota");
    Note note2("Titolo2", "Questo è un altro contenuto");
    manager.addNote(note1);
    manager.addNote(note2);

    auto results = manager.searchNotesByContent("contenuto");
    ASSERT_EQ(results.size(), 2); // Verifica che siano state trovate due note.
}

TEST(NoteManagerTest, AddFavoriteNote) {
    NoteManager manager;
    Note note1("Test1", "Content1");
    Note note2("Test2", "Content2");

    manager.addNote(note1);
    manager.addNote(note2);

    manager.setFavorite("Test1", true);
    auto favorites = manager.getFavoriteNotes();

    ASSERT_EQ(favorites.size(), 1); // Verifica che sia stata aggiunta una nota ai preferiti.
    EXPECT_EQ(favorites[0].getTitle(), "Test1"); // Verifica che il titolo della nota sia corretto.
}

TEST(NoteManagerTest, LockNote) {
    NoteManager manager;
    Note note1("Test1", "Content1");

    manager.addNote(note1);
    manager.setLocked("Test1", true);

    manager.deleteNoteByTitle("Test1");
    auto notes = manager.getAllNotes();

    ASSERT_EQ(notes.size(), 1); // Verifica che la nota non sia stata eliminata.

    manager.setLocked("Test1", false);
    manager.deleteNoteByTitle("Test1");
    notes = manager.getAllNotes();

    ASSERT_EQ(notes.size(), 0); // Verifica che la nota sia stata eliminata.
}