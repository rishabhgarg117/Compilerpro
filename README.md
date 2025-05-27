# EasyLang Compiler

A custom programming language compiler project for PBL (Project-Based Learning).

## Getting Started

### Compilation and Execution

To compile and run an EasyLang program:

```bash
# Compile the compiler
gcc main.c lexerf.c parserf.c codegeneratorf.c hashmap/hashmapoperators.c -o easy-lang

# Compile your EasyLang program (replace 'filename' with your desired output name)
./easy-lang examples/filename.el filename

# Run the compiled program
./filename
```

## About EasyLang

EasyLang is a simplified programming language designed for educational purposes. It features a clean, straightforward syntax while maintaining the power to express fundamental programming concepts.

### Language Features

#### Data Types
- Integer variables (`int`)
- String literals (for output)

#### Control Structures
- `if` statements for conditional execution
- `while` loops for iteration

#### Operators
- Arithmetic: `+`, `-`, `*`, `/`, `%` (modulo)
- Comparison: `eq` (equals), `neq` (not equals)

#### Built-in Functions
- `write(value, width)` - Prints a value with specified width
  - Example: `write("hello", 5)` or `write(variable, 2)`
- `exit(code)` - Terminates the program with the specified exit code
  - Example: `exit(0)`

### Syntax Examples

#### Variable Declaration and Assignment
```
int variable = 10;
variable = variable + 5;
```

#### Conditional Logic
```
if(value eq 10) {
  write("Equal to ten", 13);
}
```

#### Loops
```
int i = 0;
while(i neq 10) {
  write(i, 2);
  i = i + 1;
}
```

## Project Structure

- `main.c` - Main compiler entry point
- `lexerf.c/h` - Lexical analysis (tokenization)
- `parserf.c/h` - Syntax parsing and parse tree generation
- `codegeneratorf.c/h` - Assembly code generation
- `hashmap/` - Implementation of hashmap data structure
- `examples/` - Example EasyLang programs
- `build/` - Build artifacts

## Parse Tree Visualization

When compiling an EasyLang program, a parse tree visualization is automatically generated in a file named `[output_name]_parse_tree.txt`. This file shows the hierarchical structure of your program as interpreted by the compiler.

## Example Programs

### While Loop Example (examples/while.el)
```
int i = 0;
while(i neq 101){
  write(i, 2);
  i = i + 1;
}
exit(0);
```

### FizzBuzz Example (test.el)
```
int i = 1;
while(i neq 101){
  int remainderthree = i % 3;
  int remainderfive = i % 5;
  int remainderfifteen = i % 15;
  
  if(remainderfifteen eq 0){
    write("FIZZBUZZ", 9);
  }
  if(remainderfifteen neq 0){
    if(remainderthree eq 0){
      write("FIZZ", 5);
    }
    if(remainderfive eq 0){
      write("BUZZ", 5);
    }
  }
  if(remainderfive neq 0){
    if(remainderthree neq 0){
      write(i, 2);
    }
  }
  i = i + 1;
}
exit(0);
```

## Building Scripts

The project includes several build scripts:
- `build.sh` - Standard build script
- `buildasm.sh` - Builds and generates assembly
- `builddebugasm.sh` - Builds with debug information

## Copyrights

@Rishabh Garg, Shreya Arora, Nikhil Chaudhary
