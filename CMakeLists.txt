cmake_minimum_required(VERSION 3.30)
project(RacingGame VERSION 0.0.1)

set(CMAKE_GENERATOR "Ninja")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Paths
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(VENDOR_DIR "${CMAKE_SOURCE_DIR}/vendor")
set(ASSETS_DIR "${CMAKE_SOURCE_DIR}/assets")
set(INTERMEDIATE_DIR "${CMAKE_BINARY_DIR}/intermediates")
set(EXPORT_DIR "${CMAKE_BINARY_DIR}/export")
set(BIN_DIR "${CMAKE_BINARY_DIR}/bin")

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BIN_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${INTERMEDIATE_DIR})

# Source files
file(GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.cpp" "${SRC_DIR}/*.h")

# Include directories
include_directories(${SRC_DIR} ${VENDOR_DIR})

# Add executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Build configurations
set(ASSETSPATH_MACRO "${ASSETS_DIR}")

if(CMAKE_BUILD_TYPE STREQUAL "Deploy")
    set(ASSETSPATH_MACRO "../assets")
endif()

target_compile_definitions(${PROJECT_NAME} PRIVATE ASSETSPATH="${ASSETSPATH_MACRO}")

set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
set(CMAKE_CXX_FLAGS_DEPLOY "-O3")

# Debug configuration
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${BIN_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${BIN_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${INTERMEDIATE_DIR})

# Release configuration
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${BIN_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${BIN_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${INTERMEDIATE_DIR})

# Deploy configuration
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEPLOY ${EXPORT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEPLOY ${EXPORT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEPLOY ${EXPORT_DIR})

# Custom Deploy configuration
add_custom_target(Deploy ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${ASSETS_DIR} ${EXPORT_DIR}/assets
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${BIN_DIR} ${EXPORT_DIR}
        COMMAND ${CMAKE_COMMAND} -E echo "Assets and DLLs copied to ${EXPORT_DIR}"
)

# Define Deploy build flags
set_target_properties(${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEPLOY ${EXPORT_DIR}
        LIBRARY_OUTPUT_DIRECTORY_DEPLOY ${EXPORT_DIR}
        ARCHIVE_OUTPUT_DIRECTORY_DEPLOY ${INTERMEDIATE_DIR}
)

# LIBRARIES
message(STATUS "Vendor directory: ${VENDOR_DIR}")

# --- RAYLIB ----
add_library(raylib STATIC IMPORTED)
set_target_properties(raylib PROPERTIES
    IMPORTED_LOCATION "${VENDOR_DIR}/Raylib/lib/raylib.lib"
    INTERFACE_INCLUDE_DIRECTORIES "${VENDOR_DIR}/Raylib/include"
)

# Ensure Windows dependencies are linked
if(WIN32)
    target_link_libraries(raylib INTERFACE winmm opengl32)
endif()

# Link raylib to the game
target_include_directories(${PROJECT_NAME} PUBLIC ${VENDOR_DIR}/Raylib/include)

add_library(imgui STATIC
        ${VENDOR_DIR}/imgui/imgui.cpp
        ${VENDOR_DIR}/imgui/imgui_draw.cpp
        ${VENDOR_DIR}/imgui/imgui_widgets.cpp
        ${VENDOR_DIR}/imgui/imgui_tables.cpp
        ${VENDOR_DIR}/imgui/rlImGui.cpp
)

target_include_directories(imgui PUBLIC ${VENDOR_DIR}/imgui ${VENDOR_DIR}/Raylib/include)

# Link libraries to your executable
target_link_libraries(${PROJECT_NAME} raylib imgui)
