#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void evil(char *file) {

    int fd = open(file, O_RDONLY);

    void *ptr = mmap(0, 4096, PROT_READ | PROT_WRITE,
            MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    int read_count = read(fd, ptr, 4096);

    printf("%s\n", ptr);
}


int main(int argc, char *argv[]) {

    evil("funny.txt");

    char buf[32];

    strcpy(buf, argv[1]);

    return 0;
}
