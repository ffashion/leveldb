add_executable(demo demo.cpp)
target_link_libraries(demo leveldb)

add_executable(hello hello.cpp)
target_link_libraries(hello leveldb)