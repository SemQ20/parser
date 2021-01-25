echo off
rd /s /q CMakeFiles
del test.exe
del cmake_install.cmake
del CMakeCache.txt
del Makefile && cd ..