// source
// https://en.wikipedia.org/wiki/Data_Encryption_Standard
// https://csrc.nist.gov/files/pubs/fips/46-3/final/docs/fips46-3.pdf
// http://orion.towson.edu/~mzimand/cryptostuff/DES-tables.pdf

#include <stdint.h>
#include <stdlib.h>

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

// expands the 32 bit input to a 48 bit
// using the table E bit-selection table
uint64_t expansion(uint32_t input){
	
}

uint32_t substitution(uint64_t input){

}

uint64_t permutation(uint64_t input, const int* table){
	uint64_t output = 0;
	for(short i = 0; i < 56; i++){
		output |= ((input >> (64 - table[i])) & 1) << (55-i);
	}
	return  output;
}

uint64_t feistel(uint32_t R, uint64_t K){
	uint64_t E48Bit = expansion(R);

}
