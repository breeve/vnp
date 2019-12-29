# Install script for directory: /Users/breeve/Desktop/笔记/src/sdn/source/dataplane

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/breeve/Desktop/笔记/src/sdn/dev/bin/dataplane")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/breeve/Desktop/笔记/src/sdn/dev/bin" TYPE EXECUTABLE FILES "/Users/breeve/Desktop/笔记/src/sdn/build/source/dataplane/dataplane")
  if(EXISTS "$ENV{DESTDIR}/Users/breeve/Desktop/笔记/src/sdn/dev/bin/dataplane" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/Users/breeve/Desktop/笔记/src/sdn/dev/bin/dataplane")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/breeve/Desktop/笔记/src/sdn/build/source/lib/libbase"
      "$ENV{DESTDIR}/Users/breeve/Desktop/笔记/src/sdn/dev/bin/dataplane")
    execute_process(COMMAND /usr/bin/install_name_tool
      -add_rpath "/Users/breeve/Desktop/笔记/src/sdn/dev/lib"
      "$ENV{DESTDIR}/Users/breeve/Desktop/笔记/src/sdn/dev/bin/dataplane")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Library/Developer/CommandLineTools/usr/bin/strip" -u -r "$ENV{DESTDIR}/Users/breeve/Desktop/笔记/src/sdn/dev/bin/dataplane")
    endif()
  endif()
endif()

