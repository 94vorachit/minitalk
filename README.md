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

## Mandatory
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
## Bonus
* The server must acknowledge each received message by sending a signal to the client.
* Unicode characters support.

# `Instrctions`
## Usage
1. Compile the source code using the provided Makefile:
```bash
make (or make bonus)
```
* This will generate two executables: `client` and `server`

2. Launch the server by executing the `server` binary:
```bash
./server (or ./server_bonus)
```
* The server will display its process ID (PID) on the console.

Example:
```bash
PID: 12345
```
3. In a separate terminal window, launch the client by executing the client binary with the server's PID and the message you want to transmit:
```bash
./client <server_pid> <message> (or ./client_bonus <server_pid> <message>)
```
* Replace `<server_pid>` with the PID displayed by the server, and `<message>` with the text you want to send.

Example:
```bash
./client 12345 Hello
```
* This will send the message "Hello" to the server with the PID 12345.

4. The server will receive the message and display it on the console:

```bash
PID: 12345
Hello
```
* The server will display each character as it receives them.

## Bonus Features

The provided source code includes a bonus version (`client_bonus.c` and `server_bonus.c`) that adds additional functionality:

* Unicode characters like 🦁 are already supported in the mandatory part.
* Sending back a read receipt can be achieved by using the `sigaction` structure, that allows to access metadata about signal transmission.
   * The client displays a message on the console for each bit it sends. It prints "Received bit 1" for `SIGUSR1` and "Received bit 0" for `SIGUSR2`. This can help visualize the communication process.
   * The server sends an acknowledgment signal back to the client after receiving each bit. If the received signal was `SIGUSR1`, it sends `SIGUSR1` to the client. If the received signal was `SIGUSR2`, it sends `SIGUSR2`. This allows the client to know that the server has successfully received the bit.
These additional features enhance the interactivity and feedback during the communication process.


# `Resources`

* Minitalk 42 project : [Guide](https://medium.com/@gamerazer007/minitalk-42-project-guide-be45d74f8dfa)
* [Bitwise](https://youtu.be/c3sRgaH2zGA?si=4c73S0PDtVgi7qG_)
* [Signal](https://www.youtube.com/watch?v=m6WXrC9Mxzo)
* [Kill](https://www.youtube.com/watch?v=qXP4F49K1XM)
* [sigaction](https://youtu.be/83M5-NPDeWs?si=Pe0HyCuDJpIxLbjg)
* Github : [leogaudin](https://github.com/leogaudin/minitalk.git)

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

## Functions Explained

### getpid()
Returns the calling process's process ID (PID).

### usleep()
Suspends the calling thread for approximately usec microseconds.

### kill()
`kill(server_pid, 0)` does not deliver a signal — it performs a check: it tests whether a process with PID server_pid exists and whether the caller has permission to send signals to it.

`kill(pid, SIGUSR1 or 2)` sends the SIGUSR1 or 2 signal to the process with PID pid (i.e., requests the kernel deliver SIGUSR1 or 2 to that process).

`kill(info->si_pid, SIGUSR1)` sends the SIGUSR1 signal to the process whose PID is info->si_pid (the sender of the signal received by the server). In handle_signal() this acts as an acknowledgement back to the client.

* Return value: returns 0 on success (process exists and permission ok), returns -1 on error and sets errno.

### signal()
`signal(SIGUSR1, ack)` installs ack as the process's handler for the SIGUSR1 signal — when the process receives SIGUSR1 the kernel will call ack(signal_number).
* Parameters: first arg is the signal (SIGUSR1), second is a pointer to the handler function (ack). The handler must have signature void handler(int).
* Return / errors: signal() returns the previous handler on success, or SIG_ERR on error (and sets errno).
* when the server sends SIGUSR1 the ack function runs and sets g_status = 1 (and in the bonus version also prints). The client waits on that flag to know a bit was acknowledged.

Safety & portability:

`signal()` semantics differ historically; prefer `sigaction()` for reliable, portable behavior and flags like SA_RESTART.
A signal handler must only call async-signal-safe functions.use `write()` or just set a `volatile sig_atomic_t` flag and do printing from the main context.

### sigaction()
`sigaction()` installs a signal handler with full control (flags, mask, and optional siginfo).
* Key fields in struct sigaction:
	* `a_handler` — pointer to a void (*)(int) handler
	* `sa_sigaction` — pointer to a void (*)(int, siginfo_t *, void *) handler (3-arg form).
	* `sa_mask` — sigset_t of signals to block while the handler runs (init with sigemptyset/sigaddset).
	* `sa_flags` — behavior flags (SA_SIGINFO to enable sa_sigaction, SA_RESTART, SA_RESETHAND, SA_NODEFER, etc.).

* `sa.sa_sigaction = &handle_signal` — assigns the handler function to the `sa_sigaction` field (the 3-arg form). This is the function the kernel will call when the signal arrives.
* `sa.sa_flags = SA_SIGINFO` — tells `sigaction()` to:
	* use `sa.sa_sigaction` (not sa_handler) and
	* provide a `siginfo_t *` and `void * context` to the handler so you can inspect `info->si_pid`.

### sigemptyset()
`sigemptyset(&sa.sa_mask)`  initializes `sa.sa_mask` to an empty set so no extra signals are blocked while the handler runs.

* `sa.sa_mask` lists signals to block while the handler runs; calling `sigemptyset` ensures it starts from a known empty state before optionally adding signals (via `sigaddset`) or passing `sa` to `sigaction`.

	* (Can add signals with sigaddset if you need them blocked during the handler.)
```
summary :
* struct sigaction is used for better signal handling.
* sa_sigaction = signal_handler; → Assigns a handler that gets extra info.
* sa_flags = SA_SIGINFO; → Enables sa_sigaction.
* sigemptyset(&sa.sa_mask); → No signals are blocked while handling.
```
### `send_signal` (client)
```C
void	send_signal(int pid, unsigned char character)
```
* Purpose: send one byte to pid by transmitting its 8 bits as signals (MSB first).
* Bit loop: use bitwise and ship bit. so bit 7 is sent first, down to bit 0.
* Signals used: sends `SIGUSR1` for bit=1 and `SIGUSR2` for bit=0 (via `kill(pid, ...)`).
* Ack/wait: before each send it clears `g_status = 0`, sends the signal, then busy-waits `while (g_status != 1) usleep(200);` until the signal handler sets `g_status` (ack from server).
* Return semantics: returns 1 on success; returns 0 immediately if kill() fails (so caller can abort).

### `handle_signal` (server)
```C
void	handle_signal(int signal, siginfo_t *info, void *context)
```
* `signal` — the signal number delivered (e.g. `SIGUSR1` or `SIGUSR2`).
* `info` — pointer to `siginfo_t` (only valid when handler installed with `SA_SIGINFO`); `info->si_pid` is the sender’s PID (used here to ACK the client).
* `context` — pointer to a `ucontext_t`-like structure with CPU/register state (rarely needed; the code discards it).

#### How this handler works:

* treats `SIGUSR1` as bit=1 and `SIGUSR2` as bit=0.
* `current_char |= (signal == SIGUSR1)` sets the low bit according to the signal.
* `bit_index++` counts bits; if not the 8th bit it does `current_char <<= 1` to make room for the next bit (MSB-first assembly).
* When 8 bits collected, it writes the completed character (or newline on `'\0'`) and resets `current_char/bit_index`.
* It sends an acknowledgement back to the sender with `kill(info->si_pid, SIGUSR1)`.

## Minitalk-Tester

### Installation

```
git clone https://github.com/ThibaudM13/minitalk-Tester.git
```

### Preparation and execution

```sh
## 1. Edit the value of PATH_TO_CLIENT with your own client's path
## 2. Make your client and server program
## 3. Launch your server
## 4. Execute this script as below (By default the script launch the speed test on 1000 char)

./tester.sh <your server PID> [options]

Options:
  -m      Mandatory part
  -b      Execution of bonus part (All unicode)
  -[0-6]  Execution of special tests
```