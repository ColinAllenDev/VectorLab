rm -rf build
meson setup build
ninja -C build
./build/Sandbox/sandbox-app