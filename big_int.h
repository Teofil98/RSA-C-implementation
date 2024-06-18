#ifndef BIG_INT_H
#define BIG_INT_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#define INT_WIDTH 2048
#define PARTS 	  32


void add_big_int(uint64_t* res, const uint64_t* num1, const uint64_t* num2, const uint32_t parts);
// TODO: Should I handle the case when num1 < num2 to give a valid result?
//
/****************************************************************
 * result = num1 - num2
 * returns 0 if num1 >= num2
 * 		   1 if num1 <  num2
 * result is not valid if return value is 1 (or is in 2's compliment :P)
 * **************************************************************/
uint8_t sub_big_int(uint64_t* res, const uint64_t* num1, const uint64_t* num2, const uint32_t n);
void print_big_int(const uint64_t* num, const uint32_t parts);

bool mod_big_int(uint64_t res[],uint64_t num1[], uint64_t num2[],uint32_t n);
bool modnum(uint64_t res[],uint64_t num1[], uint64_t num2[],uint32_t n);
bool modmult1024(uint64_t res[], uint64_t num1[], uint64_t num2[],uint64_t mod[]);
bool mult_big_int(uint64_t res[], uint64_t num1[], uint32_t num2 ,uint32_t n);
uint32_t bit_length(uint64_t num[],uint32_t n);
int32_t compare(uint64_t num1[], uint64_t num2[],uint32_t n);
bool sln_big_int(uint64_t res[], uint64_t num[],uint32_t len, uint32_t n);//shift left by n
bool srn_big_int(uint64_t res[], uint64_t num[],uint32_t len, uint32_t n);


#endif
