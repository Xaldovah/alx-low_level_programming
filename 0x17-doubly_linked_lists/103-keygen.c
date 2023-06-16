#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - ...
 * @argc: ...
 * @argv: ...
 *
 * Return: 0 if succeeds, or 1 if it failed
 */
int main(int argc, char *argv[])
{
	char username[100];
	char key[100];

	if (argc != 2)
	{
		printf("Usage: ./keygen5 username\n");
		return (1);
	}
	strcpy(username, argv[1]);
	strcpy(key, username);
	strcat(key, "_key");
	printf("The key for the user %s is %s\n", username, key);
	return (0);
}
