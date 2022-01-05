@echo off

set masterfolder=%cd%

cd projectn
mkdir build
cd build
call cmake -G "Visual Studio 16 2019" -T host=x64 -A x64 -DCMAKE_BUILD_TYPE=RelWithDebInfo -DURHO3D_GRAPHICS_API=OpenGL ..

cd %masterfolder%
