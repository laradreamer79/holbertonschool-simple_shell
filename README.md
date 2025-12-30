## Simple Shell

## Table of Contents
- [Project Description](#project-description)
- [Features](#features)
- [Compilation](#compilation)
- [Usage](#usage)
- [exit](#exit)
- [env](#env)
- [Files Description](#files-description)
- [Return Values](#return-values)
- [Environment](#environment)
- [Authors](#authors)

---
### Description

This project is a simple UNIX command line interpreter (shell) written in C.
It replicates basic behavior of the standard `/bin/sh` shell.

The shell reads commands from standard input, parses them, searches for
executables using the `PATH` environment variable, and executes them using
system calls.


### Features

* Display a prompt and wait for user input
* Execute commands with arguments
* Search commands in `PATH`
* Execute commands using absolute paths
* Handle empty lines and extra spaces
* Built-in commands:

  * `exit` – exits the shell
  * `env` – prints the current environment
* Proper error handling
* Correct exit status handling
* Betty style compliant

---

### Compilation

Compile the shell using:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```


### Usage

Run the shell:

```bash
./hsh
```

Example:

```bash
$ ls -l
$ env
$ exit
```

Non-interactive mode:

```bash
echo "ls" | ./hsh
```

---

### Built-in Commands

#### exit

Exits the shell.

```bash
$ exit
```

#### env

Prints the current environment.

```bash
$ env
```

---

### Files Description

| File                 | Description                           |
| -------------------- | ------------------------------------- |
| `main.c`             | Entry point of the shell              |
| `simple_shell.c`     | Core shell loop logic                 |
| `execute.c`          | Command execution logic and built-ins |
| `path.c`             | PATH searching logic                  |
| `_getenv.c`          | Custom implementation of getenv       |
| `trim_space.c`       | Removes leading and trailing spaces   |
| `shell.h`            | Header file with prototypes           |
| `man_1_simple_shell` | Manual page                           |
| `AUTHORS`            | Project authors                       |

---

### Return Values

* `0` on success
* `127` when command is not found
* Proper exit status propagation from child processes


### Environment

* Uses the `environ` global variable
* Fully compatible with `PATH=""` cases

---
### Authors
- **Lara Alzannan** [laradreamer79](https://github.com/laradreamer79)
- **Layla Alshehri** [laja99](https://github.com/Laja99)
