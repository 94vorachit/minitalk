*This Project Has Been Created As Part Of The 42 Curriculum By **Vorhansa***

# `Description`
Minitalk is project about how to make process send message to each other by use UNIX signal (SIGUSR1 and SIGUSR2).
* SIGUSR1 represents bit 1.
* SIGUSR2 represents bit 0.
## UNIX SIGNALS :
UNIX signals are a way for processes to communicate or handle events asynchronously. They act like software interrupts, notifying a process that an event has occurred. A process is an instance of a running program on a computer.
When you run a program, the operating system creates a process that executes the program’s code. (and it’s allocated in RAM ), the process have a PROCESS ID that is uniq for each process , and the process can use files ,sockets ect . there is several types of process like (interactive process and daemon process (process that runs in the background without user interation)).


### Mandatory


### Bonus

# `Instrctions`

### `Stack`

### `Initialize`

# `Resources`

# `Additional`

* LIBFT

### AI Usage
GitHub Copilot (GPT-5 mini backend) is used for
* Is used to analyze other's people code sample, comprehend the code logic.
* Is used to help with debugging where logic errors occured.
* Discussed about logic, but is not usable enough.
* Used for finding information about micro-optimization, techniques, coding convention.
	* Circular stack implementation, what's the best practice to implement.


The problem was the client’s wait loop. pause() can miss the ACK if the server responds before the client enters the sleep, so the message send can hang or behave unpredictably. I fixed that in client.c by blocking SIGUSR1 and waiting with sigsuspend(), which makes the ACK handshake atomic.

