cmake_minimum_required(VERSION 3.0)

# Create project
set(ProjectName "main")
project(${ProjectName})

# Create executable file
add_executable(${ProjectName}
    main.cpp
    hungarian_algorithm.h
)
