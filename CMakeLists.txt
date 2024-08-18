# Proje için minimum CMake versiyonu
cmake_minimum_required(VERSION 3.10)

# Proje adı ve sürümü
project(MyProject VERSION 1.0)

# C++ standardını belirleyin (opsiyonel)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include dizinini derleyiciye ekleyin
include_directories(${PROJECT_SOURCE_DIR}/include)

# Projenin kaynak dosyalarını ekleyin
set(SOURCES
    src/main.cpp
    src/source.cpp
)

# Hedef executable dosyayı oluşturun
add_executable(MyProject ${SOURCES})
