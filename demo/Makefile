.PHONY: all clean
all: exploit vul
	gcc -m32 -o exploit exploit.c
exploit: exploit.c
	gcc -m32 -g -o exploit exploit.c
vul: vuln.c
	gcc -m32 -o vuln vuln.c
clean:
	rm -f exploit vuln
