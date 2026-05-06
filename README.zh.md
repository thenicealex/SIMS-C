# 学生信息管理系统 (C语言)

> [English](./README.md)

基于C语言开发的学生信息管理系统，提供学生信息的增删改查、排序和文件存储功能。

## 项目结构

```
student-management-system/
├── mylist.h          # 单文件头文件库（STB 风格）：声明 + 实现
├── student.c         # 主程序和业务逻辑
├── build/            # 编译输出目录
├── docs/             # 文档目录
├── tests/            # 测试文件目录
├── Makefile          # 构建脚本
└── README.md         # 项目说明
```

## STB 风格说明

本项目采用 [stb](https://github.com/nothings/stb) 风格的单文件头文件库设计：

- **`include/mylist.h`** 是一个独立的单文件库，包含完整的声明和实现
- **默认情况下**，只暴露声明，不生成实现代码
- **在恰好一个 `.c` 文件中**，先定义 `MYLIST_IMPLEMENTATION` 宏，再包含头文件，即可生成实现：

```c
#define MYLIST_IMPLEMENTATION
#include "mylist.h"
```

## 功能特性

- 用户登录系统
- 添加学生信息（学号、姓名、性别、年龄、数学成绩、英语成绩）
- 查询学生信息（按学号/姓名）
- 修改学生信息
- 删除学生信息
- 按多种方式排序（学号、数学成绩、英语成绩、总分）
- 数据持久化存储（student.txt）

## 编译和运行

```bash
# 编译项目
make

# 运行程序
make run

# 清理构建文件
make clean

# 安装到系统
make install

# 从系统卸载
make uninstall
```

## 系统要求

- GCC 编译器
- POSIX 兼容系统（Linux/macOS）

## 许可证

MIT License
