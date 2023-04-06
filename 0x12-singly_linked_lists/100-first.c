#include <stdio.h>

void  __attribute__((constructor)) before_main()
/**
 * void __attribute__ - prints a string before main.
 *
 * Return: Nothing.
 */

{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
