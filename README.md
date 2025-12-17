# Push_Swap

## Description

**Push_swap** is a C program that sorts a stack of integers using a very limited set of allowed operations. The goal is to sort the numbers in ascending order while using as **few operations as possible**.

Only specific stack operations are allowed, which makes the project more about **algorithm efficiency and optimization** than simple sorting.

The project uses two stacks:
- **Stack a**: starts with all the numbers  
- **Stack b**: starts empty and is used as auxiliary storage

## Allowed Operations

| Operation | Description |
|---------|-------------|
| `sa` | Swap the first two elements of stack `a` |
| `sb` | Swap the first two elements of stack `b` |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push the top element from stack `b` to stack `a` |
| `pb` | Push the top element from stack `a` to stack `b` |
| `ra` | Rotate stack `a` upwards |
| `rb` | Rotate stack `b` upwards |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack `a` |
| `rrb` | Reverse rotate stack `b` |
| `rrr` | `rra` and `rrb` at the same time |

Sorting must be done **only using these operations**, while minimizing the total number of operations.

## Algorithm

This implementation uses the **Turk algorithm** combined with **quick sort** principles to efficiently sort the stack with minimal operations.

## Performance

### Project Goals
- Sort **100 numbers** in fewer than **700 operations**  
- Sort **500 numbers** in fewer than **5500 operations**

### Project Results
Average results for this implementation:
- **100 numbers**: ~**593 operations** on average
- **500 numbers**: ~**4773 operations** on average

## Compilation

### push_swap
Run:
```bash
make
```

## Usage

Run the program with numbers as arguments, for example:
```bash
./push_swap 1 2 4 3
```

Example output:
```
pb
rra
sa
pa
```

Each line represents an operation applied to the stacks.

### Counting Operations

To see how many operations are used:
```bash
./push_swap 1 2 4 3 | wc -l
```

## Error Handling

The program displays "Error" for invalid input:
```bash
# Non-integer argument
./push_swap 1 2 three
Error

# Duplicate numbers
./push_swap 1 2 2 3
Error

# Number outside integer range
./push_swap 1 2 2147483648
Error
```

## Checker

The `checker` program is a bonus tool used to verify whether a list of operations correctly sorts the stack.

### Compilation
Run:
```bash
make bonus
```

This will compile the `checker` executable.

### How it works

The checker:
1. Takes the initial stack as arguments  
2. Reads operations from standard input, one per line  
3. Executes them on the stacks  
4. Checks if stack `a` is sorted and stack `b` is empty  

After entering all operations, press **Ctrl + D** to display the result.

### Example

Run the checker:
```bash
./checker 1 2 4 3
```

Then enter the operations one per line:
```
pb
rra
sa
pa
```

Press **Ctrl + D** to see the result:
```
OK
```

### Using checker with push_swap

You can also pipe the output of `push_swap` directly into `checker`:
```bash
./push_swap 1 2 4 3 | ./checker 1 2 4 3
```

Both programs must receive the **exact same arguments** for the result to be valid.
