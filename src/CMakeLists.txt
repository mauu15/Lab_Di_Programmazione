add_library(Note Note.cpp NoteManager.cpp Collection.cpp)

add_executable(Lab_Di_Programmazione main.cpp
        NoteManager.cpp
        NoteManager.h
        Collection.cpp
        Collection.h)
target_link_libraries(Lab_Di_Programmazione Note)
