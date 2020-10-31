# midgar
Midgar game engine

## Installation Instructions
Run the following after cloning:
- git submodule update --init
- git submodule update --remote
- CreateProjects.bat

### If you run into issues where Visual Studio can't see Windows 10 SDK
i.e. Standard headers are not visible (stddef.h, string.h, etc)

Download it here and install: https://developer.microsoft.com/en-us/windows/downloads/windows-10-sdk/

AND ENSURE YOU SET THE WINDOWS 10 SDK VERSION TO A SPECIFIC VERSION, NOT LATEST INSTALLED (doesn't seem to compile otherwise)