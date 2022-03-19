#define FD_STDIN 0
#define FD_STDOUT 1
#define FD_STDERR 2
#define BUFFSIZE 2
int write(int fd, char *outbuff, int amount);
int read(int fd, char *inbuff, int amount);
int open(char *name, int flags, int perms);