#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: the name of the file to read
 * @letters: the number of letters to read and print
 *
 * Return: the number of letters read and printed, or 0 if an error occurred
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, reading;
	char *buffer = malloc(sizeof(char *) * letters);

	if (!buffer)
		return (0);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY, 0600);
	if (fd == -1)
		return (0);

	reading = read(fd, buffer, letters);
	write(STDOUT_FILENO, buffer, reading);

	free(buffer);
	close(fd);
	return (reading);
}


