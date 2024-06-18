#include "big_int.h"

void add_big_int(uint64_t* res, const uint64_t* num1, const uint64_t* num2, const uint32_t parts)
{
	uint32_t i = 0;
	uint64_t j = 0;
	uint64_t k = 0;
	uint64_t carry=0;
	for(i = 0; i < parts; i++)
	{
		// TODO: Do I need to do this in 2 halves? Could just find the carry first and then do a single addition
		j = (num1[i] & 0xffffffff) + (num2[i] & 0xffffffff) + carry;
		
		// TODO: Mask probably not needed here
		k = ((num1[i]>>32) & 0xffffffff) + ((num2[i]>>32) & 0xffffffff) + ((j>>32) & 0xffffffff);
				
		carry = ((k>>32) & 0xffffffff);
		
		res[i] = ((k & 0xffffffff)<<32)  | (j & 0xffffffff);
	}
	res[i] = carry;
} 

uint8_t sub_big_int(uint64_t* res, const uint64_t* num1, const uint64_t* num2, const uint32_t parts)
{
	uint8_t carry = 0;
	uint32_t i;
	for(i = 0; i < parts; i++)
	{

		// do opeartions on 32-bit parts 
		uint64_t temp1 = 0;
		uint32_t aux1 = num1[i] & 0xffffffff;
		uint32_t aux2 = num2[i] & 0xffffffff;

		//if(aux1 - carry < aux2 || aux1 < aux2) {
		if(aux1 - carry < aux2 || (aux1 == 0 && carry == 1)) {
			temp1 = (aux1 | 0x100000000) - carry;
			carry = 1;
		} else {
			temp1 = aux1 - carry;
			carry = 0;
		}

		temp1 -= aux2;

		uint64_t temp2 = 0;

		aux1 = num1[i] >> 32;
		aux2 = num2[i] >> 32;

		if(aux1 - carry < aux2 || (aux1 == 0 && carry == 1)) {
			temp2 = (aux1 | 0x100000000) - carry;
			carry = 1;
		} else {
			temp2 = aux1 - carry;
			carry = 0;
		}

		temp2 -= aux2;

		res[i] = (temp2 << 32) | temp1;


		/*if(carry)
		{
			if(num1[i] != 0)
				carry = 0;
			num1[i] -= carry;		
		}
		if(num1[i] < num2[i])
			carry = 1;
			
		res[i] = num1[i] - num2[i];*/
	}	
	return carry;
}

void print_big_int(const uint64_t* num, uint32_t parts)
{
	uint32_t i;
	uint8_t ignore_zeroes = true;
	printf("0x");
	for(int i = parts - 1; i >= 00; i--) {
		if(num[i] == 0 && ignore_zeroes)
			continue;
		ignore_zeroes = false;
		printf("%016lX ", num[i]);
	}
	if(ignore_zeroes) {
		printf("0");
	}
	printf("\n");
}


