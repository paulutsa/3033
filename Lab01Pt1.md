# Play with Processes on your Ubuntu VM: Lab 01 Part 1

- Turn in screenshots to show your work
- Use docx or pdf
- Turn in only ONE DOCUMENT with all of your screenshots and questions.

### 1. Set Up Ubuntu VM: (This part is your Lab 00 no need to resubmit)

- Download and install Hypervisor (VirtualBox or VMware)
- Download an Ubuntu Desktop ISO image from the official website.
- Create a new virtual machine and install Ubuntu using the ISO image (CD/DVD) as the installation source.


### 2. Open Terminal and List Running Processes 
- Launch the Terminal on your Ubuntu system
- Run the following command to list all running processes `ps aux`
- Screenshot
### 3. Understand Key Information displayed by the `ps` command
- PID (Process ID): Unique identifier for each process.
- %CPU: CPU usage as a percentage.
- %MEM: Memory usage as a percentage.
- VSZ: Virtual memory size in kilobytes.
- RSS: Resident Set Size (actual memory used) in kilobytes.
- TTY: Terminal associated with the process (e.g., pts/0).
- STAT: Process status (e.g., R for running, S for sleeping).
- START: Start time of the process.
- TIME: Total time the process has been running.
- COMMAND: Command or program associated with the process.

### 4. Demonstrate different ps command options to customize the output
- Use `ps -ef` to display a full listing with additional details.
- Use `ps -e --sort=-%cpu` to sort processes by CPU usage in descending order.
- Use `ps -u username` to show processes for a specific user (replace "username" with an actual username).
- Screenshot

### 5. Understand Process States and Process Management 
- Understand Process States (Running, Waiting, etc.) and their meanings.
- Manage processes using commands like `kill`, `killall`, and `pkill`.
- Demonstrate how to use these commands on their processes
- Screenshot
  
### 6. Process Prioritization and Process Scheduling
- Review the concept of process priority and scheduling policies (e.g., Round Robin, Priority Scheduling) in Linux.
- Show how to change process priority using `nice` and `renice` commands
- Use the top command to monitor and interact with the scheduler in real-time
- Screenshot 

### 7. Process-Related Files and Directories 
- Explore the `/proc` filesystem and its role in providing information about running processes.
- Navigate and extract useful information from `/proc`
- Screenshot

### 8. Create New Processes 
- Create new processes using the `&` operator, `nohup`, and `bg` commands.
- Screenshot  

