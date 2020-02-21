cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Tarea_Extraclase_1 VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Client Client/Client.cpp)
add_executable(Server Server/Server.cpp)