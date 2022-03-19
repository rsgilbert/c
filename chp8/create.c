#include <stdio.h>
#include <fcntl.h>
#include <string.h>
// thinking you could leave me.  song.

int main()
{
    // create file
    char *filename = "my nice file.txt";
    int fd = creat(filename, 0644); // defined in io.h. also give rw perms to owner
    printf("fd of created file %d\n", fd);
    char content[] = "Wow. Thank you for accepting to be created";
    write(fd, content, strlen(content));
}