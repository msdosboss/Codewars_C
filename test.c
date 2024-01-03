#include <unistd.h>
#include <stdio.h>

void main(){
    char cwd[256];

    printf("%s\n",getcwd(cwd,sizeof(cwd)));
    printf("%s\n",cwd);
}