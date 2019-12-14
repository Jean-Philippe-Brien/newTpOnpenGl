cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 14)
set(
        PROJECT_NAME_VALUE
        RustBuckets)

project(${PROJECT_NAME_VALUE})

file(
        GLOB_RECURSE
        source_files
        src/*
)

#si on utilise un repertoire assets pour image fichier ou autre
#il faut decomenter le code qui suit
file(
        COPY
        assets
        DESTINATION
        ${CMAKE_BINARY_DIR}
)

add_executable(
        ${PROJECT_NAME_VALUE}
        ${source_files}
        src/Utils/Pathfinding/Node.cpp src/Utils/Pathfinding/Node.h)


if (WIN32)
    TARGET_LINK_LIBRARIES(
            ${PROJECT_NAME_VALUE}
            -lmingw32
            -lSDL2main
            -lSDL2
            -lSDL2_image
            -lopengl32
            -lglu32
            -lSDL2_ttf
    )
endif ()

if (UNIX)
    TARGET_LINK_LIBRARIES(
            ${PROJECT_NAME_VALUE}
            -lSDL2main
            -lSDL2
            -lSDL2_image
            -lGL
            -lGLU
            -lSDL2_ttf
    )
endif ()