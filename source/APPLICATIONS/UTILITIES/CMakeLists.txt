# The name of the project to build
PROJECT(UTILITIES)

# Set BALL specific includes and compilerflags
INCLUDE_DIRECTORIES(${PROJECT_BINARY_DIR})
ADD_DEFINITIONS(${BALL_ADD_CXXFLAGS})

# add UTILITIES targets
SET(UTILITIES_EXECUTABLES)
INCLUDE(sources.cmake)

FOREACH(i ${UTILITIES_EXECUTABLES})
        ADD_EXECUTABLE(${i} ${i}.C)
        TARGET_LINK_LIBRARIES(${i} BALL Qt5::Core)
        SET_PROPERTY(TARGET ${i} PROPERTY FOLDER UTILITIES)
	SET_TARGET_PROPERTIES(${i} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${UTILS_RUNTIME_OUTPUT_DIRECTORY})
ENDFOREACH(i)


