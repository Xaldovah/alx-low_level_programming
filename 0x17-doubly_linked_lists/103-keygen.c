#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * generate_key - Generates a key for the given username
 * @username: The username
 *
 * Return: The generated key
 */
char *generate_key(const char *username)
{
	size_t len = strlen(username);
	char *key = malloc((len + 5) * sizeof(char));

	if (key == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(1);
	}
	strcpy(key, username);
	strcat(key, "_key");

	return (key);
}

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 if successful, 1 if it failed
 */
int main(int argc, char *argv[])
{
	char *username = argv[1];
	char *key = generate_key(username);

	if (argc != 2)
	{
		printf("Usage: %s <username>\n", argv[0]);
		return (1);
	}
	printf("The key for the user %s is %s\n", username, key);

	free(key);

	return (0);
}
