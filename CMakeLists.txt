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
	client.cxx)

if (ANDROID)
	if (ANDROID_ABI STREQUAL "arm64-v8a")
		include_directories(/usr/local/aarch64-linux-android/sysroot/usr/include)
		target_link_directories(${PROJECT_NAME} PRIVATE /usr/local/aarch64-linux-android/sysroot/usr/lib)
	elseif (ANDROID_ABI STREQUAL "armeabi-v7a")
		include_directories(/usr/local/arm-linux-androideabi/sysroot/usr/include)
		target_link_directories(${PROJECT_NAME} PRIVATE /usr/local/arm-linux-androideabi/sysroot/usr/lib)
	elseif (ANDROID_ABI STREQUAL "x86")
		include_directories(/usr/local/i686-linux-android/sysroot/usr/include)
		target_link_directories(${PROJECT_NAME} PRIVATE /usr/local/i686-linux-android/sysroot/usr/lib)
	elseif (ANDROID_ABI STREQUAL "x86_64")
		include_directories(/usr/local/x86_64-linux-android/sysroot/usr/include)
		target_link_directories(${PROJECT_NAME} PRIVATE /usr/local/x86_64-linux-android/sysroot/usr/lib)
	endif()
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
