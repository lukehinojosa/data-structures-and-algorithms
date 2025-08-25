# source files
file(GLOB SRC_HEADERS src/*.h)
file(GLOB EXE_SOURCES src/*.cpp)
file(GLOB TEST_SOURCES src/*.cpp)

# remove files that shouldnt be there
list(REMOVE_ITEM EXE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/test.cpp)
list(REMOVE_ITEM TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

# get the assignment name from the folder name
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# add executable
add_executable(${ProjectId} ${EXE_SOURCES} ${MLD_SRC})
add_executable(${ProjectId}_tests ${TEST_SOURCES} ${MLD_SRC})

# link the library
target_link_libraries(${ProjectId} plotsvg)
target_link_libraries(${ProjectId}_tests plotsvg)

# add tests
doctest_discover_tests(${ProjectId}_tests) # todo: do we need this?

# include directories
target_include_directories(${ProjectId} PUBLIC src)
target_include_directories(${ProjectId}_tests PUBLIC src)

# copy data files
file(GLOB DATA *.txt *.csv)
file(COPY ${DATA} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
