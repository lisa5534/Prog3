# Kanban Board App

## Prerequisites

- Visual Studio Code (IDE)

## Backend (kanban-board-service)

### Prerequisites

#### Tools

- CMake (buildtool)
- gcc or clang (compiler)
- gdb or lldb (debugger)

#### Libraries

- Boost > 1.52
- mongocxx (install via package manager of OS or build from source with cmake: <http://mongocxx.org/mongocxx-v3/installation/>)

#### MongoDB

- run Application with MongoDB on default port: mongodb://localhost:27017 (change in **src/Application.cpp** if needed)
- run Application without database by setting **useDatabaseMock** to true in **src/Application.cpp**

#### Configure tools

- <https://code.visualstudio.com/docs/cpp/config-linux>
- <https://code.visualstudio.com/docs/cpp/cmake-linux>

### Build the application

#### via cmake tools extension

- open Command Palette **Ctrl+Shift+P** and run **CMake:Build**
- run **CMake:clean** to clean the project

#### via tasks.json

- open Command Palette **Ctrl+Shift+P** and run task **build**
- run task **clean** to clean the project

### Run and debug the application

#### via cmake tools extension

- Debug: open Command Palette **Ctrl+Shift+P** and run **CMake:Debug**
- Run: open Command Palette **Ctrl+Shift+P** and run **CMake:Run without Debugging**

#### via tasks.json

- Debug: open Command Palette **Ctrl+Shift+P**, type **Debug: Select and start debugging** and select **\"debug_Prog3\"**
- Run: open Command Palette **Ctrl+Shift+P** and run task **run**

### Useful guides

#### API Endpoints

- <https://github.com/ipkn/crow/tree/master/examples>

#### JSON library

- <https://rapidjson.org/md_doc_tutorial.html>

#### mongocxx driver

- <http://mongocxx.org/mongocxx-v3/tutorial>
- <https://github.com/mongodb/mongo-cxx-driver/tree/master/examples>

### Troubleshooting

#### GDB

- source files of stl not found:
  - add a sourceFileMap entry to **launch.json** files

#### Cmake Tools

- no compiler kit found:
  - open Command Palette **Ctrl+Shift+P** and run the **CMake: Edit User-Local CMake Kits** command
  - specify your correct compiler path in **cmake-tools-kits.json** file

#### Application Exceptions

- Boost system error: bind: Address already in use:
- Kill application running on port 8080: **kill \$(lsof -t -i:8080)**
- No suatable servers found:
- start MongoDB on localhost:27017 or set flag **useDatabaseMock** in application.cpp

## Frontend (kanban-board-app)

### Development server

Run `npm run start` for a dev server. Navigate to `http://localhost:4200/`. The app will automatically reload if you change any of the source files.

### Build

Run `npm run build` to build the project. The build artifacts will be stored in the `kanban-board-app/dist/` directory.

### Running unit tests

Run `npm run test` to execute the unit tests via [Karma](https://karma-runner.github.io).

### Lint

Run `npm run lint` to run linter.

### Format with Prettier

Run `npm run format:check` to check all files for format issues.

Run `npm run format` to format all files.
