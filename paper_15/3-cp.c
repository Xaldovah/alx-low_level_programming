#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
  * main - Takes arguments and a pointer to a pointer of characters
  * @argc: The argument count
  * @argv: The argument vector
  *
  * Return: The copied file
  */
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	copy_file(argv[1], argv[2]);
	exit(0);
}

/**
  * copy_file - The file to copy
  * @src: Pointer to a char
  * @dest: Pointer to a char
  *
  * Return: success
  */
void copy_file(const char *src, const char *dest)
{
	int cfd, lcd, reading;
	char buffer[1024];

	cfd = open(src, O_RDONLY);
	if (!src || cfd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
		exit(98);
	}

	lcd = open(dest, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while ((reading = read(cfd, buffer, 1024)) > 0)
	{
		if (write(lcd, buffer, reading) != reading || lcd == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest);
			exit(99);
		}
	}

	if (reading == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
		exit(98);
	}

	if (close(cfd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", cfd);
		exit(100);
	}

	if (close(lcd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", lcd);
		exit(100);
	}
}
