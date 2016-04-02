#include <stdio.h>
#include <stdbool.h>

typedef unsigned int uint;

// Function prototypes
void printBits(uint const size, void const * const ptr);
void setZero(uint const size, void *const ptr);
void xorSwap(int* a, int* b);
void leftShiftX(int* a, uint n);
bool isArithmeticRightShift();

uint setBit(uint a, const uint bit);
void setBitPtr(uint * const a, const uint bit);

uint clearBit(uint a, const uint bit);
void clearBitPtr(uint * const a, const uint bit);