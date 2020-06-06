cmake_minimum_required(VERSION 3.5)

project(qrtclient)

set(CMAKE_AUTOMOC ON)

find_package(Qt5Core)

add_library(${PROJECT_NAME} SHARED
	${PROJECT_NAME}/user.hxx
	${PROJECT_NAME}/ticket.hxx
	${PROJECT_NAME}/tickethistory.hxx
	${PROJECT_NAME}/client.hxx
	user.cxx
	ticket.cxx
	tickethistory.cxx
	client.cxx
	)

target_link_libraries(${PROJECT_NAME}
	Qt5::Core
	rtclient
	)

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES
	${PROJECT_NAME}/user.hxx
	${PROJECT_NAME}/ticket.hxx
	${PROJECT_NAME}/tickethistory.hxx
	${PROJECT_NAME}/client.hxx
	DESTINATION include/${PROJECT_NAME}
	)
