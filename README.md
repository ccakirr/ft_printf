# ft_printf

A custom implementation of the C standard library's `printf` function, created as part of the 42 School curriculum.

## Description

This project involves recoding the `printf` function from scratch, handling various format specifiers and providing formatted output functionality. The implementation focuses on understanding variadic functions, type conversions, and low-level output operations.

## Features

The `ft_printf` function supports the following format specifiers:

- `%c` - Print a single character
- `%s` - Print a string
- `%p` - Print a pointer address in hexadecimal format
- `%d` - Print a decimal (base 10) number
- `%i` - Print an integer in base 10
- `%u` - Print an unsigned decimal number
- `%x` - Print a number in hexadecimal (lowercase) format
- `%X` - Print a number in hexadecimal (uppercase) format
- `%%` - Print a percent sign

## Installation

Clone the repository and compile the library:

```bash
git clone https://github.com/ccakirr/ft_printf.git
cd ft_printf
make
```

This will generate the `ft_printf.a` static library.

## Usage

Include the header in your C file:

```c
#include "ft_printf.h"
```

Compile your program with the library:

```bash
gcc your_file.c ft_printf.a -o your_program
```

Example usage:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "world");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    ft_printf("Pointer: %p\n", &main);
    return (0);
}
```

## Makefile Rules

- `make` - Compile the library
- `make clean` - Remove object files
- `make fclean` - Remove object files and the library
- `make re` - Recompile the library from scratch

## Project Structure

```
.
├── ft_printf.c        # Main ft_printf implementation
├── ft_printf_util.c   # Utility functions for output operations
├── ft_printf.h        # Header file with function prototypes
├── Makefile           # Compilation rules
└── README.md          # Project documentation
```

## Function Prototype

```c
int ft_printf(const char *format, ...);
```

Returns the number of characters printed (excluding the null byte).

## 42 School

This project is part of the 42 School common core curriculum. It helps students understand:

- Variadic functions in C
- Format string parsing
- Type conversions and casting
- Memory management
- Low-level I/O operations

## Author

**ccakir** - [GitHub](https://github.com/ccakirr)

## License

This project is part of the 42 School curriculum and is intended for educational purposes.
