*This activity has been created as part of the 42 curriculum by raaalali.*

# ft_printf

![C](https://img.shields.io/badge/language-C-A8B9CC?style=flat-square&logo=c&logoColor=black)
![Output](https://img.shields.io/badge/output-write(2)-38bdf8?style=flat-square)

A from-scratch implementation of `printf(3)`, packaged as a static library. It parses the format string, pulls arguments through `stdarg.h` and writes directly with `write(2)`: no buffering and no calls into the real `printf`.

## Build

```sh
make          # builds libftprintf.a
make clean | fclean | re
```

```c
#include "ft_printf.h"

int main(void)
{
	int n = ft_printf("%s scored %d (0x%x) at %p\n", "raad", 42, 42, &n);
	return (n < 0);
}
```

```sh
cc main.c -L. -lftprintf -o main
```

## Conversions

| Specifier | Output |
| --- | --- |
| `%c` | single character |
| `%s` | string (`(null)` for `NULL`) |
| `%p` | pointer as `0x`-prefixed lowercase hex |
| `%d` `%i` | signed decimal, including `INT_MIN` |
| `%u` | unsigned decimal |
| `%x` `%X` | unsigned hex, lower / upper case |
| `%%` | literal percent sign |

Returns the number of bytes written, like the original.

## Structure

```
ft_printf.c           format walk and dispatch per specifier
ft_printf_char.c      %c
ft_printf_str.c       %s
ft_printf_nbr.c       %d %i
ft_printf_unsigned.c  %u
ft_printf_hex.c       %x %X
ft_printf_ptr.c       %p
```

Each handler returns the count it wrote, so the dispatcher just sums them. Numbers are converted manually by base rather than through any library formatting.

## Resources

- 42 subject, `man 3 printf`, `man 3 stdarg`
- [cppreference: printf](https://en.cppreference.com/w/c/io/fprintf)

## AI usage

AI tools were used only to help structure this README. The source code was implemented, tested and validated manually.
