#include <stdio.h>
// #include "syscalls.h"
// from system calls
int write(int fd, char *outbuff, int amount);
int read(int fd, char *inbuff, int amount);
// int printf(char *fmt, ...);

int main()
{
    int stdin_fd = 0;
    int stdout_fd = 1;
    int stderr_fd = 2;

    char buff[] = "Good morning";
    int n_written = write(stderr_fd, buff, sizeof(buff));
    printf("\nWrote: %d\n", n_written);

    char inbuff[100];
    int n_read = read(stdin_fd, inbuff, sizeof(inbuff));
    printf("Write using system calls:");
    // write(stdout_fd, inbuff, n_read);
    // inbuff[n_read] = 0; // this helps show where read values in inbuff end
    char fmt[100];
    sprintf(fmt, "Read: %%.%ds", n_read);
    // printf("Format: %s\n", fmt);
    // printf("\nRead %d bytes: %s\n", n_read, inbuff);
    printf(fmt, inbuff);
    // printf("K");
}