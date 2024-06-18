#include <gtest/gtest.h>
#include "../src/Note.h"

// Test default constructor
TEST(NoteTest, DefaultConstructor) {
    Note note;
    EXPECT_EQ(note.getTitle(), "");
    EXPECT_EQ(note.getContent(), "");
}

// Test parameterized constructor
TEST(NoteTest, ParameterizedConstructor) {
    Note note("Titolo", "Contenuto");
    EXPECT_EQ(note.getTitle(), "Titolo");
    EXPECT_EQ(note.getContent(), "Contenuto");
}

// Test setTitle
TEST(NoteTest, SetTitle) {
    Note note;
    note.setTitle("Nuovo Titolo");
    EXPECT_EQ(note.getTitle(), "Nuovo Titolo");
}

// Test setContent
TEST(NoteTest, SetContent) {
    Note note;
    note.setContent("Nuovo Contenuto");
    EXPECT_EQ(note.getContent(), "Nuovo Contenuto");
}

// Funzione per eseguire tutti i test
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
