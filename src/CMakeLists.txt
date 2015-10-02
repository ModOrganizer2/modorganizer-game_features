CMAKE_MINIMUM_REQUIRED (VERSION 2.8)
PROJECT(gamefeatures)

CMAKE_POLICY(SET CMP0020 NEW)
CMAKE_POLICY(SET CMP0043 NEW)

SET(gamefeatures_SRCS
	
  )

SET(gamefeatures_HDRS
    bsainvalidation.h
    scriptextender.h
    dataarchives.h
  )

INCLUDE_DIRECTORIES(../../uibase/src)