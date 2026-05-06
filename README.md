# Student Information Management System (C)

> [中文](./README.zh.md)

A student information management system developed in C, providing CRUD operations, sorting, and file persistence.

## Project Structure

```
student-management-system/
├── mylist.h          # Single-file header library (STB style): declarations + implementation
├── student.c         # Main program and business logic
├── build/            # Build output
├── docs/             # Documentation
├── tests/            # Tests
├── Makefile          # Build script
└── README.md         # Project readme
```

## STB Style

This project adopts the [stb](https://github.com/nothings/stb) single-file header library design:

- **`include/mylist.h`** is a self-contained single-file library with full declarations and implementation
- **By default**, it only exposes declarations without generating implementation code
- **In exactly one `.c` file**, define `MYLIST_IMPLEMENTATION` before including the header to generate the implementation:

```c
#define MYLIST_IMPLEMENTATION
#include "mylist.h"
```

## Features

- User login system
- Add student info (ID, name, gender, age, math score, English score)
- Query student info (by ID / by name)
- Modify student info
- Delete student info
- Sort by multiple fields (ID, math score, English score, total score)
- Data persistence (student.txt)

## Build & Run

```bash
# Build
make

# Run
make run

# Clean
make clean

# Install to system
make install

# Uninstall from system
make uninstall
```

## Requirements

- GCC compiler
- POSIX-compatible system (Linux / macOS)

## License

MIT License
