# About
|             |                             |
| ----------- | --------------------------- |
| Prototype		| char *get_next_line(int fd)	|
| Parameter		| File descriptor to read from.	|
| Return value	| Read line: correct behaviour;<br> NULL: nothing else to read or an error occurred. |

> A function which returns a line read from a file descriptor. Calling get_next_line in a loop will then allow us to read the text
available on the file descriptor one line at a time until the end of it.

## Bonus
> Manage multiple file descriptors with get_next_line with a single static variable. For example, if the file descriptors 3, 4 and 5 are accessible for reading, then we can call get_next_line once on 3, once on 4, once again on 3 then once on 5 etc. without losing the reading thread on each of the descriptors.

## Usage
To compile: 
```sh
$> gcc -Wall -Wextra -Werror -D BUFFER_SIZE=xxx <files>.c.
```
Where "xxx" is the number of bytes read by the buffer each time. BUFFER_SIZE is set to 1 by default.
