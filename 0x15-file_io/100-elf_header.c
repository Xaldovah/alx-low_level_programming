#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_error - Prints error message to stderr and exits with status code 98.
 * @msg: The error message to print.
 */
void print_error(char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(98);
}

/**
 * print_magic - Prints the ELF magic number to stdout.
 * @e_ident: The ELF header identification array.
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("ELF Header:\n  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++) /* Iterate over the e_ident array */
	printf("%02x ", e_ident[i]); /* Print each byte in hexadecimal format */
	printf("\n");
}

/**
 * print_class - Prints the ELF class to stdout.
 * @e_ident: The ELF header identification array.
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
			break;
	}
}

/**
 * print_data - Prints the ELF data encoding to stdout.
 * @e_ident: The ELF header identification array.
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_DATA]);
			break;
	}
}

/**
 * print_version - Prints the ELF version to stdout.
 * @e_ident: The ELF header identification array.
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           ");
	switch (e_ident[EI_VERSION])
	{
		case EV_NONE:
			printf("invalid version\n");
			break;
		case EV_CURRENT:
			printf("1 (current)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_VERSION]);
			break;
	}
}

/**
 * print_osabi - Prints the ELF OS/ABI to stdout.
 * @e_ident: The ELF header identification array.
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_OPENBSD:
			printf("UNIX - OpenBSD\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
			break;
	}
}

/**
 * main - ...
 * @argc: ...
 * @argv: ...
 *
 * Return: ...
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;
	unsigned char *e_ident;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");
	fd = open(argv[1], O_RDONLY);

	if (fd == -1)
		print_error("Error: Cannot open file");
	if (read(fd, &header, sizeof(header)) != sizeof(header))
		print_error("Error: Cannot read file");

	printf("File path: %s\n", argv[1]); /* Add file path output */
	printf("\n"); /* Add empty line */
	e_ident = header.e_ident;
	print_magic(e_ident);
	print_class(e_ident);
	print_data(e_ident);
	print_version(e_ident);
	print_osabi(e_ident);
	printf("\n"); /* Add empty line */
	system("readelf -S --wide -W --file-header --special-programs --hex-dump=.notes --string-dump=.comment --debug-dump=decodedline,info,frames,abbrev,macro,types,locs --debug-dump=info --debug-dump=frames --debug-dump=abbrev --debug-dump=macro --debug-dump=types --debug-dump=locs ");
	if (close(fd) == -1)
		print_error("Error: Cannot close file");

	return (0);
}
