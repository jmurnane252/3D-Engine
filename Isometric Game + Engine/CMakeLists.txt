cmake_minimum_required(VERSION 3.10)
project(MyOpenGLGame)

set(SRC
    src/main.c
    src/core/engine.c
    src/core/window.c
)

file(GLOB CORE_SRC src/core/*.c)
add_executable(MyOpenGLGame src/main.c ${CORE_SRC} "D:/C Projects/Isometric Game + Engine/external/glad/src/glad.c")

target_include_directories(MyOpenGLGame PRIVATE 
    "D:/C Projects/Isometric Game + Engine/external/SDL3/SDL3-3.2.28/x86_64-w64-mingw32/include"
    "D:/C Projects/Isometric Game + Engine/external/glad/include"
    "D:/C Projects/Isometric Game + Engine/src"
    "D:/C Projects/Isometric Game + Engine/external/stb"
)

target_link_directories(MyOpenGLGame PRIVATE 
    "D:/C Projects/Isometric Game + Engine/external/SDL3/SDL3-3.2.28/x86_64-w64-mingw32/lib"
)

target_link_libraries(MyOpenGLGame PRIVATE 
    SDL3 
    opengl32
)

add_custom_command(TARGET MyOpenGLGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "D:/C Projects/Isometric Game + Engine/external/SDL3/SDL3-3.2.28/x86_64-w64-mingw32/bin/SDL3.dll"
    $<TARGET_FILE_DIR:MyOpenGLGame>
)
