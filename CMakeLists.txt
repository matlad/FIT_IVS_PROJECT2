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

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
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

################################################################################
# Testy
################################################################################

# Testy lexikálního analyzátoru
###############################

add_executable(LexicalATest
        src/tests/LexicalAnalyzerTest.cpp
        src/tests/TestContants.h
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
        src/tests/TestContants.h
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
        src/tests/TestContants.h
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
        src/tests/TestContants.h
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

include(CPack)
set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VENDOR "team22")
set(CPACK_PACKAGE_CONTACT "xmatla00@stud.fit.vutbr.cz")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Jednoduchá kalkulačka")
set(CPACK_PACKAGE_VERSION "1.0.0")

# Windows
###################
IF (WIN32)
    set(CPACK_GENERATOR NSIS)
    install(DIRECTORY deployment/ DESTINATION .)
# DEB based systems
####################
else()
    set(CPACK_GENERATOR DEB)

    # chceme instalovat všechy soubory
    # z "deployment", tentokrát do "/opt/InstallerTest"
    # cı́lového systému (absolutnı́ cesta)
    install(DIRECTORY deployment/ DESTINATION /opt/${PROJECT_NAME})

    # Navı́c je třeba nainstalovat předem vytvořeného
    # zástupce do "/usr/share/applications"
    install(FILES linux/${PROJECT_NAME}.desktop DESTINATION share/applications)

#    # a přı́padně spustit skript po dokončenı́ instalace
#    # pro nastavenı́ práv souborů atd.
#    set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA "${CMAKE_CURRENT_SOURCE_DIR}/linux/postinst;")
endif()
