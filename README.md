This repository contains a collection of C-based operating systems labs completed as part of an undergraduate OS course. The labs focus on low-level systems programming concepts including process control, threading, synchronization, inter-process communication, and memory management in a Unix-like environment.

## Topics Covered

### Process Management
- Creating and managing child processes using `fork()`
- Process synchronization with `wait()`
- Signal handling and process termination

### Threads & Concurrency
- Multithreading using POSIX threads (`pthread`)
- Mutexes and synchronization primitives
- Identifying and preventing race conditions

### Inter-Process Communication (IPC)
- Pipes for process communication
- Signal-based communication between processes
- Coordinating concurrent execution

### Shell & System Utilities
- Implementing basic shell-like functionality
- Command execution and process control
- File system interaction and I/O handling

### Memory & Debugging
- Pointer management and dynamic memory allocation
- Debugging segmentation faults and memory issues using `gdb`
- Understanding stack frames and control flow behavior

---

## Development Environment

- Language: C
- Compiler: GCC
- Debugging Tools: GDB
- Platform: Unix/Linux environment

---

## Purpose

These labs were designed to build a strong understanding of:

- How operating systems manage processes and threads  
- How synchronization primitives prevent race conditions  
- How low-level memory management works  
- How user programs interact with the OS kernel  

The emphasis was on understanding internal system behavior rather than using high-level abstractions.

---

## Notes

Each lab file contains detailed inline comments explaining implementation logic, system calls used, and concurrency behavior. The goal was clarity of reasoning and understanding of underlying OS mechanisms.

---

## How to Compile

Example:

```bash
gcc filename.c -o output
./output
