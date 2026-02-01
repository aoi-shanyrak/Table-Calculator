# Table Calculator

A simple arithmetic expression interpreter in C++ implementing a basic calculator language with variable support. This project demonstrates fundamental concepts of interpreter and compiler construction.
Features

    Basic arithmetic operations: +, -, *, /

    Operator precedence and parentheses support

    Variable support (identifiers)

    Variable assignment using = operator

    Interactive mode

    Negative number handling

## Grammar
```text

Expression = Term {('+' | '-') Term}
Term = Primary {('*' | '/') Primary}
Primary = Number | Identifier | '-' Primary | '(' Expression ')'
```
## Building
```bash

# Debug build with sanitizers
make debug

# Release build with optimizations
make release

# Format code
make format

# Check code style
make check-style

# Clean build
make clean
```
## Usage
```bash

./calculator
Table Calculator: Ctrl + D to exit
> 2 + 3 * 4
14
> x = 5
5
> y = x * 2
10
> x + y
15
> 
```
