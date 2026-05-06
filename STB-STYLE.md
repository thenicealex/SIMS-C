# stb 项目代码文件风格总结

> 来源：[GitHub - nothings/stb](https://github.com/nothings/stb)

## 一、核心风格特征

### 1. 单文件库 (Single-File Libraries)

- 每个功能模块完全包含在一个独立的 `.h` 头文件中
- 无需复杂的构建配置或链接多个库文件
- 只需复制一个文件即可集成到项目中

### 2. 仅头文件 + 显式实现模式

- **默认行为**：像普通头文件一样，只提供声明，不生成实现代码
- **实现方式**：在**恰好一个** C/C++ 源文件中，先定义特定宏，再包含头文件

Example:

```c
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
