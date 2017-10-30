cmake_minimum_required (VERSION 2.6)
project (Neuro)

set(CMAKE_CXX_FLAGS "-W -Wall -pedantic -std=c++11")

option(BUILD_DOCUMENTATION "Use Doxygen to create the HTML based API documentation" ON)
if(BUILD_DOCUMENTATION)
  FIND_PACKAGE(Doxygen)
  if (NOT DOXYGEN_FOUND)
    message(FATAL_ERROR
      "Doxygen is needed to build the documentation. Please install it correctly")
  endif()

  add_custom_target (doc ALL
                     ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile
                     WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc
                     )

endif()

add_executable (Sim1 Neuron.cpp SimuNeur.cpp)
