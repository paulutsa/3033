# Create a Buffer Overflow on your Ubuntu VM: Lab 01

- Turn in screenshots to show your work
- Use docx or pdf
- Turn in only one document

### 1. Set Up Ubuntu VM: (This part is your Lab 00)

- Download and install Hypervisor (VirtualBox or VMware)
- Download an Ubuntu Desktop ISO image from the official website.
- Create a new virtual machine and install Ubuntu using the ISO image (CD/DVD) as the installation source.


### 2. Install Development Tools 

- Open a terminal in your Ubuntu VM.
- Install build-essential and gdb for development and debugging tools.
- Install multilib so you can compile your program as 32-bit
- You will run it as 32-bit to ensure the vulnerability works

```
sudo apt update
sudo apt install build-essential gdb
sudo apt-get install gcc-multilib
```


### 3. Create a Vulnerable C Program

- Create a simple C program with a buffer overflow vulnerability. 
- Type gpedit in the terminal window
- Paste the code below in the text file that pops up.  Check it twice.
- Save it as
  `vulnerable.c`


```c
#include <stdio.h>
#include <string.h>

void vulnerable_function(char *input) {
    char buffer[64];
    strcpy(buffer, input);
    printf("Buffer: %s\n", buffer);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }
    vulnerable_function(argv[1]);
    return 0;
}
```

### 4. Compile the Vulnerable Program 

```
gcc -o vulnerable.c -m32 vulnerable
```

### 5. Disable ASLR 
-Disable ASLR which is a Microsoft feature that prevents buffer overflows by randomly moving data to different places in memory.  This makes it more unpredictable for the malware writers to know where to send the malicious code.

```
sudo sysctl -w kernel.randomize_va_space=0
```

### 6. Test the Vulnerable Program 

- Run the program with a long input to trigger the buffer overflow.
```
./vulnerable $(python -c 'print("A" * 80)')
```
- You should observe a segmentation fault due to the buffer overflow (This means that if your program crashes, you did it right!).
- In the next step, we will begin inspecting our code by stepping through it line by line with GDB
- GDB will help us see exactly where the program crashed in the buffer overflow!

### 7. Set Up GDB for Debugging 

- Open the program in GDB for debugging.

```
gdb -q ./vulnerable
```

### 8. Debug the Vulnerable Program 

- Set a breakpoint at the vulnerable function and run the program
- Break vulnerable_function

```
run $(python -c 'print("A" * 80)')
```
- You can now examine the stack and registers to understand how the buffer overflow occurred (These stacks and registers will be the parts of your virtual memory with memory addresses!)

### 9. Cleanup 

- After completing the lab, reset ASLR to its default value (if you don't do this, your VM will be vulnerable to common attacks!)

```
sudo sysctl -w kernel.randomize_va_space=2
```


