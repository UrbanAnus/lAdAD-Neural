cmake_minimum_required( VERSION 3.13.2 )

file(
    GLOB_RECURSE
    source_list
    RELATIVE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "NeuralFrameworkC/Include/*"
    "NeuralFrameworkC/Source/*"
)

add_library( NeuralFrameworkC ${source_list} )

target_compile_definitions(NeuralFrameworkC PUBLIC UNICODE)

target_include_directories(
    NeuralFrameworkC
    PUBLIC
    "NeuralFrameworkC/Include/"
    PRIVATE
    "NeuralFrameworkC/Source/"
)

# For MSVC parse pretty filter names
foreach(source IN LISTS source_list)
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
endforeach()
