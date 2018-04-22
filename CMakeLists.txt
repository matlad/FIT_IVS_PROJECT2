cmake_minimum_required(VERSION 3.10)
project(Calc)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
include_directories(src/math)
include_directories(src/tests)
include_directories()

add_library(math STATIC src/math/Number.cpp src/math/Number.h src/math/UndefinedException.h)

find_package(Qt5 COMPONENTS Widgets Qml Quick REQUIRED)
include_directories(${Qt5Widgets_INCLUDE_DIRS} ${QtQml_INCLUDE_DIRS})

set(CMAKE_AUTOMOC ON)
qt5_add_resources(QT_RESOURCES src/qml.qrc)


add_executable(${PROJECT_NAME}
        src/Equation.cpp
        src/Equation.h
        src/EquationObserver.h
        src/Interpret.cpp
        src/Interpret.h
        src/InterpretException.h
        src/Lex.cpp
        src/Lex.h
        src/LexException.h
        src/LexicalAnalyzer.cpp
        src/LexicalAnalyzer.h
        src/LexicalAnalyzerException.h
        src/LexIdentificationObserver.h
        src/main.cpp
        src/ResultObserver.h
        src/SignalManager.cpp
        src/SignalManager.h
        src/resources/main.qml
        ${RESOURCES})

file(COPY src/resources/main.qml DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY src/resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})



target_link_libraries(${PROJECT_NAME} math)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Qml Qt5::Quick)

#################################################################################
## Profiling
#################################################################################
add_executable(Profiling
        src/profiling/profiling.cpp
        )
target_link_libraries(Profiling math)

#################################################################################
## Testy
#################################################################################

# Testy lexikálního analyzátoru
###############################

add_executable(LexicalATest
        src/tests/LexicalAnalyzerTest.cpp
        src/Lex.cpp
        src/Lex.h
        src/LexException.h
        src/LexicalAnalyzer.cpp
        src/LexicalAnalyzer.h
        src/LexicalAnalyzerException.h
        src/LexIdentificationObserver.h
        )
target_link_libraries(LexicalATest gtest_main)
target_link_libraries(LexicalATest math)

# Testy Interpretu
###############################

add_executable(InterpretTest
        src/tests/InterpretTests.cpp
        src/Interpret.cpp
        src/Interpret.h
        src/InterpretException.h
        src/Lex.cpp
        src/Lex.h
        src/LexException.h
        src/LexIdentificationObserver.h
        )
target_link_libraries(InterpretTest gtest_main)
target_link_libraries(InterpretTest math)

# Testy backendu
###############################

add_executable(BackendTest
        src/tests/backendTest.cpp
        src/Equation.cpp
        src/Equation.h
        src/EquationObserver.h
        src/Interpret.cpp
        src/Interpret.h
        src/InterpretException.h
        src/Lex.cpp
        src/Lex.h
        src/LexException.h
        src/LexicalAnalyzer.cpp
        src/LexicalAnalyzer.h
        src/LexicalAnalyzerException.h
        src/LexIdentificationObserver.h
      )

target_link_libraries(BackendTest gtest_main)
target_link_libraries(BackendTest math)

# Testy Numerické knihovny
###############################
add_executable(NumberTest
        src/tests/NumberTest.cpp
        )

target_link_libraries(NumberTest gtest_main)
target_link_libraries(NumberTest math)



# Gtest pto testování
###############################

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

################################################################################
# Instalace / balíček
################################################################################

set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VENDOR "team22")
set(CPACK_PACKAGE_CONTACT "xmatla00@stud.fit.vutbr.cz")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Jednoduchá kalkulacka")
set(CPACK_PACKAGE_VERSION "1.0.0-Alfa")

if(WIN32)
    set(CPACK_GENERATOR NSIS)
    install(DIRECTORY deployment/ DESTINATION .)
    set(CPACK_PACKAGE_INSTALL_DIRECTORY "${PROJECT_NAME}")
    set(CPACK_NSIS_EXTRA_INSTALL_COMMANDS "Execwait 'vcredist_x64.exe /q'")
    set(CPACK_NSIS_CREATE_ICONS_EXTRA "CreateShortCut '$DESKTOP\\\\${PROJECT_NAME}.lnk' '$INSTDIR\\\\${PROJECT_NAME}.exe'")
    set(CPACK_NSIS_DELETE_ICONS_EXTRA "Delete '$DESKTOP\\\\${PROJECT_NAME}.lnk'")
else()
    set(CPACK_GENERATOR DEB)
    install(TARGETS ${PROJECT_NAME} DESTINATION /opt/${PROJECT_NAME})
    install(DIRECTORY src/resources DESTINATION /opt/${PROJECT_NAME})
    install(FILES src/install/${PROJECT_NAME}.desktop DESTINATION share/applications)
    set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA "${CMAKE_CURRENT_SOURCE_DIR}/linux/postinst;")
endif()

include(CPack)
