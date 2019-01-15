<img src="https://www.holbertonschool.com/holberton-logo-twitter-card.png">

# 0x10. C - printf
Low-level programming & Algorithm ― Hatching out

## Contents
* [Purpose](https://github.com/sumin3/printf#Purpose)
* [Declaration](https://github.com/sumin3/printf#Declaration)
* [Coding style](https://github.com/sumin3/printf#Coding-style)
* [Installation](https://github.com/sumin3/printf#installation)
* [Usage Example](https://github.com/sumin3/printf#Usage-Example)
* [Files](https://github.com/sumin3/printf#Files)
* [Author](https://github.com/sumin3/printf#author)

## Purpose
To create a custom _print function that sends formatted output to stdout by using C programming language

## Declaration
Following is the declaration for printf() function.
#### `int _printf(const char *format, ...)`
- format: A string that contains the text to be written to stdout. It can optionally contains format placeholder specifiers (eg: %s, %d, and %i) that will replaced by the value specified in additional arguments. 
- Return: return length of the buffer. if error, return -1
#### Specifiers
Specifier  | Description
----|-----
%s | String of characters
%c | Character
%d | Signed decimal integer
%i | Signed decimal integer

## Coding style
- All C files are compiled on Ubuntu 14.04 LTS and using [Betty Style](https://\github.com/holbertonschool/Betty) for checking coding and documentation styles.

## Installation
To use, first download  this repository into your local machine by issuing the following command in your local terminal. 
```
git clone https://github.com/sumin3/printf.git
```

#### Change Directory
```
cd printf
```
After change current working directory to **printf** directory, issue the following command to compile

##### Run .c file
Create your own main file before you start. 
- Not sure what to put in your main file? see [Usage Example](https://github.com/sumin3/printf#Usage-Example)


```
gcc -Wall -Werror -Wextra -pedantic <main.c> -o <output filename>
```
Once the .c files are compiled you can run the program by issuing the command
```
./<output filename>
```
## Usage Example
- print a string:
```
#include "holberton.h"
_printf("This is an example.");
```
```
output: This is an example.
```

- print a string contains format placeholder specifiers:
```
#include "holberton.h"
_printf("This is an example %d, %c %s.", 3, "a", "cat");
```
```
output: This is an example 3, a cat.
```
## Files
File | Function | Desc
---|---|---
[_printf.c](_printf.c) | _printf | print string or string with format.
[get_sp.c](get_sp.c) | get_sp | selects the correct specifier function
[helper.c](helper.c) | _strlen | return the length of a string
.	|  _strncpy | copies a string.
[helper2.c](helper2.c) | copy_literal | copy literal string to buffer
.   | write_buff | write string from buffer
.   | percent_helper | handle specifiler - %
[sp.c](sp.c) | get_int | convert integer to string
.   |  not_match | return null
.   |  get_char | put/add character in buffer
.   |  get_string | put/add string in buffer
.   |  get_percent | put/add percentage sign in buffer


## Author
- Sumin Yu - [Twitter: @3_sumin](https://twitter.com/3_sumin)
- Wendy Leung - [Twitter: @theebluesea](https://twitter.com/theebluesea)