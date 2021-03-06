#include "timabin.h"



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
			unsigned char and = byte & mask;	// AND mask with byte to find out which bit is 0 or 1
			unsigned char result = and >> j;	// right shift the filtered bit to the lowest bit
			printf("%u", result);				// print out result

			if (j % 4 == 0)
			{
				printf(" ");
			}
		}
	}
	printf("\n");
}

// Function which sets value to zero
// This is just experimental and should never be used in production
void setZero(uint const size, void *const ptr)
{
	unsigned char * b = (unsigned char*)ptr;	// cast pointer to char pointer so it covers 1 byte
	unsigned char byte = 0;					    // value to store byte

	// iteratae over each byte inside the variable right to left
	for (int i = size - 1; i >= 0; i--)
	{
		b[i] ^= b[i];		// zero each byte
	}
}

// Function which swaps variables - source https://en.wikipedia.org/wiki/XOR_swap_algorithm
void xorSwap(int* a, int* b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

// Function which multiplies value by factor of 2^N via left shift operator
void leftShiftX(int* a, uint n)
{
	*a = *a << n;
}

// Function which determines if machine has arithmetic or logical right shift
bool isArithmeticRightShift()
{
	int i = ~0;		// set all bits to 1
	i >>= 1;		// right shift by 1

	if (i > 0)		// higher bit got replaced by 0
	{
		return false;
	}
	else            // higher bit got replaced by 1
	{
		return true;
	}
}


// Set bit to 1 and return value
uint setBit(uint a, const uint bit)
{
	return a | (1 << bit);
}

// Set bit to 1 via pointer
void setBitPtr(uint * const a, const uint bit)
{
	*a |= (1 << bit);
}

// Clear bit and return value
uint clearBit(uint a, const uint bit)
{
	return a & (~(1 << bit));
}

// Clear bit via pointer
void clearBitPtr(uint * const a, const uint bit)
{
	*a &= (~(1 << bit));
}

// Get bits pattern from variable
uint bitpatGet(uint a, uint startBit, uint bitCount)
{
	uint size = sizeof(a) * 8;
	return (a << (size - (startBit + bitCount))) >> (size - bitCount);
}

// Set bits pattern inside variable
void bitpatSet(
	uint * const	ptr,
	uint			value,
	const uint		startingBit,
	const uint		bitSize)
{
	value <<= startingBit;

	uint mask = 0u;
	for (uint i = 0; i < bitSize; i++)
	{
		mask |= 1 << i;
	}
	mask = ~(mask << startingBit);

	*ptr = (*ptr & mask) | (value << startingBit);
}
