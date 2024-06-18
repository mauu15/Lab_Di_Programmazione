add_library(Note Note.cpp NoteManager.cpp)

add_executable(Lab_Di_Programmazione main.cpp
        NoteManager.cpp
        NoteManager.h)
target_link_libraries(Lab_Di_Programmazione Note)
