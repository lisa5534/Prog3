# Instructions for Windows

## How to setup tools on Windows using MSYS2 (MinGW64)

### install MSYS2

- Get the [MSYS2 64 bit installer](https://repo.msys2.org/distrib/x86_64/msys2-x86_64-20200903.exe)
- install to default location `C:\msys64`
- start msys2 in `C:\msys6\msys2.exe`
- inside the msys2 shell type: `pacman -Syuu` (close the shell when you are asked to)
- type this command `pacman -Syuu` multiple until there are no updates left ;)

### install gcc via MSYS2

- starrt msys2.exe and type in msys2 shell:

```bash
pacman -S --needed base-devel mingw-w64-i686-toolchain mingw-w64-x86_64-toolchain \
                    git subversion mercurial \
                    mingw-w64-i686-cmake mingw-w64-x86_64-cmake
```

- add `C:\dev\msys64\mingw64\bin` and `C:\dev\msys64\mingw32\bin` **_in that order!!!_** to your system PATH
- type `gcc --version` or `g++ --version` to ensure installation and path setting is right

### install missing libraries via MSYS2

- type in msys2 shell:

```bash
   pacman -Sy mingw-w64-i686-boost mingw-w64-x86_64-boost mingw-w64-x86_64-sqlite3 mingw-w64-i686-sqlite3 libsqlite
```

### configure VisualStudio Code

- add the following lines to `.vscode\settings.json`: (cannot be commited due to platform incompatibility)

```json
  "cmake.generator": "MinGW Makefiles",
  "cmake.cmakePath": "C:/msys64/mingw64/bin/cmake.exe",
  "cmake.mingwSearchDirs": [
      "C:/msys64/mingw64",
  ],
  "cmake.preferredGenerators": [
      "MinGW Makefiles"
  ],
```

- select compiler kit `[GCC 10.2.0]` in the bottom bar
- run `cmake:Configure` again
- run `cmake_Build`
- run `cmake: Run without debugging`

## How to setup tools on Windows machines (using Visual Studio Compiler)

- download and install CMake via installer <https://cmake.org/download/>
- download and install Visual Studio (Community edition works) <https://visualstudio.microsoft.com/de/downloads/>
  - make sure to check C++ Build Tools on installer, otherwise you need to download seperatly
- download and install vcpkg <https://github.com/microsoft/vcpkg>
  - extract zip and move to `C:\vcpkg` so that executalbe path looks like `C:\vcpkg\vcpkg`
  - run `.\vcpkg\bootstrap-vcpkg.bat` to install
  - add `"cmake.configureSettings": { "CMAKE_TOOLCHAIN_FILE": "c:/vcpkg/scripts/buildsystems/vcpkg.cmake" }` to `.vscode/settings.json`
    - make sure path is correct for `CMAKE_TOOLCHAIN_FILE`
- install boost via vcpkg by running `.\vcpkg\vcpkg install boost` (can take a very long time >30m)
- install SQLite3 via vcpkg by running `.\vcpkg\vcpkg install sqlite3`
- run VSCode and select `Visual Studio Community 2019 Release - x86` compiler (`amd64` should work too)
  - VSCode asks you for compiler, if not you can select compiler on bottom toolbar next to `Build` entry
  - if no compiler shows up click `Scan for kits` first
- build and run application -> done
