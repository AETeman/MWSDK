/*
 * randMT.h
 *
 *  Created on: 2013/01/17
 *      Author: seigo13
 */

#ifndef RANDMT_H_
#define RANDMT_H_

#include <jendefs.h>

void MTRND_vInitSeed(uint32 s);
void MTRND_vInitSeedArray(uint32 init_key[], int key_length);
uint32 MTRND_u32GenRnd(void);

#endif /* RANDMT_H_ */
