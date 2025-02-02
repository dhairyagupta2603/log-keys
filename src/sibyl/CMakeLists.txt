include(GetSpdlog)
include(BuildInfo)

# Create an object library for compiling .cpp files into object files
add_library(sibyl OBJECT sibyl.cpp)

# Set target properties
target_sources(sibyl
  PUBLIC FILE_SET HEADERS
  BASE_DIRS include
)
set_target_properties(sibyl PROPERTIES POSITION_INDEPENDENT_CODE 1)

InstrumentForCoverage(sibyl)

# Create the shared library
add_library(sibyl_shared SHARED)
target_link_libraries(sibyl_shared PUBLIC sibyl)

add_library(sibyl_static SHARED)
target_link_libraries(sibyl_static PUBLIC sibyl)

CleanCoverage(sibyl_static)
Format(sibyl_static .)
AddCppCheck(sibyl)
Doxygen(sibyl src/sibyl)

# Install the shared library and headers
include(GNUInstallDirs)
install(TARGETS sibyl sibyl_shared sibyl_static
  EXPORT SibylLibrary
  ARCHIVE COMPONENT development
  LIBRARY COMPONENT runtime
  FILE_SET HEADERS COMPONENT runtime
)


# Export for use in other projects
install(EXPORT SibylLibrary
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/sibyl/cmake
  NAMESPACE sibyl::
  COMPONENT runtime
)

# Install the configuration file
install(FILES "SibylConfig.cmake" DESTINATION "${CMAKE_INSTALL_LIBDIR}/sibyl/cmake")

# Generate build information
BuildInfo(sibyl)
