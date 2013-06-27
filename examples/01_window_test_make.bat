@echo off
set CC=mingw32-c++
set INCLUDES=../include
set CFLAGS=-O3
set SOURCES=01_window_test.cpp
set OUTFILE=01_window_test.exe

@echo on
%CC% -I %INCLUDES% %CFLAGS% %SOURCES% -o %OUTFILE%

%OUTFILE%

@pause