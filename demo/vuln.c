#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


void evil(char *file)
{
	int fd = open(file, O_RDONLY);

	void *ptr = mmap(0, 4096, PROT_READ | PROT_WRITE,
		MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	int read_count = read(fd, ptr, 4096);

	printf("%s\n", ptr);

	close(fd);
}

void well_made_code(char* file, int len)
{
	char buf[32];
	int fd = open(file, O_RDONLY);
	read(fd, buf, len);
	close(fd);
}

int main(int argc, char *argv[])
{
	evil("funny.txt");

	int size = strtol(argv[2], NULL, 10);

	well_made_code(argv[1], size);

	printf("What a great program\n");

	return 0;
}
