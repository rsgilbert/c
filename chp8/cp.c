#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdarg.h>

#define BUFFSIZE 1000
#define FD_STDERR 2
#define TO_PERMS 0644 /* Read and Write for all */

void error(char * msg, ...)
{
    va_list args;
    va_start(args, msg);
    fprintf(stderr, "Error: ");
    vfprintf(stderr, msg, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}

// cp: copy f1 to f2
int main(int argc, char *argv[])
{
    int i = unlink("hello.txt"); // remove file

    int fd1, fd2, n_read;
    char buf[BUFFSIZE];

    if(argc != 3)
    {
        error("Expected two arguments, got %d", argc - 1);
    }
    char *from_filename = argv[1];
    char *to_filename = argv[2];
    fd1 = open(from_filename, O_RDONLY, 0);
    if(fd1 == -1)
    {
        error("Failed to open from file %s", from_filename);
    }
    fd2 = creat(to_filename, TO_PERMS);
    if(fd2 == -1)
    {
        error("Failed creating destination file %s", to_filename);
    }
    while(n_read = read(fd1, buf, sizeof(buf)))
    {
        write(fd2, buf, n_read);
    }
}



