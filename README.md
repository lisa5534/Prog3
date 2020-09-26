# Prerequisites
## Tools
* visual studio code (ide)  
    * c/c++ extension
    * c++ snippets
    * cmake tools
* gcc or clang (compiler) 
* gdb (debugger)

## Libraries
* Boost > 1.52

# Configure tools
* https://code.visualstudio.com/docs/cpp/config-linux
* https://code.visualstudio.com/docs/cpp/cmake-linux

# Build the application
### via cmake tools extension:
* open Command Palette __Ctrl+Shift+P__ and run __CMake:Build__
* run __CMake:clean__ to clean the project 

### via tasks.json:
* open Command Palette __Ctrl+Shift+P__ and run task __build__
* run task __clean__ to clean the project

# Run and debug the application
### via cmake tools extension:
* Debug: open Command Palette __Ctrl+Shift+P__ and run __CMake:Debug__
* Run: open Command Palette __Ctrl+Shift+P__ and run __CMake:Run without Debugging__

### via tasks.json:
* Debug: open Command Palette __Ctrl+Shift+P__, type __Debug: Select and start debugging__ and select __\"debug_Prog3\"__
* Run: open Command Palette __Ctrl+Shift+P__ and run task __run__

# Troubleshooting
### GDB
* source files of stl not found:
    * add a sourceFileMap entry to __launch.json__ files
* use option __"MIMode":"lldb"__ in __launch.json__ when debugging with Clang
### Cmake Tools
* no compiler kit found:  
    * open Command Palette __Ctrl+Shift+P__  and run the __CMake: Edit User-Local CMake Kits__ command
    * specify your correct compiler path in __cmake-tools-kits.json__ file 