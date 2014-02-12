@echo off
set CC=mingw32-c++
set INCLUDES=../../include
set CFLAGS=-O3
set SOURCES=dxgi_test.cpp
set OUTFILE=dxgi_test.exe

echo %C_INCLUDE_PATH%

@echo on
%CC% -I %INCLUDES% %CFLAGS% %SOURCES% -o %OUTFILE% -v

%OUTFILE%

@pause