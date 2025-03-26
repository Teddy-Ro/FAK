# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "CMakeFiles\\FAK_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\FAK_autogen.dir\\ParseCache.txt"
  "FAK_autogen"
  )
endif()
