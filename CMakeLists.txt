cmake_minimum_required(VERSION 3.0)

project(test)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)
	
include_directories(interfaces)
include_directories(impl)
include_directories(impl/checksumdataconsumer)
include_directories(impl/counterdataconsumer)
include_directories(impl/filedataprovider)
		
set(SOURCES
		main.cpp
		impl/dataprovider.cpp
		impl/checksumdataconsumer/checksumdataconsumer.cpp
		impl/counterdataconsumer/counterdataconsumer.cpp
		impl/filedataprovider/filedataprovider.cpp)
				
add_executable(test ${SOURCES})