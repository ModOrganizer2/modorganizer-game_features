CMAKE_MINIMUM_REQUIRED (VERSION 2.8)
PROJECT(gamefeatures)

CMAKE_POLICY(SET CMP0020 NEW)
CMAKE_POLICY(SET CMP0043 NEW)

SET(gamefeatures_SRCS)

SET(gamefeatures_HDRS
    bsainvalidation.h
    scriptextender.h
    dataarchives.h
  )


# Qt5
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
FIND_PACKAGE(Qt5Core REQUIRED)

INCLUDE_DIRECTORIES(../../uibase/src)

ADD_LIBRARY(gamefeatures STATIC ${gamefeatures_HDRS} ${gamefeatures_SRCS})

QT5_USE_MODULES(gamefeatures Core)
