#include "./syscalls.h"
#include <stdio.h>

/* unbuffered single character input. When the input consists of multiple
characters, multiple system calls (reads) will be made. */
int getchar(void)
{
    char c;
    const static int BYTES_TO_READ = 1;
    int n_read = read(FD_STDIN, &c, BYTES_TO_READ);
    if (n_read == 1)
    { // casting eliminates problem of sign extension (!)
        printf("read %c\n", c);
        return (unsigned char)c;
    }
    else
    {
        printf("eo");
        return EOF;
    }
}

/* buffered version. Does input in big chunks and
hands out characters one at a time.
This means one system call is used. */
int getchar2(void)
{
    static char buf[BUFFSIZE];
    static char *bufp = buf;
    static int n_read = 0;
    // printf("n read %d\n", n_read);

    if (n_read == 0)
    { // buffer is empty
        n_read = read(FD_STDIN, buf, sizeof buf);
        bufp = buf; // make bufp point to first position
        if (n_read == 0)
        { // no character was read
            return EOF;
        }
    }

    unsigned char c = *bufp;
    bufp++;
    n_read--;
    return c;
}

int main()
{
    // getchar2
    int c1 = getchar2(), c2 = getchar2(), c3 = getchar2(), c4 = getchar2();
    printf("Chars are %c and %c and %c and %c\n", c1, c2, c3, c4);

    // int c1 = getchar();
    // printf("sec");
    // int c2 = getchar();
    // printf("Chars are %c and %c and %c\n", c1, c2, getchar());
}
