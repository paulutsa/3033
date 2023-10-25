# Memory Management with GDB: Lab 02

- Turn in screenshots to show your work (You can show multiple steps with one screenshot)
- Use docx or pdf
- Turn in only one document

### 1. Compile and Run the Code
- `Objective:` This exercise helps you learn about memory management and how to fix memory-related problems using GDB (a debugging tool).
- Save your first program as `memory_management.c`
```c

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Memory Leak: Allocating memory but forgetting to free it
    char *memory_leak = (char *)malloc(10);
    
    // Uninitialized Variable: Using a variable before giving it a value
    int uninitialized_variable;
    printf("Uninitialized Variable: %d\n", uninitialized_variable);
    
    // Invalid Memory Access: Trying to use memory that doesn't belong to us
    int array[5];
    array[6] = 42;

    // To fix the memory leak, we should free the allocated memory
    free(memory_leak);
    
    return 0;
}
```
### 2.  Use GDB to Identify and Understand Memory Problems

- Compile the `memory_management.c `program with debugging symbols enabled. This will allow you to use GDB effectively.

`gcc -g -o memory_management memory_management.c`

- Open GDB by running the following command, specifying the name of the compiled program:

`gdb ./memory_management`

- Set a breakpoint at the beginning of the main function to pause program execution at that point:

`break main`

- Start running the program within GDB:

`run`

- When the program pauses at the breakpoint, use GDB to examine the memory leak issue. Check the value of the memory_leak variable to see if it's correctly allocated and freed:
 
`print memory_leak`
- You should see that `memory_leak` points to a memory address.

- Execute the program to step through the code using the `next` command in GDB. This allows you to see how the uninitialized variable and invalid memory access issues unfold:

`next`
- Keep using next to step through the code until you reach the uninitialized variable and invalid memory access sections.

- When you reach the uninitialized variable part, examine the uninitialized_variable:


`print uninitialized_variable`
- You'll notice that it contains garbage data since it hasn't been initialized.


- When you reach the invalid memory access part, use GDB to identify the issue. Inspect the array variable and how it's accessed:


`print array`
- You'll notice that the program is trying to access memory outside the bounds of the array.

- After analyzing the memory issues, exit GDB:

`quit`
### 3. Fix the Memory Issues

Now that you've identified the memory problems using GDB, you can go back to your code (memory_management.c) and fix them. To fix the issues:

- Free the allocated memory (free(memory_leak);) to resolve the memory leak.

- Locate the line where memory is allocated using malloc. In this case, it's the line where memory_leak is allocated:

`char *memory_leak = (char *)malloc(10);`
- After using the allocated memory, free it using the free function:

`free(memory_leak);`
- Initialize the uninitialized_variable Before Using it

- Find the line where uninitialized_variable is used:
`printf("Uninitialized Variable: %d\n", uninitialized_variable);`
- Initialize uninitialized_variable with a value before using it. For example, set it to 0:

`int uninitialized_variable = 0;`

- Ensure that array indices do not exceed the array's bounds.
- Locate the line where you access an array element outside of its bounds. In this case, it's the line where array[6] is accessed:

`array[6] = 42;`
- Ensure that the array index stays within the bounds of the array. If array has a size of 5, you should access elements from 0 to 4:

`array[4] = 42;` // Accessing the last element of a 5-element array
- Review the rest of your code to ensure that array indices are always within bounds to avoid undefined behavior.

- After making these changes, your modified code should look like this:
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Resolve Memory Leak: Free the allocated memory
    char *memory_leak = (char *)malloc(10);
    free(memory_leak);
    
    // Initialize uninitialized_variable before using it
    int uninitialized_variable = 0;
    printf("Initialized Variable: %d\n", uninitialized_variable);
    
    // Ensure Array Indices Do Not Exceed Bounds
    int array[5];
    array[4] = 42; // Accessing the last element of a 5-element array
    
    return 0;
}
```

  
- After making these changes, recompile the program and run it outside of GDB to verify that the issues have been resolved

`gcc -o memory_management_fixed memory_management.c`
- Run the program to check your work
  
`./memory_management_fixed`
- By following these steps, you've resolved the memory leak, initialized the variable properly, and ensured that array indices stay within bounds, making your code more reliable and free from memory-related issues.
- These steps will help you use GDB to identify and understand memory problems in your code, allowing you to fix them effectively.
