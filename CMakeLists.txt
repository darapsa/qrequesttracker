cmake_minimum_required(VERSION 3.5)
project(qrtclient)
set(CMAKE_AUTOMOC ON)
find_package(Qt5Core)
set(HDRS
	${PROJECT_NAME}/user.hxx
	${PROJECT_NAME}/ticket.hxx
	${PROJECT_NAME}/tickethistory.hxx
	)
set(SRCS
	${PROJECT_NAME}.hxx
	${HDRS}
	user.cxx
	ticket.cxx
	tickethistory.cxx
	client.cxx
	)
if (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
	include_directories(/usr/local/include)
	link_directories(/usr/local/lib)
endif()
if (EMSCRIPTEN OR IOS)
	add_library(${PROJECT_NAME} STATIC ${SRCS})
else()
	add_library(${PROJECT_NAME} SHARED ${SRCS})
endif()
target_link_libraries(${PROJECT_NAME}
	Qt5::Core
	rtclient
	)
include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${PROJECT_NAME}.hxx DESTINATION include)
install(FILES ${HDRS} DESTINATION include/${PROJECT_NAME})
