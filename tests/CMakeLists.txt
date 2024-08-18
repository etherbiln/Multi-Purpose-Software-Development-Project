cmake_minimum_required(VERSION 3.10)

# Proje adý ve sürümü
project(MyProject VERSION 1.0)

# C++ standardýný belirleyin
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include dizinlerini belirtin
include_directories(${PROJECT_SOURCE_DIR}/include)

# Kaynak dosyalarýný tanýmlayýn
set(SOURCES
    src/main.cpp
    src/person.cpp
    src/student.cpp
    src/student_manager.cpp
)

# Test dosyalarýný tanýmlayýn
set(TEST_SOURCES
    tests/test_student.cpp
)

# Hedef executable dosyayý oluþturun
add_executable(MyProject ${SOURCES})

# Google Test ve diðer kütüphaneleri baðlayýn
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Testleri ekleyin
add_executable(runTests ${TEST_SOURCES})
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

# Testleri derleme hedefine ekleyin
add_dependencies(runTests MyProject)

# Varsayýlan hedefler
add_custom_target(tests COMMAND runTests)
