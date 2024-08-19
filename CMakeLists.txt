cmake_minimum_required(VERSION 3.10)

# Proje adı ve sürümü
project(myCpp VERSION 1.0)

# C++ standardını belirleyin
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include dizinlerini belirtin
include_directories(${PROJECT_SOURCE_DIR}/include)

# Kaynak dosyalarını tanımlayın
set(SOURCES
    src/main.cpp
    src/person.cpp
    src/student.cpp
    src/student_manager.cpp
)

# Hedef executable dosyayı oluşturun
add_executable(myCpp ${SOURCES})

# Google Test ve diğer kütüphaneleri bağlayın
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
