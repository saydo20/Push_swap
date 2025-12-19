# push_swap

*This project has been created as part of the 42 curriculum by sjdia.*

## Description

**push_swap** is a sorting algorithm project that challenges students to sort a stack of integers using a limited set of operations and the smallest number of moves possible. The program must sort a stack (stack A) using an auxiliary stack (stack B) while minimizing the total number of operations.

The goal is to implement an efficient sorting algorithm that can handle various input sizes while maintaining optimal performance. The project helps develop skills in algorithm complexity analysis, optimization techniques, and problem-solving under constraints.

## Available Operations

The program can only use the following operations to sort the stack:

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first 2 elements at the top of stack A |
| `sb` | Swap the first 2 elements at the top of stack B |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push the first element of stack B to stack A |
| `pb` | Push the first element of stack A to stack B |
| `ra` | Rotate stack A (shift up all elements by 1) |
| `rb` | Rotate stack B (shift up all elements by 1) |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack A (shift down all elements by 1) |
| `rrb` | Reverse rotate stack B (shift down all elements by 1) |
| `rrr` | `rra` and `rrb` at the same time |

## Algorithm Approach

This implementation uses a **custom version of the chunk algorithm**. The chunk algorithm divides the input into segments and processes them strategically:

1. **Chunking Phase**: The numbers are divided into chunks based on their position in the sorted sequence
2. **Push Phase**: Elements are pushed to stack B in chunks, with strategic positioning
3. **Optimization Phase**: Elements are rotated to optimal positions
4. **Push Back Phase**: Elements are pushed back to stack A in descending order
5. **Final Sorting**: Any remaining elements are sorted with minimal operations

This approach balances efficiency across different input sizes and provides consistent performance.

## Instructions

### Compilation

Clone the repository and compile the project:

```bash
git clone <repository-url>
cd push_swap
make
```

This will generate the `push_swap` executable.

### Usage

Run the program with a list of integers as arguments:

```bash
./push_swap 4 67 3 87 23
```

The program will output the sequence of operations needed to sort the stack.

### Example

```bash
$ ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
```

### Testing

You can verify the output by counting the number of operations:

```bash
./push_swap 4 67 3 87 23 | wc -l
```

Or test with random numbers:

```bash
ARG=$(shuf -i 0-100 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l
```

### Error Handling

The program handles the following error cases:
- Non-integer arguments
- Numbers outside integer range
- Duplicate numbers
- Invalid input format

Errors are displayed as `Error\n` on standard error output.


## Project Structure

```
push_swap/
├── Makefile
├── README.md
├── push_swap.h
├── push_swap.c
├── checker_linux
├── operations/
│   ├── push.c
│   ├── reverse.c
│   ├── rotate.c
│   └── swap.c
├── parsing/
│   └── parsing.c
└── utils/
    ├── push_swap_utils_2.c
    ├── push_swap_utils_3.c
    ├── push_swap_utils_4.c
    ├── push_swap_utils.c
    └── sort.c
```

## Resources

### Documentation & Tutorials
- [Push_swap: The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) - Excellent overview of various algorithms
- [Push_swap Visualizer](https://github.com/o-reo/push_swap_visualizer) - Tool to visualize the sorting process

### AI Usage
AI (ChatGPT/Claude) was used in this project for:
- **Understanding the chunk algorithm**: AI helped explain the steps and logic behind dividing the input into chunks and how to process them efficiently
- **Algorithm optimization**: Discussions about improving the number of operations and edge case handling
- **Debugging assistance**: Help identifying logical errors in the sorting process

The core implementation, algorithm adaptation, and code structure were developed independently.

## Author

**sjdia** - 42 Student

---

*For questions or suggestions, feel free to reach out!*