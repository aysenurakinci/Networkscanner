# Networkscanner


A simple **Network Scanner** program that uses ICMP (ping) requests to check the status of a given IP address. This program helps you check if a specific device or host in the network is reachable.

## Features
- Sends **ICMP Echo Requests** to a specified IP address (ping).
- Displays the round-trip time (RTT) for successful pings.
- Handles unreachable IP addresses gracefully.
- Written in **C** using **Windows API** (`IcmpSendEcho`).

## Requirements
- **Windows Operating System**
- **Visual Studio 2022** (or any C/C++ IDE with Windows SDK support)
- **Git** (for version control)
- **GitHub Account** (for sharing the project)

## Installation

### Clone the Repository
Clone the repository to your local machine using Git:
```bash
git clone https://github.com/aysenurakinci/Networkscanner.git

##Running the Program

**To use the program, simply run the executable from the terminal or Visual Studio's built-in terminal with an IP address argument:
- network_scanner.exe <IP_address>
If the ping request is successful, it will output the round-trip time (in milliseconds). If the host is unreachable, it will show an error message.

##Contribution
-Feel free to fork this project, make changes, and submit pull requests. If you find any bugs or have suggestions for improvements, please open an issue in the GitHub repository.
