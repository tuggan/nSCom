include_directories (${NSCOM_SOURCE_DIR}/lib)
link_directories (${NSCOM_SOURCE_DIR}/lib)

# Would like it to create a make debug thingey instead
set(CMAKE_CXX_FLAGS "-Wall -g -std=c++11 -lpthread -lncurses")

#dont really like this :/
file( GLOB SRCS *.cpp *.h)

add_executable (nSCom ${SRCS})

target_link_libraries (nSCom simpleSerialIO)

