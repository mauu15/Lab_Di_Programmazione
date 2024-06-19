#include <gtest/gtest.h>
#include "../src/NoteManager.h"

// Test addNote
TEST(NoteManagerTest, AddNote) {
    NoteManager manager;
    Note note("Titolo", "Contenuto");
    manager.addNote(note);

    ASSERT_EQ(manager.getAllNotes().size(), 1);
    EXPECT_EQ(manager.getAllNotes()[0].getTitle(), "Titolo");
    EXPECT_EQ(manager.getAllNotes()[0].getContent(), "Contenuto");
}

// Test deleteNoteByTitle
TEST(NoteManagerTest, DeleteLockedNote) {
    NoteManager manager;
    Note note1("Titolo1", "Contenuto1");
    manager.addNote(note1);
    manager.setLocked("Titolo1", true);

    // Tentare di eliminare la nota bloccata
    bool result = manager.deleteNoteByTitle("Titolo1");
    EXPECT_FALSE(result);

    // Verifica che la nota sia ancora presente
    Note* foundNote = manager.findNoteByTitle("Titolo1");
    EXPECT_NE(foundNote, nullptr);
}

// Test findNoteByTitle
TEST(NoteManagerTest, FindNoteByTitle) {
    NoteManager manager;
    Note note1("Titolo1", "Contenuto1");
    Note note2("Titolo2", "Contenuto2");
    manager.addNote(note1);
    manager.addNote(note2);

    Note* foundNote = manager.findNoteByTitle("Titolo1");
    ASSERT_NE(foundNote, nullptr);
    EXPECT_EQ(foundNote->getTitle(), "Titolo1");
    EXPECT_EQ(foundNote->getContent(), "Contenuto1");
}

// Test searchNotesByContent
TEST(NoteManagerTest, SearchNotesByContent) {
    NoteManager manager;
    Note note1("Titolo1", "Questo è il contenuto della prima nota");
    Note note2("Titolo2", "Questo è un altro contenuto");
    manager.addNote(note1);
    manager.addNote(note2);

    auto results = manager.searchNotesByContent("contenuto");
    ASSERT_EQ(results.size(), 2); // Verifica che ci siano due risultati
}

//Test addFavoriteNotes
TEST(NoteManagerTest, AddFavoriteNote) {
    NoteManager manager;
    Note note1("Test1", "Content1");
    Note note2("Test2", "Content2");

    manager.addNote(note1);
    manager.addNote(note2);

    manager.setFavorite("Test1", true);
    auto favorites = manager.getFavoriteNotes();

    ASSERT_EQ(favorites.size(), 1);
    EXPECT_EQ(favorites[0].getTitle(), "Test1");
}

TEST(NoteManagerTest, LockNote) {
    NoteManager manager;
    Note note1("Test1", "Content1");

    manager.addNote(note1);
    manager.setLocked("Test1", true);

    manager.deleteNoteByTitle("Test1");
    auto notes = manager.getAllNotes();

    ASSERT_EQ(notes.size(), 1); // Nota non eliminata perché bloccata

    manager.setLocked("Test1", false);
    manager.deleteNoteByTitle("Test1");
    notes = manager.getAllNotes();

    ASSERT_EQ(notes.size(), 0); // Nota eliminata perché sbloccata
}
