// source
// https://en.wikipedia.org/wiki/Data_Encryption_Standard
//

#include <stdint.h>
#include <stdio.h>
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

//
//Takes in a 32 bit Halfblock and the subkey
// returns the 
char* des(char* message, uint64_t key){

}

uint64_t permutation(uint64_t input, const int* table){
	uint64_t output = 0;
	for(short i = 0; i < 56; i++){
		output |= ((input >> (64 - table[i])) & 1) << (55-i);
	}
	return  output;
}
