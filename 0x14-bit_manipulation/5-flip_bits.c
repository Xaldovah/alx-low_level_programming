#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * flip_bits - Returns bits needed to flip to get from one number to another
 * @n: The first number
 * @m: The second number
 *
 * Return: The number of bits needed to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	/* XOR the two numbers to get the bits that are different */
	unsigned long int xor_result = n ^ m;
	/* Initialize a variable to count number of bits to be flipped */
	unsigned int count = 0;

	/* Continue looping while there are still bits to be flipped */
	while (xor_result != 0)
	{
		/* If least significant result of XOR is 1, increment count */
		count += xor_result & 1;
		/* Right-shift the XOR result by 1 bit to check the next bit */
		xor_result >>= 1;
	}

	/* Return the total count of bits that need to be flipped */
	return (count);
}
