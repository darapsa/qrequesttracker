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

if (ANDROID)
	set(ANDROID_BUILD_ABI_${ANDROID_ABI} 1)
	set(CMAKE_CXX_STANDARD_LIBRARIES ${ANDROID_NDK}/sources/cxx-stl/llvm-libc++/libs/${ANDROID_ABI}/libc++_shared.so)
	include_directories(${CMAKE_SYSROOT}/usr/include)
	target_link_directories(${PROJECT_NAME} PRIVATE
		${CMAKE_SYSROOT}/usr/lib/${ANDROID_TOOLCHAIN_NAME}/${ANDROID_NATIVE_API_LEVEL})
endif()

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
