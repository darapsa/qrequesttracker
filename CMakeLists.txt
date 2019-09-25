cmake_minimum_required(VERSION 3.0.0)

project(qrtclient VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt5Core)

add_library(${PROJECT_NAME} STATIC
	user.cxx
	ticket.cxx
	client.cxx)

target_link_libraries(${PROJECT_NAME} Qt5::Core)

include_directories(librtclient)
