#  ***Introduction to Sysinternals Tools for Malware Analysis: Lab 03***

`Objective:` Familiarize yourself with Sysinternals tools used for malware analysis and Windows administration. Practice using them with a simple software executable.

`Software Requirements:`

1. Windows 10 or 11 machine
1. Sysinternals Suite installed

`Lab Outline:`
- Introduction to Systernals
- Overview of the main tools: Process Explorer, Process Monitor, Autoruns, and TCPView.
- Creating and running a simple software executable.
- Analyzing the executable using Sysinternals tools Part 1
- Analyzing the executable using Sysinternals tools Part 2

### **1. Introduction to the Sysinternals Suite**

Sysinternals Suite is a collection of system utilities and technical information related to Windows internals. It's especially valuable for system administrators, IT professionals, and malware analysts.

### **2. Overview of the Main Tools**

*Screenshot 1: Show tht you have it installed.*

a. `Process Explorer`
Shows a detailed view of all processes running on the system. It's like the Task Manager but with more in-depth details.

b.`Process Monitor`
Monitors real-time file system, registry, and process/thread activity.

c.`Autoruns`
Shows what programs are configured to startup during boot or login.

d. `TCPView`
Displays all active TCP and UDP endpoints, revealing which processes are making network connections.

e. `VMMap`
This tool shows a breakdown of a process's committed virtual memory types. It's useful for understanding the memory footprint of an application.

f.`Sigcheck`
Sigcheck is a command-line utility that shows file version number, timestamp information, and digital signature details, including certificate chains.

g.`LiveKd`
This utility allows you to start any of the supported kernel-mode debuggers on a live system. It's a way to inspect the system's memory and kernel without halting the system.

h.`Procdump`
Procdump is a command-line utility that monitors processes for CPU spikes and generates crash dumps. It's an advanced tool for procuring comprehensive memory dumps.

i. `AccessChk`
This tool reports the effective permissions on files, registry keys, processes, etc. It's useful for understanding what operations can be performed on specific objects by different users.

### **3. Creating and Running a Simple Software Executable**

For this lab, we will create a basic program that spawns multiple processes and establishes a network connection. Copy and compile the following Python code:


```python

import subprocess
import socket

def create_processes():
    for _ in range(5):
        subprocess.Popen(["notepad.exe"])

def establish_connection():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect(("example.com", 80))
    s.close()

if __name__ == "__main__":
    create_processes()
    establish_connection()
 
``` 


Save the above code as `malware_sample.py` and compile it using a tool like *PyInstaller* using the command below:
_Note: if you have other compilers that you prefer, that is fine_

```pyinstaller --onefile malware_sample.py```

*Screenshot 2: Show the compiled executable from your favorite compiler, IDE, etc. *

### **4. Analyzing the Executable using Sysinternals Tools**

a. `Using Process Explorer`

*Screenshot 3: Open Process Explorer.*

- Double-click on the `malware_sample.exe process`.
- Under the Image tab, note the Parent (this indicates which process started the executable). 
- Move to the Threads tab to see the threads spawned by the process.

*Questions:*

- Which parent process launched malware\_sample.exe?
- How many threads were created?

b. `Using Process Monitor`

*Screenshot 4: Set filters in Process Monitor.*

- Start Process Monitor.
- Set a filter to only show events related to `malware_sample.exe`.
- Run the `malware_sample.exe`
- Observe the file system, registry, and process activity.

*Questions:*

- What files did the executable access?
- Were any registry keys modified?

c. `Using Autoruns`

*Screenshot 5: Scanning with Autoruns.*

- Start Autoruns.
- Search for malware\_sample.exe.
- Note if it's set to start during boot or login.

*Questions:*

- Did `malware_sample.exe` set itself to start at boot?

d. `Using TCPView`

*Screenshot 6: Network connections in TCPView.*

- Start TCPView.
- Run the `malware_sample.exe`.
- Observe any new network connections.

*Questions:*

- To which domain did malware\_sample.exe establish a connection?
- On which port?

 ###  **4. Analysis of the Executable using Sysinternals Tools Part 2**


e. `Using VMMap`

*Screenshot 7: Analyzing malware\_sample.exe with VMMap.*

- Start VMMap and open `malware_sample.exe`. 
- Examine the different types of memory allocated by the process.

*Questions:*

- How much private memory has the executable reserved?
- Are there any noticeable memory-mapped files?

f. `Using Sigcheck`

*Screenshot 8: Running Sigcheck on `malware_sample.exe`

 - Open Command Prompt and navigate to the directory containing `malware_sample.exe`. 
 - Run sigcheck `malware_sample.exe`.
 - Observe the details provided.

*Questions:*

- Is malware\_sample.exe digitally signed?
- If signed, who is the signer?

g. `Using LiveKd`

*Screenshot 9: Running LiveKd.*

 
- Launch LiveKd.
- Initiate a debugging session and inspect the kernel's current state.

*Questions:*

- Can you identify any active system processes?
- What is the state of the memory?

h.`Using Procdump`

*Screenshot 10: Generating a memory dump of malware\_sample.exe.*

i. Run `procdump -ma malware_sample.exe`. ii. This will generate a full memory dump of the process.

*Questions:*

- What is the size of the generated memory dump?
- Can you identify any strings or sections within the dump?

i. `Using AccessChk`

*Screenshot 11: Checking permissions with AccessChk.*

 - In the Command Prompt, run `accesschk -p malware_sample.exe` 
 - Observe the permissions of different users for the executable.

*Questions:*

- Which users/groups have read permissions for `malware_sample.exe`?
- Are there any unusual permission assignments?
