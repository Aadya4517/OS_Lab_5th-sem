# Compile and Run

These programs use Linux system calls such as `fork()`, `wait()`, `pipe()`, and System V IPC. They are meant to be run on Linux (or a Linux virtual machine).

Compile a program from the repository folder:

```bash
gcc -Wall -Wextra path/to/file.c -o program
./program
```

For example:

```bash
gcc -Wall -Wextra 01_Process_Management/02_fork_parent_child.c -o fork_demo
./fork_demo
```

For two-program examples such as FIFO, message queue, and shared memory, compile both source files and follow the instructions in that folder's README.

The orphan and zombie examples are timing demonstrations. The exact PPID of an orphan depends on the Linux system's process reaper. For the zombie example, use the `ps` command printed by the program while the parent is sleeping.
