
cmake_minimum_required(VERSION 3.10)

project(Tutorial VERSION 1.03)

configure_file(cfgs.h.in cfgs.h)
add_subdirectory(List)
add_subdirectory(AVLTree)
add_subdirectory(hashtable)
add_executable(Tutorial main.c)


# add the executable
target_link_libraries(Tutorial PUBLIC List AVLTree)
# target_link_libraries(Tutorial PUBLIC List)

target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}"
                           )

# set the project name




