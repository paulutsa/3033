#  ***Introduction to Sysinternals Tools for Process Analysis: Lab 03***

`Objective:` Familiarize yourself with Sysinternals tools used for malware analysis and Windows administration. Practice using them with a simple software executable.

`Software Requirements:`

1. Windows 10 or 11 machine
1. Sysinternals Suite installed

`Lab Outline:`
- Introduction to Systernals
- Overview of the main tools: Process Explorer, Process Monitor, Autoruns, and TCPView.
- Browser
- Analyzing the browser processes and behavior using Sysinternals tools
- Choose 3 other tools mentioned in Part 2 and screenshot your results.  


### **1. Introduction to the Sysinternals Suite**

Sysinternals Suite is a collection of system utilities and technical information related to Windows internals. It's especially valuable for system administrators, IT professionals, and malware analysts.

### 2. Overview of the Main Tools


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

### **3. Download and install the Chrome browser**

-   https://www.google.com/chrome/ download chrome.exe and run it
-   if its already installed just click on the icon and close out other applications.  
-   ctrl alt del to task manager to make sure no "extra" programs aren't running so you can distiunguish your processes
-   open up your chrome to one browser tab with https://google.com
-   observe and document with each tool
-   open up a second tab with a more "process heavy" website like Microsoft office or Canvas
-   observe what is added and some differences and document it with each tool
-   answer the questions based on your observations with Chrome
 
 
### **4. Analyzing the Executable using Sysinternals Tools**

a. `Using Process Explorer`

*Screenshot 1: Open Process Explorer*

- Open Process Explorer and click on the chrome process in the list of running processes
- Under the Image tab, note the Parent (this indicates which process started the executable). 
- Move to the Threads tab to see the threads spawned by the process.

Questions:

- Which parent process was launched ?
- How many threads were created?

b. `Using Process Monitor`

*Screenshot 2: Set filters in Process Monitor.*

- Start Process Monitor.
- Set a filter to only show events related to chrome
- Observe the file system, registry, and process activity.


c. `Using Autoruns`

*Screenshot 3: Scanning with Autoruns.*

- Start Autoruns.
- Search for malware_sample.exe.
- Note if it's set to start during boot or login.

Questions:

- Did chrome set itself to start at boot?

d. `Using TCPView`

*Screenshot 4: Network connections in TCPView.*

- Start TCPView.
- Observe any new network connections.

Questions:

- To which domain did chrome establish a connection?
- On which port?

### 5. Choose 3 Tools from Part 2's overview of tools 
*Screenshot 5,6,7: Screenshot the 3 Tools running*

Questions:

- what tool did you choose and what does it do?
- how does this tool help in your observation?

### 6. Concisely answer the following questions (1-2 sentences) 
Note: There are no right or wrong answers.  This part is a thought exercise.  I will not grade these answers but I expect you to complete these questions to show you understood the assignment.

General Understanding:
 
- Which libraries are imported to support the operations of Chrome?
- What protocol and port does the script use to communicate with the remote server?

 
Network Communication (establish_network_connection):
- To which IP address does Chrome  establish a connection?
- Using TCPView, were you able to observe a UDP connection initiated by chrome? What details could you gather?

 
