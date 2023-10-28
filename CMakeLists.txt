cmake_minimum_required(VERSION 3.26)
project(Design_Model)

set(CMAKE_CXX_STANDARD 14)

add_executable(Design_Model main.cpp
        instance_model.cpp
        instance_model.h
        prototype_model.cpp
        prototype_model.h
        factory_model.cpp
        factory_model.h
        proxy_model.cpp
        proxy_model.h
)
