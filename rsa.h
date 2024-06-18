/*
 * rsa.h
 *
 *  Created on: 09-May-2017
 *      Author: navin
 *
 *  Modified on: 17-Jun-2024 
 *  	Author: 
 */

#ifndef RSA_H_
#define RSA_H_

#include <stdbool.h>
#include <stdint.h>


bool rsa1024(uint64_t res[], uint64_t data[], uint64_t expo[],uint64_t key[]);


#endif /* RSA_H_ */
