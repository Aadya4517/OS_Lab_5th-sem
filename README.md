# Operating Systems Lab - 5th Semester

This repository contains my OS lab practical programs in C. I have kept the programs separate so that I can compile and run them one at a time while practising.

## Folders

| Folder | Topics |
| --- | --- |
| `01_Process_Management` | fork, wait, parent-child processes, orphan and zombie processes, exec |
| `02_Process_Communication` | pipe, FIFO, message queue, shared memory and permutations |
| `03_File_Handling` | File operations using parent and child processes |
| `04_CPU_Scheduling` | FCFS, SJF and Priority scheduling |
| `05_Page_Replacement` | FIFO and LRU page replacement |

## How to compile

These programs are for Linux. Open a terminal in the repository folder and compile the file you want:

```bash
gcc -Wall -Wextra 01_Process_Management/02_fork_parent_child.c -o fork_demo
./fork_demo
```

For another program, replace the source file name and output name.

## IPC programs

Some IPC practicals use two separate programs:

- **FIFO:** compile `03_fifo_writer.c` and `04_fifo_reader.c`. Open two terminals in the same folder. Run the reader in one terminal and writer in the other. The writer waits until the reader opens the FIFO.
- **Message queue:** run `05_message_sender.c` first, then `06_message_receiver.c`. The receiver removes the queue after reading.
- **Shared memory:** run `07_shared_writer.c` first and then `08_shared_reader.c`. The reader removes the shared memory segment.

For the IPC programs, run both executables from the same working directory because they use the same `ftok()` path or FIFO name.

## Notes

- The scheduling programs assume all processes arrive at time zero.
- SJF and Priority are non-preemptive.
- In the Priority program, a smaller priority number means higher priority.
- The orphan and zombie examples are timing demonstrations. Use the instructions printed by the zombie program to check the process with `ps`.
- See [QUESTIONS.md](QUESTIONS.md) for the practical checklist and [BUILDING.md](BUILDING.md) for compile instructions.

