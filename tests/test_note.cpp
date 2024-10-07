#include "gtest/gtest.h"
#include "../src/Note.h"

TEST(NoteTest, Constructor) {
    Note note("Titolo", "Contenuto");
    EXPECT_EQ(note.getTitle(), "Titolo");
    EXPECT_EQ(note.getContent(), "Contenuto");
    EXPECT_FALSE(note.getIsFavorite());
    EXPECT_FALSE(note.getIsLocked());
}

TEST(NoteTest, SetTitle) {
    Note note("Titolo", "Contenuto");
    note.setTitle("Nuovo Titolo");
    EXPECT_EQ(note.getTitle(), "Nuovo Titolo");
}

TEST(NoteTest, SetContent) {
    Note note("Titolo", "Contenuto");
    note.setContent("Nuovo Contenuto");
    EXPECT_EQ(note.getContent(), "Nuovo Contenuto");
}

TEST(NoteTest, SetIsFavorite) {
    Note note("Titolo", "Contenuto");
    note.setIsFavorite(true);
    EXPECT_TRUE(note.getIsFavorite());
}

TEST(NoteTest, SetIsLocked) {
    Note note("Titolo", "Contenuto");
    note.setIsLocked(true);
    EXPECT_TRUE(note.getIsLocked());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}