@echo off

set masterfolder=%cd%

mkdir build
cd build
call cmake -G "Visual Studio 16 2019" -T host=x64 -A x64 ..

cd %masterfolder%
