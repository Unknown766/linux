#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	DIR *dirp;
	int file=0, dir=0;
	struct dirent *dentry;
	
	if((dirp = opendir(".")) == NULL) {
		fprintf(stderr,"Error\n");
		exit(1);
	}	
	while( dentry = readdir(dirp)) {
		if(dentry->d_ino != 0) {
			if ((dentry->d_name)=="."||(dentry->d_name)=="..") {
				dir++;
			} else {
				file++;
			}
		}
	}
	printf("%d file, %d dir.\n",file,dir);

	closedir(dirp);
} 
