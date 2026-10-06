# IPC Selection and Justification

## Selected IPC Method
POSIX Named Pipes (FIFO)

## Why FIFO was Selected

FIFO was selected because it provides simple communication between
independent processes.

Our simulator has three separate processes:
- UI Process
- Core Process
- Logger Process

FIFO allows these processes to exchange commands and messages
without combining them into a single program.

## Communication Flow

UI Process → Core Process
Core Process → UI Process
Core Process → Logger Process

## Advantages

- Simple to implement
- Suitable for communication between independent processes
- Supports one-way communication
- Easy to test and debug
- Supported by POSIX/Linux systems

## Use in Our Project

The UI sends commands to the Core process through the
`ui_to_core` FIFO.

The Core sends responses to the UI through the
`core_to_ui` FIFO.

The Core sends log messages to the Logger through the
`core_to_logger` FIFO.
