# OS Lab Programs

Simple C programs for Operating Systems practicals.

The programs use basic concepts like loops, arrays, functions, `fork()`, `wait()` and IPC system calls.

## Folders

- `01_Process_Management` - fork, wait, parent-child, orphan and zombie processes
- `02_Process_Communication` - pipe, FIFO, message queue, shared memory and permutations
- `03_File_Handling` - file reading and writing using processes
- `04_CPU_Scheduling` - FCFS, SJF and Priority
- `05_Page_Replacement` - FIFO and LRU

## Important

The process and IPC programs use Linux/POSIX functions. Run them using a Linux-based GCC compiler or an online compiler that allows process creation and IPC. A restricted online compiler may block `fork()` or IPC calls even if GCC is available.

See [QUESTIONS.md](QUESTIONS.md) for the practical checklist.
