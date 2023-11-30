# Shared Objects

Note: README.md written by ChatGPT.

This repository contains a simple example demonstrating the creation and usage of a shared object (shared library) in a Linux environment.

## Table of Contents

- [Concepts](#concepts)
- [Implementation Details](#implementation-details)
  - [Create a Simple Shared Library](#create-a-simple-shared-library)
  - [Create a Program Using the Shared Library](#create-a-program-using-the-shared-library)
  - [Run the Program](#run-the-program)
- [How to Use](#how-to-use)

## Concepts

### Shared Object (Shared Library)

A shared object (or shared library) is a file containing compiled code that can be dynamically loaded into a program at runtime. This allows for modular code organization and sharing of functionalities among different programs.

### `dlopen` and `dlsym`

In Linux, the `dlopen` function is used to dynamically load a shared library, and `dlsym` is used to obtain a pointer to a function within that library. This dynamic loading enables flexibility and modularity in program design.

## Implementation Details

### Create a Simple Shared Library

The `addition.c` file contains a basic function, `add`, which adds two numbers. We compile this into a shared library named `libaddition.so`.

```
gcc -shared -o build/libaddition.so addition.c
```
### Create a Program Using the Shared Library

The main.c file demonstrates how to dynamically load the shared library, get a function pointer, and use it. We compile the main program, linking against the dynamic linking library (-ldl for the dlopen functions).

```
gcc -o build/main main.c -ldl
```

### Run the Program

Navigate to the build folder and execute the program:
```
cd build
./main
```
This will display the result of adding two numbers using the shared library.

## How to Use

### Clone the repository:

```
git clone <repository_url>
cd shared-object-example
```

### Compile the shared library:

```
gcc -shared -o build/libaddition.so addition.c
```

### Compile the main program:

```
gcc -o build/main main.c -ldl
```

### Run the executable:

```
cd build
./main
```

This will output the result of adding two numbers.

Feel free to explore and modify the example to better understand the concepts of shared objects in Linux.
