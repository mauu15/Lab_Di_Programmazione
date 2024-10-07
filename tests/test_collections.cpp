#include "gtest/gtest.h"
#include "../src/NoteManager.h"
#include "../src/NoteCountObserver.h"

TEST(CollectionTest, AddNote) {
    NoteManager manager;
    manager.addCollection("Work");

    NoteCountObserver observer;
    Collection* collection = manager.findCollectionByName("Work");
    ASSERT_NE(collection, nullptr);
    collection->addObserver(&observer);

    Note note1("Meeting", "Discussione sul progetto");
    manager.addNote(note1);
    collection->addNote(&note1);

    ASSERT_EQ(collection->getNotes().size(), 1); // Verifica che la collezione contenga una nota.
    EXPECT_EQ(collection->getNotes()[0]->getTitle(), "Meeting"); // Verifica che il titolo della nota sia corretto.
}

TEST(CollectionTest, FindCollectionByName) {
    NoteManager manager;
    manager.addCollection("Personale");

    Collection* collection = manager.findCollectionByName("Personale");
    ASSERT_NE(collection, nullptr); // Verifica che la collezione trovata non sia nulla. Serve per assicurarsi che la collezione esista. Se la collezione non esiste, il test fallisce immediatamente.
    EXPECT_EQ(collection->getName(), "Personale"); // Verifica che il nome della collezione trovata sia corretto.

    Collection* nonExistentCollection = manager.findCollectionByName("NonExistent");
    EXPECT_EQ(nonExistentCollection, nullptr); // Verifica che la collezione non esista. Serve per assicurarsi che la collezione non esista. Se la collezione esiste, il test fallisce immediatamente.
}

TEST(CollectionTest, AddMultipleNotes) {
    NoteManager manager;
    manager.addCollection("Projects");

    NoteCountObserver observer;
    Collection* collection = manager.findCollectionByName("Projects");
    ASSERT_NE(collection, nullptr); // Verifica che la collezione esista.
    collection->addObserver(&observer);

    Note note1("Project A", "Dettagli sul progetto A");
    Note note2("Project B", "Dettagli sul progetto B");
    manager.addNote(note1);
    manager.addNote(note2);

    collection->addNote(&note1);
    collection->addNote(&note2);

    ASSERT_EQ(collection->getNotes().size(), 2); // Verifica che la collezione contenga due note.
    EXPECT_EQ(collection->getNotes()[0]->getTitle(), "Project A"); // Verifica che il titolo della prima nota sia corretto.
    EXPECT_EQ(collection->getNotes()[1]->getTitle(), "Project B"); // Verifica che il titolo della seconda nota sia corretto.
}

TEST(CollectionTest, AddNoteToMultipleCollections) {
    NoteManager manager;
    manager.addCollection("Work");
    manager.addCollection("Personal");

    NoteCountObserver observer;
    Collection* workCollection = manager.findCollectionByName("Work");
    Collection* personalCollection = manager.findCollectionByName("Personal");

    ASSERT_NE(workCollection, nullptr); // Verifica che la collezione di lavoro esista.
    ASSERT_NE(personalCollection, nullptr); // Verifica che la collezione personale esista.

    workCollection->addObserver(&observer);
    personalCollection->addObserver(&observer);

    Note note1("Task", "Completa il report");
    manager.addNote(note1);

    workCollection->addNote(&note1);
    personalCollection->addNote(&note1);

    ASSERT_EQ(workCollection->getNotes().size(), 1); // Verifica che la collezione di lavoro contenga una nota.
    ASSERT_EQ(personalCollection->getNotes().size(), 1); // Verifica che la collezione personale contenga una nota.
    EXPECT_EQ(workCollection->getNotes()[0]->getTitle(), "Task"); // Verifica che il titolo della nota nella collezione di lavoro sia corretto.
    EXPECT_EQ(personalCollection->getNotes()[0]->getTitle(), "Task"); // Verifica che il titolo della nota nella collezione personale sia corretto.
}