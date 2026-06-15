*This project has been created as part of the 42 curriculum by bda-luz-*

# ft_printf 42

## Description
This project is based on the standard printf function behavior from the C library. The goal of this project is to understand variadic functions and string formatting. It will be part of my libft for my future projects in the 42 Common Core.

## Supported Conversions

The implementation handles the following mandatory format specifiers:

| Specifier | Description |
| :---: | :--- |
| `%c` | Prints a single character. |
| `%s` | Prints a string (as defined by the common C convention). |
| `%p` | Prints the `void *` pointer argument in hexadecimal format. |
| `%d` | Prints a decimal (base 10) number. |
| `%i` | Prints an integer in base 10. |
| `%u` | Prints an unsigned decimal (base 10) number. |
| `%x` | Prints a number in hexadecimal (base 16) lowercase format. |
| `%X` | Prints a number in hexadecimal (base 16) uppercase format. |
| `%%` | Prints a percent sign. |

## Instructions

### Compilation & Usage

### Prerequisites
Before compiling, ensure you have a C compiler (`cc` or `gcc`) and the `make` utility installed and configured on your system.

### Compilation
The library is compiled using `cc` with the strict flags `-Wall -Wextra -Werror`.

| Command | Description |
| :--- | :--- |
| `make` | Compiles all source files and generates the `libftprintf.a` static library. |
| `make clean` | Removes all intermediary object files (`.o`). |
| `make fclean` | Removes all object files and the compiled `libftprintf.a`. |
| `make re` | Performs a full cleanup and forces a fresh recompilation (`fclean` + `make`). |

### Using the Library
To use `ft_printf`in your own C project:

#### 1. Include the Header
Add the `ft_printf.h` header inside your project's main header file
```c
#ifndef MAIN_H
# define MAIN_H

/* Include ft_printf */
# include "ft_printf.h"

/* Your other libraries and prototypes */

#endif
```

#### 2. Compilation & Linking
When compiling your project, you must link the `libftprintf.a` static library.
```bash
cc -Wall -Wextra -Werror *.c -L. -lftprintf -o youroutputfile
```


## Resources / References

- https://man7.org/linux/man-pages/
- https://www.ibm.com/docs/en/i/7.6.0?topic=lf-va-arg-va-copy-va-end-va-start-handle-variable-argument-list
- https://pliniohavila.hashnode.dev/introducao-aos-macros-vastart-vaarg-vaend-vacopy-na-linguagem-c
- https://www.youtube.com/watch?v=7Sph8JlRo0g

### AI Usage

AI tools were used for:

- Clarifying function specifications and expected behavior.
- Assisting with the creation of this readme.