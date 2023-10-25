  ***Introduction to Sysinternals Tools for Malware Analysis: Lab 03***

**Objective:** Familiarize yourself with Sysinternals tools used for malware analysis and Windows administration. Practice using them with a simple software executable.

**Software Requirements:**

1. Windows 10 or 11 machine
1. Sysinternals Suite installed

**Lab Outline:**

1. Introduction to the Sysinternals Suite
1. Overview of the main tools: Process Explorer, Process Monitor, Autoruns, and TCPView.
1. Creating and running a simple software executable.
1. Analyzing the executable using Sysinternals tools.

**1. Introduction to the Sysinternals Suite**

Sysinternals Suite is a collection of system utilities and technical information related to Windows internals. It's especially valuable for system administrators, IT professionals, and malware analysts.

**2. Overview of the Main Tools**

*Screenshot 1: Display icons and main interfaces of each tool.*

a. **Process Explorer**
Shows a detailed view of all processes running on the system. It's like the Task Manager but with more in-depth details.

b. **Process Monitor**
Monitors real-time file system, registry, and process/thread activity.

c. **Autoruns**
Shows what programs are configured to startup during boot or login.

d. **TCPView**
Displays all active TCP and UDP endpoints, revealing which processes are making network connections.

**3. Creating and Running a Simple Software Executable**

For this lab, we will create a basic program that spawns multiple processes and establishes a network connection. Copy and compile the following Python code:

pythonCopy code

``
import subprocess

import socket

def create\_processes():

`    `for \_ in range(5):

`        `subprocess.Popen(["notepad.exe"])

def establish\_connection():

`    `s = socket.socket(socket.AF\_INET, socket.SOCK\_STREAM)

`    `s.connect(("example.com", 80))

`    `s.close()

if \_\_name\_\_ == "\_\_main\_\_":

`    `create\_processes()

`    `establish\_connection()
``

Save the above code as malware\_sample.py and compile it using a tool like PyInstaller:

cssCopy code

pyinstaller --onefile malware\_sample.py

*Screenshot 2: Show the compiled executable.*

**4. Analyzing the Executable using Sysinternals Tools**

a. **Using Process Explorer**

*Screenshot 3: Open Process Explorer.*

i. Double-click on the malware\_sample.exe process. ii. Under the Image tab, note the Parent (this indicates which process started the executable). iii. Move to the Threads tab to see the threads spawned by the process.

*Questions:*

- Which parent process launched malware\_sample.exe?
- How many threads were created?

b. **Using Process Monitor**

*Screenshot 4: Set filters in Process Monitor.*

i. Start Process Monitor. ii. Set a filter to only show events related to malware\_sample.exe. iii. Run the malware\_sample.exe. iv. Observe the file system, registry, and process activity.

*Questions:*

- What files did the executable access?
- Were any registry keys modified?

c. **Using Autoruns**

*Screenshot 5: Scanning with Autoruns.*

i. Start Autoruns. ii. Search for malware\_sample.exe. iii. Note if it's set to start during boot or login.

*Questions:*

- Did malware\_sample.exe set itself to start at boot?

d. **Using TCPView**

*Screenshot 6: Network connections in TCPView.*

i. Start TCPView. ii. Run the malware\_sample.exe. iii. Observe any new network connections.

*Questions:*

- To which domain did malware\_sample.exe establish a connection?
- On which port?

Upon completion, the student should have a basic understanding of the Sysinternals tools used for malware analysis.


**


** 
\*


e. **VMMap**
This tool shows a breakdown of a process's committed virtual memory types. It's useful for understanding the memory footprint of an application.

f. **Sigcheck**
Sigcheck is a command-line utility that shows file version number, timestamp information, and digital signature details, including certificate chains.

g. **LiveKd**
This utility allows you to start any of the supported kernel-mode debuggers on a live system. It's a way to inspect the system's memory and kernel without halting the system.

h. **Procdump**
Procdump is a command-line utility that monitors processes for CPU spikes and generates crash dumps. It's an advanced tool for procuring comprehensive memory dumps.

i. **AccessChk**
This tool reports the effective permissions on files, registry keys, processes, etc. It's useful for understanding what operations can be performed on specific objects by different users.

**4. Extended Analysis of the Executable using Sysinternals Tools**

e. **Using VMMap**

*Screenshot 7: Analyzing malware\_sample.exe with VMMap.*

i. Start VMMap and open malware\_sample.exe. ii. Examine the different types of memory allocated by the process.

*Questions:*

- How much private memory has the executable reserved?
- Are there any noticeable memory-mapped files?

f. **Using Sigcheck**

*Screenshot 8: Running Sigcheck on malware\_sample.exe.*

i. Open Command Prompt and navigate to the directory containing malware\_sample.exe. ii. Run sigcheck malware\_sample.exe. iii. Observe the details provided.

*Questions:*

- Is malware\_sample.exe digitally signed?
- If signed, who is the signer?

g. **Using LiveKd**

*Screenshot 9: Running LiveKd.*

i. Launch LiveKd. ii. Initiate a debugging session and inspect the kernel's current state.

*Questions:*

- Can you identify any active system processes?
- What is the state of the memory?

h. **Using Procdump**

*Screenshot 10: Generating a memory dump of malware\_sample.exe.*

i. Run procdump -ma malware\_sample.exe. ii. This will generate a full memory dump of the process.

*Questions:*

- What is the size of the generated memory dump?
- Can you identify any strings or sections within the dump?

i. **Using AccessChk**

*Screenshot 11: Checking permissions with AccessChk.*

i. In the Command Prompt, run accesschk -p malware\_sample.exe. ii. Observe the permissions of different users for the executable.

*Questions:*

- Which users/groups have read permissions for malware\_sample.exe?
- Are there any unusual permission assignments?
