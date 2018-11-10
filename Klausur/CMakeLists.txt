cmake_minimum_required(VERSION 3.12)
project(Klausur)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Optimiert
        Klausur03NOV2018.cpp
        KlausurUtils.cpp
        KlausurUtils.h
        )

add_executable(Abgabe
        KlausurAbgabe.cpp
        KlausurUtils.cpp
        KlausurUtils.h
        )
