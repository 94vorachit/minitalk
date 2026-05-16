This project has been created as part of the 42 curriculum by **naratass**

### Description
Minitalk is project about how to make process send message to each other by use UNIX signal
### **Concept**
- Signal in C
- BITWISE Operation
- Unicode
- UTF-8

### Project instructions
- Name your executable files **client** and **server**.
- You must submit a Makefile that compiles your source files. It must not perform unnecessary relinking.
- Program must handle errors thoroughly. And not quite unexpectedly (segmentation fault, bus error, double free, and so forth)
- program must be free of **memory leaks**.

### Allowed function
- write()
- ft_printf()
- signal()
- sigemptyset()
- sigaddset()
- sigaction()
- kill()
- getpid()
- malloc()
- free()
- pause()
- sleep()
- usleep()
- exit()

### Mandatory Part
- The server must be started first and print its PID.
- The client take two parameter: `The server PID` and `The string to send`.
- The client must send specified string to server. Once received, the server must print it.
- The server must print string without delay.
- Server should be able to receive strings from several clients without needing to restart.
- Communication must exclusively use UNIX signals only.
- Can only use these two signals: `SIGUSR1` and `SIGUSR2`.
[[42Project/minitalk/Note]]

### How to send text
I will use `SIGUSR1` to represent `1` and `SIGUSR2` to represent `0`. Now, there's a plenty of encoding format to use such as ACSII, Unicode and UTF-8. This encoding format will change out text into binary code that contain `0` and `1`. We can use this advantage to adapt this into our project.

**💡Solution key**: Find the way to convert text into binary
### Solution
I use bitwise operation to convert each charater into binary then send it with signal `SIGUSR1` or `SIGUSR2`

### Bonus Part
- The server must acknowledge each received message by sending a signal to the client.
- Unicode characters support

### Instruction

#### Compilation
```bash
make         # build the minitalk binary
make clean   # remove object files
make fclean  # remove object files and binary
make re      # full rebuild
make bonus   # build the minitalk binary bonus part
```

#### Execution
1. Start server, then server will show PID
```bash
./server
```
```bash
PID: xxxxx
```
2. Run client with format `./client <pid> <text>`
```bash
./client xxxxx "Hello"
```
##### Server output
```bash
./server
PID: xxxxx
Hello
```

#### Bonus part command
```bash
./server // Run server binary file
./client <pid> <text> // Run client bianary file
```

#### Example
##### Mandatory
**Server**
```bash
./server
PID: 89034
Hello Minitalk 
```
**Client**
```bash
./client 89034 "Hello Minitalk"
```

#### Bonus
**Server**
```bash
./server
PID: 54522
😭
```
**Client**
```bash
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
SEND SUCCESS
```

### Resource
#### Github repo reference
- https://github.com/bababxxm/minitalk
- https://github.com/leogaudin/minitalk/tree/main
#### Another source
- Convert to binary with bitwise: https://youtu.be/c3sRgaH2zGA?si=4c73S0PDtVgi7qG_
- What is signal?: https://www.youtube.com/watch?v=m6WXrC9Mxzo

AI(Gemini) was used only for research topic and teaching about concept.