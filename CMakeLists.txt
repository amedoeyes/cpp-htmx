cmake_minimum_required(VERSION 3.20)
project(cpp-htmx LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
set(FETCHCONTENT_QUIET OFF)

fetchcontent_declare(
    retina
    GIT_REPOSITORY https://github.com/amedoeyes/retina.git
    GIT_TAG master
    GIT_PROGRESS TRUE
)

fetchcontent_makeavailable(retina)

fetchcontent_declare(
    inja
    GIT_REPOSITORY https://github.com/pantor/inja.git
    GIT_TAG v3.4.0
    GIT_PROGRESS TRUE
)

fetchcontent_makeavailable(inja)

add_executable(cpp_htmx src/main.cpp)
target_link_libraries(cpp_htmx retina inja)
set_target_properties(
    cpp_htmx
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/
)
