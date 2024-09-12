cmake_minimum_required(VERSION 3.25)
project(workerManagement)

set(CMAKE_CXX_STANDARD 11)

add_executable(workerManagement
        main.cpp
        inc/workerManagement.h
        src/workerManagement.cpp
        inc/worker.h
        inc/employee.h
        src/empolyee.cpp
        inc/manager.h
        src/manager.cpp
        inc/boss.h
        src/boss.cpp
        )
