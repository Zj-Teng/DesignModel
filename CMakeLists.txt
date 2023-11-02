cmake_minimum_required(VERSION 3.26)
project(Design_Model)

set(CMAKE_CXX_STANDARD 14)

# Introduce libcurl
find_package(CURL CONFIG REQUIRED)

add_executable(Design_Model main.cpp
        instance_model.cpp
        instance_model.h
        prototype_model.cpp
        prototype_model.h
        factory_model.cpp
        factory_model.h
        proxy_model.cpp
        proxy_model.h
        decorator_model.cpp
        decorator_model.h
        observer_model.cpp
        observer_model.h
        iterator_model.cpp
        iterator_model.h
        builder_model.cpp
        builder_model.h
)

target_link_libraries(Design_Model PRIVATE CURL::libcurl)
