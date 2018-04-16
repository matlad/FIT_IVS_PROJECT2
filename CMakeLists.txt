cmake_minimum_required(VERSION 3.9)
project(FIT_IVS_PROJECT2)

set(CMAKE_CXX_STANDARD 17)


set(REPO /media/Linux_Data/Code/repo)
include(CTest)
enable_testing()

include(${REPO}/DownloadProject/DownloadProject.cmake)
download_project(
        PROJ                googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             master
        UPDATE_DISCONNECTED 1
)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)


add_executable(MathTest
        src/tests/NumberTest.cpp
        src/math/Number.cpp
        src/math/Number.h
        src/math/UndefinedException.h
        src/tests/TestContants.h)

target_link_libraries(MathTest gtest gtest_main)

add_executable(LexAnalyserTest
        src/tests/LexicalAnalyzerTest.cpp
        src/math/Number.cpp
        src/math/Number.h
        src/math/UndefinedException.h
        src/Lex.cpp
        src/Lex.h
        src/LexicalAnalyzer.cpp
        src/LexicalAnalyzer.h
        src/LexIdentificationObserver.h
        src/LexException.h
        src/LexicalAnalyzerException.h
        src/tests/TestContants.h)

target_link_libraries(LexAnalyserTest gtest gtest_main)

add_executable(InterpretTest
        src/Interpret.cpp
        src/Interpret.h
        src/tests/InterpretTests.cpp
        src/math/Number.cpp
        src/math/Number.h
        src/math/UndefinedException.h
        src/Lex.cpp
        src/Lex.h
        src/LexicalAnalyzer.cpp
        src/LexicalAnalyzer.h
        src/LexIdentificationObserver.h
        src/LexException.h
        src/LexicalAnalyzerException.h
        src/tests/InterpretTests.cpp
        src/ResultObserver.h
        src/InterpretException.h
        src/tests/TestContants.h)
target_link_libraries(InterpretTest gtest gtest_main)

add_executable(BackendTest
        src/Interpret.cpp
        src/Interpret.h
        src/math/Number.cpp
        src/math/Number.h
        src/math/UndefinedException.h
        src/Lex.cpp
        src/Lex.h
        src/LexicalAnalyzer.cpp
        src/LexicalAnalyzer.h
        src/LexIdentificationObserver.h
        src/LexException.h
        src/LexicalAnalyzerException.h
        src/ResultObserver.h
        src/InterpretException.h
        src/Equation.cpp
        src/Equation.h
        src/tests/backendTest.cpp
        src/tests/TestContants.h)

target_link_libraries(BackendTest gtest gtest_main)

