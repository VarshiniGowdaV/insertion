cmake_minimum_required(VERSION 3.16)

project(Insertionlinkedlist LANGUAGES C)

add_executable(Insertionlinkedlist main.c
)

include(GNUInstallDirs)
install(TARGETS Insertionlinkedlist
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
