*This Project Has Been Created As Part Of The 42 Curriculum By **Vorhansa***

# `Description`
Minitalk is project about how to make process send message to each other by use UNIX signal (SIGUSR1 and SIGUSR2).
* SIGUSR1 represents bit 1.
* SIGUSR2 represents bit 0.
## UNIX SIGNALS :
UNIX signals are a way for processes to communicate or handle events asynchronously. They act like software interrupts, notifying a process that an event has occurred. A process is an instance of a running program on a computer.
When you run a program, the operating system creates a process that executes the program’s code. (and it’s allocated in RAM ), the process have a PROCESS ID that is uniq for each process , and the process can use files ,sockets ect . there is several types of process like (interactive process and daemon process (process that runs in the background without user interation)).

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

### Mandatory
Create a communication program in the form of a client and a server.
* The server must be started first. Upon launch, it must print its PID.
* The client takes two parameters:
	* The server PID.
	* The string to send.
* The client must send the specified string to the server.
Once received, the server must print it.
* The server must display the string without delay. If it seems slow, it is likely too slow.
* Your server should be able to receive strings from several clients in a row without needing to restart.
* Communication between the client and server must exclusively use UNIX signals
### Bonus
* The server must acknowledge each received message by sending a signal to the client.
* Unicode characters support.

# `Instrctions`

# `Resources`

* Minitalk 42 project : [Guide](https://medium.com/@gamerazer007/minitalk-42-project-guide-be45d74f8dfa)
* [Bitwise](https://youtu.be/c3sRgaH2zGA?si=4c73S0PDtVgi7qG_)
* [Signal](https://www.youtube.com/watch?v=m6WXrC9Mxzo)

# `Additional`

* LIBFT
* ft_printf

### AI Usage
GitHub Copilot (GPT-5 mini backend) is used for
* Is used to analyze other's people code sample, comprehend the code logic.
* Is used to help with debugging where logic errors occured.
* Discussed about logic, but is not usable enough.
* Used for finding information about micro-optimization, techniques, coding convention.
	* Circular stack implementation, what's the best practice to implement.
