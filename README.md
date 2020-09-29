# Prerequisites
## Tools
* CMake (buildtool)
* visual studio code (ide)  
    * c/c++ extension
    * c++ snippets
    * cmake tools
* gcc or clang (compiler) 
* gdb or lldb (debugger)

## Libraries
* Boost > 1.52
* mongocxx (install via package manager of OS or build from source with cmake: http://mongocxx.org/mongocxx-v3/installation/)

## MongoDB
* run Application with MongoDB on default port: mongodb://localhost:27017 (change in __src/Application.cpp__ if needed)
* run Application without database by setting __useDatabaseMock__ to true in __src/Application.cpp__

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

# Useful guides
### API Endpoints
* https://github.com/ipkn/crow/tree/master/examples
### JSON library
* https://rapidjson.org/md_doc_tutorial.html
### mongocxx driver
* http://mongocxx.org/mongocxx-v3/tutorial
* https://github.com/mongodb/mongo-cxx-driver/tree/master/examples


# Troubleshooting
### GDB
* source files of stl not found:
    * add a sourceFileMap entry to __launch.json__ files
### Cmake Tools
* no compiler kit found:  
    * open Command Palette __Ctrl+Shift+P__  and run the __CMake: Edit User-Local CMake Kits__ command
    * specify your correct compiler path in __cmake-tools-kits.json__ file 
### Application Exceptions
* Boost system error: bind: Address already in use:
    * Kill application running on port 8080: __kill $(lsof -t -i:8080)__
* No suatable servers found:
    * start MongoDB on localhost:27017 or set flag __useDatabaseMock__ in application.cpp