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

    ASSERT_EQ(collection->getNotes().size(), 1);
    EXPECT_EQ(collection->getNotes()[0]->getTitle(), "Meeting");
}

TEST(CollectionTest, FindCollectionByName) {
    NoteManager manager;
    manager.addCollection("Personale");

    Collection* collection = manager.findCollectionByName("Personale");
    ASSERT_NE(collection, nullptr);
    EXPECT_EQ(collection->getName(), "Personale");

    Collection* nonExistentCollection = manager.findCollectionByName("NonExistent");
    EXPECT_EQ(nonExistentCollection, nullptr);
}

TEST(CollectionTest, AddMultipleNotes) {
    NoteManager manager;
    manager.addCollection("Projects");

    NoteCountObserver observer;
    Collection* collection = manager.findCollectionByName("Projects");
    ASSERT_NE(collection, nullptr);
    collection->addObserver(&observer);

    Note note1("Project A", "Dettagli sul progetto A");
    Note note2("Project B", "Dettagli sul progetto B");
    manager.addNote(note1);
    manager.addNote(note2);

    collection->addNote(&note1);
    collection->addNote(&note2);

    ASSERT_EQ(collection->getNotes().size(), 2);
    EXPECT_EQ(collection->getNotes()[0]->getTitle(), "Project A");
    EXPECT_EQ(collection->getNotes()[1]->getTitle(), "Project B");
}

TEST(CollectionTest, AddNoteToMultipleCollections) {
    NoteManager manager;
    manager.addCollection("Work");
    manager.addCollection("Personal");

    NoteCountObserver observer;
    Collection* workCollection = manager.findCollectionByName("Work");
    Collection* personalCollection = manager.findCollectionByName("Personal");

    ASSERT_NE(workCollection, nullptr);
    ASSERT_NE(personalCollection, nullptr);

    workCollection->addObserver(&observer);
    personalCollection->addObserver(&observer);

    Note note1("Task", "Completa il report");
    manager.addNote(note1);

    workCollection->addNote(&note1);
    personalCollection->addNote(&note1);

    ASSERT_EQ(workCollection->getNotes().size(), 1);
    ASSERT_EQ(personalCollection->getNotes().size(), 1);
    EXPECT_EQ(workCollection->getNotes()[0]->getTitle(), "Task");
    EXPECT_EQ(personalCollection->getNotes()[0]->getTitle(), "Task");
}