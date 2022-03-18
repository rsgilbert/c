#include <stdio.h>
#include <stdlib.h>

// execute command 
int main()
{
    // on windows, these will be the commands available to command prompt, not powershell
    int status = system("dir");
    // status = system("date");
    printf("Status %d\n",status);
}