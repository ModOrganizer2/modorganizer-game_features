CMAKE_MINIMUM_REQUIRED (VERSION 2.8.11)

CMAKE_POLICY(SET CMP0020 NEW)
CMAKE_POLICY(SET CMP0043 NEW)

SET(gamefeatures_SRCS
  )

SET(gamefeatures_HDRS
    bsainvalidation.h
    scriptextender.h
    dataarchives.h
    localsavegames.h
    gameplugins.h
    unmanagedmods.h
  )

INCLUDE_DIRECTORIES(../../uibase/src)

ADD_LIBRARY(${PROJ_NAME} STATIC ${${PROJ_NAME}_HDRS} ${${PROJ_NAME}_SRCS})
SET_TARGET_PROPERTIES(${PROJ_NAME} PROPERTIES LINKER_LANGUAGE CXX)
