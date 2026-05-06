# Changelog

All notable changes to this project will be documented in this file.

## [1.0.1] - 2026-05-07

### Fixed
- Prevent duplicate student ID insertion (`mylist_exists_by_id` check on add and file load)

### Changed
- Compute total score at runtime instead of storing redundant field in struct and file
- File format simplified from 7 to 6 columns (removed total score column)

## [1.0.0] - 2026-05-07

### Added
- GitHub Actions CI workflow for Ubuntu and macOS builds
- GitHub Actions Release workflow with multi-platform binaries
- Bilingual README (English and Chinese)

### Changed
- Adopt STB-style single-file header library (`mylist.h` with `MYLIST_IMPLEMENTATION` macro)
- Flatten project structure: move files to root directory
- Rename all APIs to `snake_case` with `mylist_` prefix
  - `struct student` → `struct mylist_student`
  - `struct Node` → `struct mylist_node`
  - `creatList()` → `mylist_create()`, etc.
- Fix `clear_screen()` recursive call bug on Windows

### Removed
- `src/mylist.c` (merged into `include/mylist.h`)
- `include/` and `src/` directories

## [0.1.0] - Earlier

### Added
- Student information management system in C
- Linked list data structure for student records
- CRUD operations (Create, Read, Update, Delete)
- Sort by ID, math score, English score, total score
- File persistence (`student.txt`)
- User login system
