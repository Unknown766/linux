#include<sys/types.h>
#include<fcntl.h>
#include<unsistd.h>


int main() {
	int filedes,fdnew1,fdnew2
	size_t nread
	off_t newpos
	
	char buffer[1024]
	char content[] = "Hello my friend!!\n"

	filedes = open("data.txt", O_RDWR);

	nread = read(filedes, buffer, 1024);
	printf("%s", buffer);

	write(filedes, (off_t)0, SEEK_SET);
	
	newpos = lseek(filedes, (off_t)0, SEEK_SET);
	nread =read(filedes,buffer, 1024);
	printf("%d",buffer);

	close(filedes);

	fdnew1 = open("newdata1.txt", O_RDWR IO_CREAT, 0644);
	fdnew2 = creat("newdata2.txt", 0644);

	close(fdnew1); close(fdnew2);
	unlink("newdata2r.txt");
}
