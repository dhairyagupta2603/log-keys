include(Coverage)
include(Format)
include(CppCheck)
include(Doxygen)

add_subdirectory(sibyl)
# add_subdirectory(app1)

add_executable(sybil-system main.cpp)
target_link_libraries(sybil-system PUBLIC sibyl)

InstrumentForCoverage(sybil-system)
CleanCoverage(sybil-system)
Format(sybil-system .)
AddCppCheck(sybil-system)
Doxygen(sybil-system src)

# Installation
install(TARGETS sybil-system RUNTIME COMPONENT runtime)



