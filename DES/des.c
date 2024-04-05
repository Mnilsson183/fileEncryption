// source
// https://csrc.nist.gov/files/pubs/fips/46-3/final/docs/fips46-3.pdf
// http://orion.towson.edu/~mzimand/cryptostuff/DES-tables.pdf

#include <stdint.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	// starting with a standard size of 64 message;
	char* message = malloc(64);
	const short BLOCKSIZE = 64;
	char* key = malloc(64);
	
}

static const int key[] = {
	1,2,3,4,5,6,7,8,
	9,10,11,12,13,14,15,16,
	17,18,19,20,21,22,23,24,
	25,26,27,28,29,30,31,32,
	33,34,35,36,37,38,39,40,
	41,42,43,44,45,46,47,48,
	49,50,51,52,53,54,55,56,
	57,58,59,60,61,62,63,64,
};

static const int IP[] = {
	58,50, 42, 34, 26, 18, 10, 2,
	60,52, 44, 36, 28, 20, 12, 4,
	62,54, 46, 38, 30, 22, 14, 6,
	64,56, 48, 40, 32, 24, 16, 8,
	57,49, 41, 33, 25, 17, 9, 1,
	59,51, 43, 35, 27, 19, 11, 3,
	61,53, 45, 37, 29, 21, 13, 5,
	63,55, 47, 39, 31, 23, 15, 7,	

};

static const int E[] = {
	32,1,2,3,4,5,
	4,5,6,7,8,9,
	8,9,10,11,12,13,
	12,13,14,15,16,17,
	16,17,18,19,20,21,
	20,21,22,23,24,25,
	24,25,26,27,28,29,
	28,29,30,31,32,1,
};

static const int PC1[] = {
	57, 49, 41, 33, 25, 17, 9,
	1, 58, 50, 42, 34, 26, 18,
	10, 2, 59, 51, 43, 35, 27,
	19, 11, 3, 60, 52, 44, 36,
	63, 55, 47, 39, 31, 23, 15,
	7, 62, 54, 46, 38, 30, 22,
	14, 6, 61, 53, 45, 37, 29,
	21, 13, 5, 28, 20, 12, 4
};

static const int PC2[] = {
	14, 17, 11, 24, 1, 5, 3, 28,
	15, 6, 21, 10, 23, 19, 12, 4,
	26, 8, 16, 7, 27, 20, 13, 2,
	41, 52, 31, 37, 47, 55, 30, 40,
	51, 45, 33, 48, 44, 49, 39, 56,
	34, 53, 46, 42, 50, 36, 29, 32,
};

// FP or inverse initial permutation table
static const int FP[] = {
	40, 8, 48, 16, 56, 24, 64, 32,
	39, 7, 47, 15, 55, 23, 63, 31,
	38, 6, 46, 14, 54, 22, 62, 30,
	37, 5, 45, 13, 53, 21, 61, 29,
	36, 4, 44, 12, 52, 20, 60, 28,
	35, 3, 43, 11, 51, 19, 59, 27,
	34, 2, 42, 10, 50, 18, 58, 26,
	33, 1, 41, 9, 49, 17, 57, 25
};

// DES S-box 1
static const uint8_t S1[4][16] = {
    {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
    {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
    {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
    {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
};

// DES S-box 2
static const uint8_t S2[4][16] = {
    {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
    {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
    {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
    {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}
};

// DES S-box 3
static const uint8_t S3[4][16] = {
    {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
    {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
    {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
    {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}
};

// DES S-box 4
static const uint8_t S4[4][16] = {
    {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
    {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
    {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
    {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}
};

// DES S-box 5
static const uint8_t S5[4][16] = {
    {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
    {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
    {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
    {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}
};

// DES S-box 6
static const uint8_t S6[4][16] = {
    {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
    {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
    {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
    {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}
};

// DES S-box 7
static const uint8_t S7[4][16] = {
    {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
    {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
    {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
    {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 12, 2, 3, 12},
};



// DES S-box 8
static const uint8_t S8[4][16] = {
    {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
    {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
    {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
    {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}
};

static const uint8_t P_TABLE[32] = {
    16,  7, 20, 21,
    29, 12, 28, 17,
     1, 15, 23, 26,
     5, 18, 31, 10,
     2,  8, 24, 14,
    32, 27,  3,  9,
    19, 13, 30,  6,
    22, 11,  4, 25
};


// expands the 32 bit input to a 48 bit
// using the table E bit-selection table
uint64_t expansion(uint32_t input){
	
}

uint32_t substitution(uint64_t input){

}

uint64_t permutation(uint64_t input, const uint32_t* table){
	uint64_t output = 0;
	for(short i = 0; i < 56; i++){
		output |= ((input >> (64 - table[i])) & 1) << (55-i);
	}
	return  output;
}

uint32_t binToDec(uint64_t input){
	uint32_t value = 0;
	uint8_t i = 0;
	while(input != 0){
		value += (input & 1) * pow(2, i);
		i++;
		value = value >> 1;
	} return value;
}

uint64_t decToBin(uint32_t dec){
		
}

uint8_t sTable(int table_number, int y, int x){
	switch (table_number) {
		case(0): return S1[y][x];
		case(1): return S2[y][x];
		case(2): return S3[y][x];
		case(3): return S4[y][x];
		case(4): return S5[y][x];			
		case(5): return S6[y][x];
		case(6): return S7[y][x];
		case(7): return S8[y][x];
		default: return 0;
	}
}

uint32_t feistelSubFunction(uint64_t block_48Bit){
	// I am hard codeing this to avoid thinking
	uint32_t value = 0;
	// the s subfunctions
	for(int i = 0; i < 8; i++){
		// the first 2 bits as a decimal number
		int y = binToDec((block_48Bit >> (30-4*i)) & 3); 
		// the 3-6 bits as a decimal
		int x = binToDec((block_48Bit >> (26-4*i)) & 15);
		int s_table_value = decToBin(sTable(i, y, x));
		// INITED TO ALL ZEROS
		value = value & s_table_value;
		value = value << 4;
	}
	return  value;
}

uint64_t feistel(uint32_t r, uint64_t k){
	uint64_t E_48Bit = expansion(r);
	uint64_t xored_48Bit = E_48Bit ^ k;
	uint64_t s_32Bit = feistelSubFunction(xored_48Bit);
	return permutation(s_32Bit, &P_TABLE);
}
