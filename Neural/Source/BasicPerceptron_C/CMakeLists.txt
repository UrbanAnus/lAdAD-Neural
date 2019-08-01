cmake_minimum_required( VERSION 3.13.2 )

file(
    GLOB_RECURSE
    source_list
    RELATIVE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "BasicPerceptron_C/Include/*"
    "BasicPerceptron_C/Source/*"
)

add_executable( BasicPerceptron_C ${source_list} )

target_include_directories(
    BasicPerceptron_C
    PUBLIC
    "BasicPerceptron_C/Include/"
    PRIVATE
    "BasicPerceptron_C/Source/"
)

# For MSVC parse pretty filter names
foreach(source IN LISTS source_list)
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
endforeach()
