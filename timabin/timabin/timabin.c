#include "timabin.h"

// Function which prints out bytes of the variable
// Input size: size of the variables in bytes
// Input ptr: pointer to the variable
void printBits(uint const size, void const * const ptr)
{
	unsigned char * b	= (unsigned char*)ptr;	// cast pointer to char pointer so it covers 1 byte
	unsigned char byte	= 0;					// value to store byte being pointed at			

	// iteratae over each byte inside the variable right to left
	for (int i = size - 1; i >= 0; i--)
	{
		byte = b[i]; // get byte

		// iterate over each bit inside the byte
		for (int j = 7; j >= 0; j--)
		{
			unsigned char mask = 1 << j;		// create mask to filter each individual bit
			unsigned char and = byte & mask;				// AND mask with byte to find out which bit is 0 or 1
			unsigned char result = and >> j;				// right shift the filtered bit to the lowest bit
			printf("%u", result);				// print out result

			if (j % 4 == 0)
			{
				printf(" ");
			}
		}
	}
	printf("\n");
}
