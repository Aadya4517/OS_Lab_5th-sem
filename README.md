# OS Lab Programs

C programs for Operating Systems practicals.

I have kept the programs separate and used basic C concepts like loops, arrays, functions, if-else and simple system calls.

## Folders

- `01_Process_Management` - fork, wait, parent-child, orphan and zombie processes
- `02_Process_Communication` - pipe, FIFO, message queue and shared memory
- `03_File_Handling` - reading and writing files
- `04_CPU_Scheduling` - FCFS, SJF and Priority
- `05_Page_Replacement` - FIFO and LRU

## Run

These programs use `fork()`, `wait()` and other POSIX functions. They work with GCC in a Linux-based online compiler.

You can edit the code in VS Code. But on Windows, the normal MinGW GCC compiler does not support `fork()` and `wait()`. To run those particular programs locally, a POSIX-compatible environment is needed.

Compile one program like this in a GCC environment:

```bash
gcc file.c -o output
./output
```

