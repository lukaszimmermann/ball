FIND_PACKAGE(OpenEye)
IF(NOT OPENEYE_FOUND)
	FIND_PACKAGE(OpenBabel)
	SET(PREFIX OPENBABEL)
ELSE()
	SET(PREFIX OPENEYE)
ENDIF()

IF(OPENBABEL_FOUND OR OPENEYE_FOUND)
	SET(BALL_HAS_${PREFIX} TRUE)
	LIST(APPEND BALL_DEP_LIBRARIES ${${PREFIX}_LIBRARIES})
	INCLUDE_DIRECTORIES(${${PREFIX}_INCLUDE_DIRS})
ENDIF()