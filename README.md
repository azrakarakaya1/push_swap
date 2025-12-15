# push_swap

**push_swap** is a 42 School algorithm project. The goal is to sort a random list of integers using two stacks (Stack A and Stack B) and a limited set of instructions, while minimizing the total number of operations.

## Features

- **Efficient Sorting:** Uses a custom simple sort for small lists (≤ 5 numbers) and **Radix Sort** (Bitwise) for large lists.
- **Robust Parsing:** Handles integers input as separate arguments or as a single quoted string.
- **Error Management:** Detects non-numeric input, duplicates, and integer overflows.

## Compilation

Use the provided Makefile to compile the project:

```bash
make
