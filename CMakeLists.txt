cmake_minimum_required(VERSION 3.14)
project(basetest LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    set(CMAKE_C_COMPILER clang-cl)
    set(CMAKE_CXX_COMPILER clang-cl)
endif()

add_definitions(-DUNICODE -D_UNICODE)
add_definitions(-DWIN32_LEAN_AND_MEAN)

add_executable(basetest
    main.cpp
)

target_compile_options(basetest PRIVATE "/FC")

include(${CMAKE_CURRENT_SOURCE_DIR}/xchromebase.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/absl.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/perfetto.cmake)

target_link_libraries(basetest PRIVATE perfetto)


target_link_libraries(basetest PRIVATE absl)
target_link_libraries(basetest PRIVATE xchromebase)
target_link_libraries(basetest PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/third_party/boringssl/boringssl.dll.lib")

target_link_libraries(basetest PRIVATE
    SetupAPI
    Propsys
    Powrprof
    Shlwapi
    Winmm
    Version
	Ws2_32
	Dbghelp
    delayimp
)

set(EXECUTABLE_OUTPUT_PATH out)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

target_include_directories(basetest PRIVATE
    base
)

add_custom_command(
    TARGET basetest POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_SOURCE_DIR}/third_party/boringssl/boringssl.dll
        $<TARGET_FILE_DIR:basetest>/boringssl.dll
    COMMENT "Copying boringssl.dll to output directory"
)
