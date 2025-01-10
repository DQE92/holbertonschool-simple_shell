
# HOLBERTON SIMPLE SHELL

### Description 

## What is Shell ?

The shell is a program that takes commands from the keyboard via the terminal, and gives them to the operating system to perform.

This repository is a project from Holberton School and contains the files to simulate a basic Unix Shell
We are asked to create a shell in C language where we can type simple commands.
The goal in this project is to understand how a shell work and what is the environment,
the difference between functions and system calls, how to create processes using execve...

## Who we are?

We are Camille and Dylan, students of Holberton School. 

## Installation

- Clone repository

HTTPS:
```bash
git clone https://github.com/DQE92/holbertonschool-simple_shell.git
```
SSH:
```bash
git clone git@github.com:DQE92/holbertonschool-simple_shell.git
```

- Change directory  into the repository
```bash
cd holbertonschool-simple_shell
```
- Compile 
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
- Run the shell in interactive mode
```bash
./hsh
```
- Run the shell in non-interactive mode
```bash
echo "Hello world!" | ./hsh
```
-Exiting the shell, with 2 methods
```bash
exit
```
or Press Ctrl+D

## Usage/Examples

```bash
holbertonschool-simple_shell git:(main) gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
($) ./hsh
($) echo "Hello world!"
"Hello world!"
($) ls
AUTHORS.sh		execute_command.c	main.c			show_prompt.c
README.md		hsh			shell.h
($) ls -l
total 152
-rw-r--r--  1 miaou  staff    211 17 déc 14:19 AUTHORS.sh
-rw-r--r--  1 miaou  staff    924 10 jan 01:08 README.md
-rw-r--r--  1 miaou  staff   3047  8 jan 02:26 execute_command.c
-rwxr-xr-x  1 miaou  staff  50704 10 jan 01:14 hsh
-rw-r--r--  1 miaou  staff    710  8 jan 02:16 main.c
-rw-r--r--  1 miaou  staff    290  8 jan 02:16 shell.h
-rw-r--r--  1 miaou  staff    129  7 jan 21:41 show_prompt.c
($) exit
```
## Requierments

- Allowed editors: vi, vim, emacs
- Github
- main.c
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options
-Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
- Use system call only when you need to.

## Tasks

0- README, man, AUTHORS

1- Betty would be proud 

2- Simple shell 0.1

3- Simple shell 0.2

4- Simple shell 0.3

5- Simple shell 0.4

§- Simple shell 1.0

## Authors

- Camille Ducatte (camilledct28@gmail.com)
- Dylan Duque (duquedylan@gmail.com)
