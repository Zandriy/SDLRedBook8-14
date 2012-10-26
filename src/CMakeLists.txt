# it can exclude SDLmain lib on Linux, FMI: read FindSDL.cmake
# SET(SDL_BUILDING_LIBRARY FALSE)

find_package(SDL REQUIRED)

if(NOT SDL_FOUND)
	message( FATAL ERROR "SDL not found!")
endif(NOT SDL_FOUND)

find_package(OpenGL REQUIRED)

if(NOT OPENGL_FOUND)
	message( FATAL ERROR "GL not found!")
endif(NOT OPENGL_FOUND)

IF(APPLE)
	SET(SDL_MAIN_SOURCE SDLMain.m)
ELSE()
	SET(SDL_MAIN_SOURCE)
ENDIF()

SET(SDL_OGL_PROJECT_SOURCE
	prg.cpp
	OGLApplication.cpp
	OGLConsumer.cpp
	Lesson_1_2.cpp
	Lesson_1_3.cpp
	Lesson_2_5.cpp
	Lesson_2_6.cpp
	Lesson_2_7.cpp
	Lesson_2_9.cpp
	Lesson_2_10.cpp
	Lesson_2_11.cpp
	Lesson_2_13.cpp
	Lesson_2_15.cpp
	Lesson_2_15ex.cpp
	Lesson_3_1.cpp
	Lesson_3_2.cpp
	Lesson_3_5.cpp
	Lesson_3_6.cpp
	Lesson_3_7.cpp
	)

SET(SDL_OGL_PROJECT_TARGET prg)

include_directories(
	${SDL_INCLUDE_DIR}
	${OPENGL_INCLUDE_DIR}
	)

link_libraries(
	${SDL_LIBRARY}
	${OPENGL_LIBRARY}
	)

ADD_EXECUTABLE(${SDL_OGL_PROJECT_TARGET} ${SDL_MAIN_SOURCE} ${SDL_OGL_PROJECT_SOURCE})

message("============ INFO ============")
message("OS: " ${CMAKE_SYSTEM})
message("PROCESSOR: " ${CMAKE_SYSTEM_PROCESSOR})
message("SDL INCLUDE: " ${SDL_INCLUDE_DIR})
message("OPENGL INCLUDE: " ${OPENGL_INCLUDE_DIR})
message("SDL LIB: " ${SDL_LIBRARY})
message("OpenGL LIB: " ${OPENGL_LIBRARY})
message("==============================")
message(" !!! always do `pwd -P` before `rm` !!!")
message("==============================")
