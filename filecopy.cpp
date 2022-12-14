/*
	6. Write a program to copy a source file into the target file and display the target file using system calls.

*/
#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
using namespace std;
int main()
{
	char src,dest;
	cin>>src;
	if (src!=0)
	{
		fprintf(stderr, "Correct Usage: ./main <src_filename> <src_filename>\n");
		return -1;
	}
	
	char buf;
	int fd1, fd2, n;
	if ((fd1 = open(src, O_RDONLY)) < 0)
	{
		fprintf(stderr, "Could not read %s\n", src);
		return 2;
	}

	if ((fd2 = creat(dest, 0666)) < 0)
	{
		fprintf(stderr, "Could not write to %s\n", dest);
    		return 2;
	}
	
	while ((n = read(fd1, &buf, 1)) > 0)
		write(fd2, &buf, 1);

	printf("Copied contents of %s to %s\n", src, dest);

	close(fd1);
	close(fd2);
	return 0;
}
