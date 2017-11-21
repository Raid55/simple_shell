## b.sh
#### (best shell)

### Description 
**A simple UNIX command interpreter.**
* Displays a prompt and waits for the user to type a command. Command line always ends with a new line.
* The prompt is displayed again each time a command has been executed.
* The command lines are simple, no semi-columns, no pipes, no redirections or any other advanced features.
* If an executable cannot be found, prints an error message and displays the prompt again.
* Handles errors.
* Handles the “end of file” condition (Ctrl+D).
* Handles command lines with arguments.
* Handles the PATH.
* Implements the exit buit-in, that exits the shell (Usage: exit).
* Implements the env built-in, that prints the current environment.

### Files

|   **Files**   |   **Description**   |
| -------------- | --------------------- |
| main.c | main shell entry and loop |
| shell_instance.c | starts shell, recieves and interprets user input|
| bundled_funcs.c | display custom prompt and get absolute path |
| utils.c | obtain string tokens and execute files |
| helpers.c | functions that help obtain a programs path and tokenize strings |
| built_in.c | checks for and runs builtin functions |
| shell.h | header file: contains prototypes, libraries and macros |

### Requirements
* Allowed editors: ```vi```, ```vim```, ```emacs```
* All files will be compiled on Ubuntu 14.04 LTS
* Programs and functions will be compiled with ```gcc 4.8.4``` using the flats ```-Wall``` ```-Werror``` ```-Wextra``` ```and -pedantic```
* All files should end with a new line
* Code should use the ```Betty``` style. it will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)
* Not allowed to use global variables
* No more than 5 functions per file
* The prototypes of all functions should be included in the header file called ```holberton.h```
* All header files should be include guarded
* Authorized functions and system calls:
  * ```access``` (```man 2 access```)
  * ```chdir``` (```man 2 chdir```)
  * ```close``` (```man 2 close```)
  * ```closedir``` (```man 3 closedir```)
  * ```execve (```man 2 execve```)
  * ```exit``` (```man 3 exit```)
  * ```fork``` (```man 2 fork```)
  * ```free``` (```man 3 free```)
  * ```stat``` (```man 2 stat```)
  * ```lstat``` (```man 2 lstat```)
  * ```fstat``` (```man 2 fstat```)
  * ```getcwd``` (```man 3 getcwd```)
  * ```getline``` (```man 3 getline```)
  * ```kill``` (```man 2 kill```)
  * ```malloc``` (```man 3 malloc```)
  * ```open``` (```man 2 open```)
  * ```opendir``` (```man 3 opendir```)
  * ```perror``` (```man 3 perror```)
  * ```read``` (```man 2 read```)
  * ```readdir``` (```man 3 readdir```)
  * ```signal``` (```man 2 signal```)
  * ```strtok``` (```man 3 strtok```)
  * ```wait``` (```man 2 wait```)
  * ```waitpid``` (```man 2 waitpid```)
  * ```wait3``` (```man 2 wait3```)
  * ```wait4``` (```man 2 wait4```)
  * ```write``` (```man 2 write```)
  * ```_exit``` (```man 2 _exit```)
  * ```isatty``` (```man 3 isatty```)
  * ```fflush``` (```man 3 fflush```)

### Notes
Tested on *Ubuntu 14.04 LTS*.    
No known bugs.  

### Author

* [**James Heck**](https://github.com/notjamesheck) 
* [**Raid55 (Nick B.)**](https://github.com/Raid55)

<p align="center">
<a href="https://www.holbertonschool.com"><img src="https://intranet.hbtn.io/assets/holberton-logo-simplified-d4e8a1e8bf5ad93c8c3ce32895b4b53749b477b7ba7342d7f064e6883bcd3be2.png"></a>
</p>

