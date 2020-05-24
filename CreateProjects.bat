if not exist ".\Midgar\vendor\GLFW" mkdir ".\Midgar\vendor\GLFW"
if not exist ".\Midgar\vendor\spdlog" mkdir ".\Midgar\vendor\spdlog"

call vendor\bin\premake\premake5.exe vs2019
PAUSE