cmake_minimum_required(VERSION 3.0)
project(queue_linked_list)

set(CMAKE_C_COMPILER "gcc")

# Set the output folder where your program will be created
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/lib)

# Add your source files here
set(SOURCES
    ../doubly_linked_lists/doubly_linked_lists.c
    main.c
    queue.c
)

# Generate the executable
add_executable(${PROJECT_NAME} ${SOURCES})
