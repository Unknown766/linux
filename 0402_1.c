#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
        DIR *dirp;
        if ((dirp=opendir(argv[1]))==NULL) {
                printf("Dir not exisit.\n");
                exit(1);
        } else {
                printf("Dir now exisit.\n");
                exit(1);	
        }
        closedir(dirp);
}

