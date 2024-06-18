#include "big_int.h"

int main()
{
	// 222263634737534342545647476578486746048699597695765
	uint64_t num1[PARTS] = {0x7911CDDB4DC1AB15, 0xFFF9EC7DADC6CE93, 0x98143614BF};
	// 99887123823483773727299856736379865747385858323434
	uint64_t num2[PARTS] = {0xD0B27D55045AF3EA, 0xFA90950F22E67D50, 0x4458758B03};


	uint64_t num3[PARTS] = {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0x1};
	uint64_t num4[PARTS] = {0x1};
	uint64_t num5[PARTS] = {0x0, 0x0, 0x1};
	uint64_t result[PARTS + 1];
	add_big_int(result, num1, num2, PARTS);

	//print_big_int(num1, PARTS);
	//print_big_int(num2, PARTS);
	print_big_int(result, PARTS + 1);

	add_big_int(result, num3, num4, PARTS);
	print_big_int(result, PARTS  + 1);

	printf("Sub return: %d\n", sub_big_int(result, num1, num2, PARTS));
	print_big_int(result, PARTS + 1);

	sub_big_int(result, num5, num4, PARTS);
	print_big_int(num5, PARTS);
	print_big_int(result, PARTS + 1);

	return 0;
}
