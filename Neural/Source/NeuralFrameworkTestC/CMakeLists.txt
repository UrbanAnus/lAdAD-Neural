cmake_minimum_required( VERSION 3.13.2 )

file(
    GLOB_RECURSE
    source_list
    RELATIVE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "NeuralFrameworkTestC/Include/*"
    "NeuralFrameworkTestC/Source/*"
)

add_executable( NeuralFrameworkTestC ${source_list} )

target_link_libraries( NeuralFrameworkTestC NeuralFrameworkC )

target_include_directories(
    NeuralFrameworkTestC
    PUBLIC
    "NeuralFrameworkTestC/Include/"
    PRIVATE
    "NeuralFrameworkTestC/Source/"
)

# For MSVC parse pretty filter names
foreach(source IN LISTS source_list)
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
endforeach()
