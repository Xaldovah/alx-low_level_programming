#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * generate_key - Generate a key
 *
 * Return: Pointer to generated key (char *)
 */
char *generate_key(void)
{
	char possible_chars[] = "abcdefghijklmnopqrstuvwxyz0123456789";
	char *key = malloc(9 * sizeof(char));
	int i;

	srand(time(NULL));
	for (i = 0; i < 7; i++)
	{
		key[i] = possible_chars[rand() % (sizeof(possible_chars) - 1)];
	}
	key[7] = '@';
	key[rand() % 8] = '-';
	key[8] = '\0';

	return (key);
}

/**
 * test_key_gen - Test the key generation
 * @program: Program name
 * @test_count: Number of tests
 */
void test_key_gen(const char *program, int test_count)
{
	int i;
	char *key, command[50];
	FILE *pipe;

	for (i = 0; i < test_count; i++)
	{
		key = generate_key();
		printf("test %d: %s\n", i + 1, key);
		sprintf(command, "%s %s", program, key);
		pipe = popen(command, "r");
		pclose(pipe);
		free(key);
	}
	printf("completed %d successful runs!\n", test_count);
}

/**
 * main - Entry point
 * Return: 0
 */
int main(void)
{
	test_key_gen("./crackme5", 50);

	return (0);
}
