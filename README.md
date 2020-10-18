# Kanban Board App

## Prerequisites

- Visual Studio Code (IDE)

## Backend (kanban-board-service)

### Backend Prerequisites

#### Tools

- CMake
- C++ Compiler
  - GCC (Linux), Visual Studio C++ Compiler (Windows) or Clang (Mac)
- C++ Debugger
  - GDB (Linux) or lldb (Mac)

#### Libraries

- Boost > 1.55
- SQLite3

### Build the C++ application

- open Command Palette `Ctrl+Shift+P` and run `CMake: Configure`
  - `kanban-board-service/build` should be created (contains build system)
- open Command Palette `Ctrl+Shift+P` and run `CMake: Build`

### Run and debug the application

- open Command Palette `Ctrl+Shift+P` and run `CMake: Run without Debugging`
- With Debugger: open Command Palette `Ctrl+Shift+P` and run `CMake: Debug`

### Useful guides

#### API Endpoints

- <https://github.com/ipkn/crow/tree/master/examples>

#### JSON library

- <https://rapidjson.org/md_doc_tutorial.html>

### Troubleshooting

#### GDB

- source files of stl not found:
  - add a sourceFileMap entry to `launch.json` files

#### Cmake Tools

- no compiler kit found:
  - open Command Palette `Ctrl+Shift+P` and run the `CMake: Edit User-Local CMake Kits` command
  - specify your correct compiler path in `cmake-tools-kits.json` file

#### Application Exceptions

- Boost system error: bind: Address already in use:
  - Kill application running on port 8080: `kill \$(lsof -t -i:8080)`

## Frontend (kanban-board-app)

### Frontend Prerequisites

- NPM (NodeJs) <https://nodejs.org/en/>

### Build the Angluar application

- Run `npm install` to install dependencies
- Run `npm run build` to build frontend

### Tasks

#### Development server

Run `npm run start` for a dev server. Navigate to `http://localhost:4200/`. The app will automatically reload if you change any of the source files.

#### Build

Run `npm run build` to build the project. The build artifacts will be stored in the `kanban-board-app/dist/` directory.

#### Running unit tests

Run `npm run test` to execute the unit tests via [Karma](https://karma-runner.github.io).

#### Lint

Run `npm run lint` to run linter.

#### Format with Prettier

Run `npm run format:check` to check all files for format issues.

Run `npm run format` to format all files.
