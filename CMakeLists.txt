#cmake -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=g++ ..

cmake_minimum_required(VERSION 3.12)
project(NetworkApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(WIN32)
    set(WS2_LIB ws2_32)
    set(MSWSOCK Mswsock)
endif()

set(SOURCE_DIR src)
set(BSOURCES 
    start_server.cpp
    ${SOURCE_DIR}/Server.cpp
    ${SOURCE_DIR}/Session.cpp
    ${SOURCE_DIR}/RoomManager.cpp
    ${SOURCE_DIR}/Handlers.cpp
    ${SOURCE_DIR}/ChatRoom.cpp
)

set(RESULT "server")
add_executable(${RESULT} ${BSOURCES})
target_link_libraries(${RESULT} ${WS2_LIB} ${MSWSOCK})


set(ASIO_INCLUDE_DIRS
    "C:\\Program Files\\boost-1.88.0\\libs\\asio\\include"
    "C:\\Program Files\\boost-1.88.0\\libs\\config\\include" 
    "C:\\Program Files\\boost-1.88.0\\libs\\assert\\include" 
    "C:\\Program Files\\boost-1.88.0\\libs\\throw_exception\\include" 
    "C:\\Program Files\\boost-1.88.0\\libs\\align\\include" 
    "C:\\Program Files\\boost-1.88.0\\libs\\system\\include" 
    "C:\\Program Files\\boost-1.88.0\\libs\\winapi\\include" 
    "C:\\Program Files\\boost-1.88.0\\libs\\predef\\include" 
    "C:\\Program Files\\boost-1.88.0\\libs\\date_time\\include" 
    "C:\\Program Files\\boost-1.88.0\\libs\\smart_ptr\\include" 
    "C:\\Program Files\\boost-1.88.0\\libs\\core\\include" 
    "C:\\Program Files\\boost-1.88.0\\libs\\utility\\include" 
    "C:\\Program Files\\boost-1.88.0\\libs\\static_assert\\include" 
    "C:\\Program Files\\boost-1.88.0\\libs\\type_traits\\include" 
    "C:\\Program Files\\boost-1.88.0\\libs\\numeric\\conversion\\include" 
    "C:\\Program Files\\boost-1.88.0\\libs\\mpl\\include" 
    "C:\\Program Files\\boost-1.88.0\\libs\\preprocessor\\include"
)

target_include_directories(${RESULT} PRIVATE ${ASIO_INCLUDE_DIRS})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

add_custom_target(
    run
    COMMAND ".\\bin\\${RESULT}"
    DEPENDS ${RESULT}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)