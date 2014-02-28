@echo off

echo.
echo ***** Test of %1. *****
echo.

set CC=mingw32-c++
set INCLUDES=../../include
set CFLAGS=-O3
set SOURCES=%1_test.cpp
set OUTFILE=run.exe

%CC% -I %INCLUDES% %CFLAGS% %SOURCES% -o %OUTFILE%

%OUTFILE%