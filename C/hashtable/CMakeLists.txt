add_library(hashtable hashtable.c hashtable.h)
target_include_directories(hashtable PUBLIC "${CMAKE_SOURCE_DIR}")
target_link_directories(hashtable PUBLIC "../List")
