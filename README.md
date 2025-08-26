# Briscola

# Building

CMake is used as build system for Briscola. Build is performed in `build` directory in this example.
Commands are executed in repository root.

```
$ mkdir build && cd build
$ cmake -DCMAKE_BUILD_TYPE=Debug ..
...
$ cmake --build .
...
```

This will create executable called `Briscola` in `build` directory.
