# Simple, cross-platform CMake template project for OpenGL apps

## Requirements

- CMake
- vcpkg for CMake: https://learn.microsoft.com/en-us/vcpkg/
  - Set the `VCPKG_ROOT` environment variable to the root of your vcpkg installation.

## Build

This project should be automatically parsed by most IDEs supporting CMake (Visual Studio, CLion, etc). So you will most likely just have to click the "Run" button in your editor. Otherwise, building from the command line is also quite simple, you may see the build presets in `CMakePresets.json`:

`cmake --preset "x64-debug" && cmake --build --preset "debug"`
