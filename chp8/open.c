#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd;
    char *filename = "hello.txt";
    // perms is always 0 for uses of open here
    fd = open(filename, O_RDONLY, 0);
    printf("fd is %d\n", fd);
    if(fd == -1)
    {
        // fprintf(stderr, "An error ocurred while opening file %s", filename);
    }
    char in_buf[100];
    int n_read = read(fd, in_buf, sizeof in_buf);
    printf("Read %d bytes: ", n_read);
    write(1, in_buf, n_read);


}