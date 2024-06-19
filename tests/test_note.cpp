#include "gtest/gtest.h"
#include "../src/Note.h"

// Test costruttore Note
TEST(NoteTest, Constructor) {
    Note note("Titolo", "Contenuto");
    EXPECT_EQ(note.getTitle(), "Titolo");
    EXPECT_EQ(note.getContent(), "Contenuto");
    EXPECT_FALSE(note.getIsFavorite());
    EXPECT_FALSE(note.getIsLocked());
}

// Test modifica del titolo
TEST(NoteTest, SetTitle) {
    Note note("Titolo", "Contenuto");
    note.setTitle("Nuovo Titolo");
    EXPECT_EQ(note.getTitle(), "Nuovo Titolo");
}

// Test modifica del contenuto
TEST(NoteTest, SetContent) {
    Note note("Titolo", "Contenuto");
    note.setContent("Nuovo Contenuto");
    EXPECT_EQ(note.getContent(), "Nuovo Contenuto");
}

// Test preferiti
TEST(NoteTest, SetIsFavorite) {
    Note note("Titolo", "Contenuto");
    note.setIsFavorite(true);
    EXPECT_TRUE(note.getIsFavorite());
}

// Test blocco
TEST(NoteTest, SetIsLocked) {
    Note note("Titolo", "Contenuto");
    note.setIsLocked(true);
    EXPECT_TRUE(note.getIsLocked());
}


// Funzione per eseguire tutti i test
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
