#include <stdlib.h>
#include "main.h"

/**
 * count_word - helper function to count the number of words in a string
 * @s: string to evaluate
 * Return: number of words
 */
int count_word(char *s)
{
	int flag, c, w;

	flag = 0;
	w = 0;

	for (c = 0; s[c] != '\0'; c++)
		if (s[c] == ' ')
			flag = 0;

		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
	return (w);
}

/**
 * count_word - counts the number of words in a string
 * @str: string to count words in
 * Return: number of words in the string
 */

int count_word(char *str)
{
	/* Implementation */
}

/**
 * copy_word - copies a word from a string into a new memory block
 * @start: starting index of the word in the string
 * @end: ending index of the word in the string
 * Return: pointer to the copied word
 */

char *copy_word(char *str, int start, int end)
{
	/* Implementation */
}

/**
 * strto - splits a string into words
 * @str: string to split
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */

char **strtow(char *str)
{
	/* Declarations */

	int i, k = 0, len = 0, words, c = 0, start, end;
	char **matrix, *tmp;

	/* Count number of words */

	len = strlen(str);
	words = count_word(str);
	if (words == 0)
		return (NULL);

	/* Allocate memory for matrix */

	matrix = (char **) malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	/* Split string into words and store in matrix */
	for (i = 0; i <= len; i++) {
		if (str[i] == ' ' || str[i] == '\0') {
			if (c) {
				end = i;

				tmp = copy_word(str, start, end);

				if (tmp == NULL)
					return (NULL);
				matrix[k] = tmp;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0) {
			start = i;
		}
	}
	matrix[k] = NULL;
	return (matrix);
}
