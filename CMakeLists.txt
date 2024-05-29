cmake_minimum_required(VERSION 3.5)

project(gestiune-transport)

set(CMAKE_CXX_STANDARD 17)
add_executable(gestiune-transport main.cpp Order.h Vehicle.h Vehicle.cpp User.h User.cpp Supplier.h Supplier.cpp Order.cpp Invoice.h Invoice.cpp Expense.h Expense.cpp Driver.h Driver.cpp
        main.cpp
        ProjectUtils.cpp
        ProjectUtils.h
        Person.cpp
        Person.h)