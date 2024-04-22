cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("projectHelper")

# Add source to this project's executable.
add_executable (projectHelper "projectHelper.cpp" "projectHelper.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET projectHelper PROPERTY CXX_STANDARD 20)
endif()

add_subdirectory(3rdparty/RapidFuzz)
find_package(rapidfuzz REQUIRED)

target_link_libraries(projectHelper rapidfuzz::rapidfuzz)
	