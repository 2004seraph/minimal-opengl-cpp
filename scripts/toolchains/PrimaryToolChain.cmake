#set(VCPKG_TARGET_TRIPLET x64-windows-cyanseraph-app)

message(STATUS "vcpkg toolchain loaded")

# THIS MUST BE AT THE BOTTOM
include($ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)

