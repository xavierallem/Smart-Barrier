# Minimum Cmake verison required
cmake_minimum_required(VERSION 3.0.0)

project(smart_security_barrier C CXX)

set(CMAKE_CXX_STANDARD 14) 

add_executable(smart_security_barrier relay.cpp)

# Link to ShunyaInterfaces
target_link_libraries(smart_security_barrier siCore siYaml siPeripheral siConn siCloud siIiot)