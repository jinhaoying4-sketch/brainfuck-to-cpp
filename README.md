# brainfuck-to-cpp
# 🧠 Brainfuck to C++ Compiler

> A lightweight Brainfuck-to-C++ compiler written in C++
> Generates native C++ source code from Brainfuck programs for significantly improved execution performance.

---

# 📌 Overview

Brainfuck is a minimalist esoteric programming language consisting of only eight commands.

Traditional Brainfuck interpreters execute instructions one by one at runtime, which introduces interpretation overhead.

This project takes a different approach:

```text
Brainfuck Source
       ↓
  Code Translation
       ↓
     C++ Code
       ↓
 Native Compiler
       ↓
 Executable Program
```

By translating Brainfuck directly into C++, programs can be compiled by modern C++ compilers such as GCC or Clang, achieving much higher execution efficiency.

---

# 🎯 Project Goal

The purpose of this project is to explore:

* Compiler fundamentals
* Source-to-source translation
* Code generation techniques
* Memory model implementation
* Performance optimization through compilation

Instead of interpreting Brainfuck instructions at runtime, the compiler generates equivalent C++ code that can be optimized by existing compiler toolchains.

---

# ✨ Features

## Brainfuck Command Translation

Supports all standard Brainfuck instructions:

| Brainfuck | Meaning            | Generated C++   |
| --------- | ------------------ | --------------- |
| `>`       | Move pointer right | `ptr++`         |
| `<`       | Move pointer left  | `ptr--`         |
| `+`       | Increment cell     | `(*ptr)++`      |
| `-`       | Decrement cell     | `(*ptr)--`      |
| `.`       | Output character   | `putchar(*ptr)` |
| `,`       | Input character    | `getchar()`     |
| `[`       | Loop start         | `while(*ptr){`  |
| `]`       | Loop end           | `}`             |

---

## Configurable Memory Size

Users can specify the tape size used by the generated program.

Example:

```text
Memory Cells: 30000
```

Generated code:

```cpp
static uint8_t array[30000] = {0};
```

This allows memory usage to be customized according to program requirements.

---

## Native C++ Code Generation

Instead of producing machine code directly, the compiler generates readable and editable C++ source files.

Advantages:

* Easy debugging
* Easy learning
* Compiler optimization support
* Cross-platform compatibility

---

## Standard Input / Output Support

Supports Brainfuck input and output operations.

### Input

```brainfuck
,
```

Generated:

```cpp
(*ptr) = getchar();
```

### Output

```brainfuck
.
```

Generated:

```cpp
putchar(*ptr);
fflush(stdout);
```

---

# 🏗️ Architecture

```text
          Brainfuck File
                 │
                 ▼
      Character-by-Character Parser
                 │
                 ▼
       Instruction Translation
                 │
                 ▼
         C++ Source Generator
                 │
                 ▼
          Generated .cpp File
                 │
                 ▼
       GCC / Clang Compilation
                 │
                 ▼
         Native Executable
```

---

# 🔧 Build

## Requirements

* C++17 or later
* GCC / Clang / MSVC

## Compile

```bash
g++ main.cpp -o bf2cpp
```

## Run

```bash
./bf2cpp
```

---

# 🚀 Usage

### Step 1

Prepare a Brainfuck source file.

Example:

```brainfuck
++++++++++[>+++++++>++++++++++>+++>+<<<<-]
>++.>+.+++++++..+++.>++.
<<+++++++++++++++.
>.+++.------.--------.>+.>.
```

### Step 2

Run the converter.

```text
Input BF File:
hello.bf

Output C++ File:
hello.cpp

Memory Size:
30000
```

### Step 3

Compile generated code.

```bash
g++ hello.cpp -O2 -o hello
```

### Step 4

Execute program.

```bash
./hello
```

Output:

```text
Hello World!
```

---

# 📈 Why Compile Instead of Interpret?

### Traditional Interpreter

```text
Brainfuck
    ↓
 Interpreter
    ↓
 Execution
```

Every instruction must be decoded repeatedly.

---

### This Project

```text
Brainfuck
    ↓
 C++ Generator
    ↓
 GCC Optimization
    ↓
 Native Binary
```

The Brainfuck instructions are translated only once.

Benefits:

* Faster execution
* Better compiler optimization
* Lower runtime overhead

---

# 🛠️ Technologies Used

* C++
* STL
* File I/O
* Source Code Generation
* Compiler Design Concepts

---

# 📚 What I Learned

Through this project, I gained practical experience in:

* Compiler construction basics
* Lexical processing
* Code generation
* Language translation
* Memory management models
* Performance-oriented software design

---

# 🔮 Future Improvements

Planned enhancements:

* Syntax validation
* Bracket matching analysis
* Intermediate Representation (IR)
* Optimization passes
* Direct executable generation
* LLVM backend support
* GUI interface

---

# 👨‍💻 Author

**Kim**

Personal Compiler Project

Portfolio Project for Kakao AI Rookie Camp

2026
