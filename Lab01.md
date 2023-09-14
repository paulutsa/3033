<h1>Create a Buffer Overflow on your Ubuntu VM: Lab 01</h1>

- Turn in screenshots to show your work
- Use docx or pdf
- Turn in only one document

<h2>1. Set Up Ubuntu VM: (This part is your Lab 00)</h2>
- Download and install VirtualBox or VMware.
- Download an Ubuntu Desktop ISO image from the official website.
- Create a new virtual machine and install Ubuntu using the ISO image as the installation source.


<h2>2. Install Development Tools</h2>

- Open a terminal in your Ubuntu VM.
- Install build-essential and gdb for development and debugging tools.
```
sudo apt update
sudo apt install build-essential gdb
```


<h2>3. Create a Vulnerable C Program</h2>

- Create a simple C program with a buffer overflow vulnerability. 
- Type gpedit in the terminal window
- Paste the code below in the text file that pops up.  Check it twice.
- Save it as `vulnerable.c`


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

<h2>4. Compile the Vulnerable Program</h2>
```gcc -o vulnerable vulnerable.c -fno-stack-protector -m32```

<h2>5. Disable ASLR</h2>
```sudo sysctl -w kernel.randomize_va_space=0```

<h2>6. Test the Vulnerable Program</h2>
- Run the program with a long input to trigger the buffer overflow.
```./vulnerable $(python -c 'print("A" * 80)')```
- You should observe a segmentation fault due to the buffer overflow.

<h2>7. Set Up GDB for Debugging</h2>

-O pen the program in GDB for debugging.
```gdb -q ./vulnerable```

<h2>8. Debug the Vulnerable Program</h2>

- Set a breakpoint at the vulnerable function and run the program
- Break vulnerable_function
```run $(python -c 'print("A" * 80)')```
- You can now examine the stack and registers to understand how the buffer overflow occurred.

<h2>9. Cleanup</h2>

- After completing the lab, reset ASLR to its default value
```sudo sysctl -w kernel.randomize_va_space=2```


