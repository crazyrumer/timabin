#include <stdio.h>
#include <stdbool.h>

typedef unsigned int uint;

// Function prototypes
// Function which prints out bytes of the variable
// 
// Input size:	size of the variables in bytes
// Input ptr:	pointer to the variable we want to print binary equivalent
//
//Return nothing
void printBits(uint const size, void const * const ptr);


void setZero(uint const size, void *const ptr);
void xorSwap(int* a, int* b);
void leftShiftX(int* a, uint n);
bool isArithmeticRightShift();

uint setBit(uint a, const uint bit);
void setBitPtr(uint * const a, const uint bit);

uint clearBit(uint a, const uint bit);
void clearBitPtr(uint * const a, const uint bit);

uint bitpatGet(uint a, uint startBit, uint bitCount);

void bitpatSet(
	uint * const ptr,
	uint value,
	const uint startingBit,
	const uint bitSize);