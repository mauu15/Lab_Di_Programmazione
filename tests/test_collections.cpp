// test_collections.cpp
#include "gtest/gtest.h"
#include "../src/NoteManager.h"

TEST(CollectionTest, AddNote) {
    NoteManager manager;
    manager.addCollection("Work");

    Note note1("Meeting", "Discuss project status");
    manager.addNote(note1);

    Collection* collection = manager.findCollectionByName("Work");
    ASSERT_NE(collection, nullptr);

    collection->addNote(&note1);
    ASSERT_EQ(collection->getNotes().size(), 1);
    EXPECT_EQ(collection->getNotes()[0]->getTitle(), "Meeting");
}

TEST(CollectionTest, FindCollectionByName) {
    NoteManager manager;
    manager.addCollection("Personal");

    Collection* collection = manager.findCollectionByName("Personal");
    ASSERT_NE(collection, nullptr);
    EXPECT_EQ(collection->getName(), "Personal");

    Collection* nonExistentCollection = manager.findCollectionByName("NonExistent");
    EXPECT_EQ(nonExistentCollection, nullptr);
}

TEST(CollectionTest, AddMultipleNotes) {
    NoteManager manager;
    manager.addCollection("Projects");

    Note note1("Project A", "Details about project A");
    Note note2("Project B", "Details about project B");
    manager.addNote(note1);
    manager.addNote(note2);

    Collection* collection = manager.findCollectionByName("Projects");
    ASSERT_NE(collection, nullptr);

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

    Note note1("Task", "Complete the report");
    manager.addNote(note1);

    Collection* workCollection = manager.findCollectionByName("Work");
    Collection* personalCollection = manager.findCollectionByName("Personal");

    ASSERT_NE(workCollection, nullptr);
    ASSERT_NE(personalCollection, nullptr);

    workCollection->addNote(&note1);
    personalCollection->addNote(&note1);

    ASSERT_EQ(workCollection->getNotes().size(), 1);
    ASSERT_EQ(personalCollection->getNotes().size(), 1);
    EXPECT_EQ(workCollection->getNotes()[0]->getTitle(), "Task");
    EXPECT_EQ(personalCollection->getNotes()[0]->getTitle(), "Task");
}
