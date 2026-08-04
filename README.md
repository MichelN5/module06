*This project has been created as part of the 42 curriculum by mnaouss*

# CPP Module 06

## Description

CPP Module 06 is the seventh C++ module in the 42 curriculum. Its goal is to
introduce the different C++ casts, scalar type conversion, pointer
reinterpretation, and runtime type identification in C++98.

The project contains three exercises:

- `ex00`: `ScalarConverter`, a non-instantiable class that converts a string
  representation of a C++ literal to `char`, `int`, `float`, and `double`.
- `ex01`: `Serializer`, which uses `reinterpret_cast` to serialize a `Data`
  pointer into a `uintptr_t` value and deserialize it back into a pointer.
- `ex02`: Runtime type identification using a polymorphic `Base` class and the
  derived classes `A`, `B`, and `C`, identified with `dynamic_cast` without
  using `typeinfo`.

## Instructions

Each exercise has its own `Makefile`. Build and run it from its exercise
directory.

### ex00

```sh
cd ex00
make
./convert 42.0f
make fclean
```

The `convert` program expects exactly one scalar literal as an argument.

### ex01

```sh
cd ex01
make
./serializer
make fclean
```

### ex02

```sh
cd ex02
make
./identify
make fclean
```

The project is written for C++98 and is compiled with:

```sh
c++ -Wall -Wextra -Werror -std=c++98
```

## Resources

- C++ reference: https://cplusplus.com/reference/
- Type conversions: https://cplusplus.com/doc/tutorial/typecasting/
- `static_cast`: https://en.cppreference.com/w/cpp/language/static_cast
- `reinterpret_cast`: https://en.cppreference.com/w/cpp/language/reinterpret_cast
- `dynamic_cast`: https://en.cppreference.com/w/cpp/language/dynamic_cast
- Fixed-width integer types: https://cplusplus.com/reference/cstdint/

AI was used as a learning assistant to clarify casting concepts, review project
requirements, help debug the exercises, and prepare documentation. The final
code was reviewed and tested locally with the required compiler flags.
