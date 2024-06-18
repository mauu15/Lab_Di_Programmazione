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
TEST(NoteManagerTest, DeleteNoteByTitle) {
    NoteManager manager;
    Note note1("Titolo1", "Contenuto1");
    Note note2("Titolo2", "Contenuto2");
    manager.addNote(note1);
    manager.addNote(note2);

    manager.deleteNoteByTitle("Titolo1");
    ASSERT_EQ(manager.getAllNotes().size(), 1);
    EXPECT_EQ(manager.getAllNotes()[0].getTitle(), "Titolo2");
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
