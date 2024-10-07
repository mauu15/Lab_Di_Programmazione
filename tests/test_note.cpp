#include "gtest/gtest.h"
#include "../src/Note.h"

TEST(NoteTest, Constructor) {
    Note note("Titolo", "Contenuto");
    EXPECT_EQ(note.getTitle(), "Titolo"); // Verifica che il titolo della nota sia corretto.
    EXPECT_EQ(note.getContent(), "Contenuto"); // Verifica che il contenuto della nota sia corretto.
    EXPECT_FALSE(note.getIsFavorite()); // Verifica che la nota non sia preferita.
    EXPECT_FALSE(note.getIsLocked()); // Verifica che la nota non sia bloccata.
}

TEST(NoteTest, SetTitle) {
    Note note("Titolo", "Contenuto");
    note.setTitle("Nuovo Titolo");
    EXPECT_EQ(note.getTitle(), "Nuovo Titolo"); // Verifica che il titolo della nota sia stato modificato correttamente.
}

TEST(NoteTest, SetContent) {
    Note note("Titolo", "Contenuto");
    note.setContent("Nuovo Contenuto");
    EXPECT_EQ(note.getContent(), "Nuovo Contenuto"); // Verifica che il contenuto della nota sia stato modificato correttamente.
}

TEST(NoteTest, SetIsFavorite) {
    Note note("Titolo", "Contenuto");
    note.setIsFavorite(true);
    EXPECT_TRUE(note.getIsFavorite()); // Verifica che la nota sia stata impostata come preferita.
}

TEST(NoteTest, SetIsLocked) {
    Note note("Titolo", "Contenuto");
    note.setIsLocked(true);
    EXPECT_TRUE(note.getIsLocked()); // Verifica che la nota sia stata bloccata.
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}