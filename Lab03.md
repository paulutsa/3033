#  ***Introduction to Sysinternals Tools for Malware Analysis: Lab 03***

`Objective:` Familiarize yourself with Sysinternals tools used for malware analysis and Windows administration. Practice using them with a simple software executable.

`Software Requirements:`

1. Windows 10 or 11 machine
1. Sysinternals Suite installed

`Lab Outline:`
- Introduction to Systernals
- Overview of the main tools: Process Explorer, Process Monitor, Autoruns, and TCPView.
- Creating and running a simple software executable.
- Analyzing the executable using Sysinternals tools
- Choose 3 other tools mentioned in Part 2 and screenshot your results.  


### **1. Introduction to the Sysinternals Suite**

Sysinternals Suite is a collection of system utilities and technical information related to Windows internals. It's especially valuable for system administrators, IT professionals, and malware analysts.

### **2. Overview of the Main Tools**


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

import socket
import os
import winreg as reg

def write_data_to_file():
    with open("sample_data.txt", "w") as file:
        file.write("This is a benign data sample.")

def establish_network_connection():
    server_ip = '8.8.8.8'  # Google's public DNS server (benign, for illustrative purposes)
    server_port = 53  # DNS port
    
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
        s.sendto(b'hello', (server_ip, server_port))
        s.recvfrom(1024)

def modify_registry():
    key_name = r"Software\Microsoft\Windows\CurrentVersion\Run"
    try:
        # Open the key in read-write mode
        reg_key = reg.OpenKey(reg.HKEY_CURRENT_USER, key_name, 0, reg.KEY_WRITE)
        reg.SetValueEx(reg_key, "BenignSample", 0, reg.REG_SZ, r"C:\Path\to\BenignSample.exe")
        reg.CloseKey(reg_key)
    except Exception as e:
        print(f"Failed to write to registry: {e}")

if __name__ == "__main__":
    write_data_to_file()
    establish_network_connection()
    modify_registry()

 
``` 
Save the above code as `malware_sample.py` then compile and run.  If you don't have a favorite compiler feel free to choose one of the options below.

`Option 1:` compile it using a tool like *PyInstaller* using the command below:

```pyinstaller --onefile malware_sample.py```

`Option 2: `
- Download Python:
  Go to the official Python website and download the latest version of Python for Windows.
- Install Python: Run the downloaded installer. Ensure that you check the box that says "Add Python X.Y to PATH" (where X.Y is the Python version number). This will add Python to your system's environment variables, allowing you to run Python from the Command Prompt.
- Create the Python Script:
Write the Script: Open a text editor (like Notepad) and paste the provided Python code into it.
Save the Script: Save the file with a .py extension, for example malware_sample.py.
- Run the Python Script:
Open Command Prompt: Press Windows + R, type cmd, and press Enter.
Navigate to the Script's Directory: Use the cd command to navigate to the directory where you saved the Python script. For example, if you saved it on the Desktop, you would type something like cd C:\Users\YourUsername\Desktop.
- Run the Script:
  Type python malware_sample.py and press Enter.
 
### **4. Analyzing the Executable using Sysinternals Tools**

a. `Using Process Explorer`

*Screenshot 1: Open Process Explorer.*

- Open Process Explorer and double-click on the malware_sample process in the list of running processes
- Under the Image tab, note the Parent (this indicates which process started the executable). 
- Move to the Threads tab to see the threads spawned by the process.

*Questions:*

- Which parent process launched malware_sample.exe?
- How many threads were created?

b. `Using Process Monitor`

*Screenshot 2: Set filters in Process Monitor.*

- Start Process Monitor.
- Set a filter to only show events related to `malware_sample.exe`.
- Run the `malware_sample.exe`
- Observe the file system, registry, and process activity.

*Questions:*

- What files did the executable access?
- Were any registry keys modified?

c. `Using Autoruns`

*Screenshot 3: Scanning with Autoruns.*

- Start Autoruns.
- Search for malware_sample.exe.
- Note if it's set to start during boot or login.

*Questions:*

- Did `malware_sample.exe` set itself to start at boot?

d. `Using TCPView`

*Screenshot 4: Network connections in TCPView.*

- Start TCPView.
- Run the `malware_sample.exe`.
- Observe any new network connections.

*Questions:*

- To which domain did malware_sample.exe establish a connection?
- On which port?

### **5. Choose 3 Tools from Part 2's overview of tools**
-provide screenshots

*Questions:*

- what tool did you choose and what does it do?
- how does this tool help in your observation?

### **6. Concisely answer the follownig questions (1-2 sentences)**
Note: There are no right or wrong answers.  This part is a thought exercise.  I will not grade these answers but I expect you to complete these questions to show you understood the assignment.

General Understanding:
- What are the three main actions this script attempts to perform (refer to the three main functions)
- Which libraries are imported to support the operations of this script?
- What protocol and port does the script use to communicate with the remote server?

File Operation (write_data_to_file):
- What's the name of the file that the script writes data to?
- Using ProcMon, can you identify the exact time when the file "sample_data.txt" was created or modified?
- If you were to track this activity using Sysinternals tools, which tool and filters would you use?

Network Communication (establish_network_connection):
- To which IP address does the script attempt to establish a connection?
- Why might the choice of the IP address and port be considered "benign" or non-malicious in this context?
- Using TCPView, were you able to observe the UDP connection initiated by this script? What details could you gather?

 
