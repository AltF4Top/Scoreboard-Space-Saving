#ifndef __TDY_SSH_CBF_CONFIG_HPP__
#define __TDY_SSH_CBF_CONFIG_HPP__

#include <cmath>

#define FREQ
#define PR
/*
#ifdef  FREQ

#define phi (0.0010)
//#define K	(unsigned int)(0.1 / phi)
#define K (1000)

#else

#define K	(300)

#endif

// K < 1000
#define SSH_HEAPSIZE	(K)
#define SS_HEAPSIZE		(K)

#define CBF_NCNTR	(30 * SSH_CBF_QLEN)
#define CBF_NHF		(3)
#define CBF_NBITS	(12)

// QLEN < 1000
#define SSH_CBF_QLEN	(K)
#define SSH_CBF_m	(10)
//#define SSH_CBF_M	(3000)
//#define SSH_CBF_M	((uint32_t)(107283/pow(K, 0.668)))
*/


#ifdef  FREQ

const double phi = 0.0001;
const uint32_t K = (uint32_t)(pow(0.0107283/phi, 1/0.668));

#else

const uint32_t K = (300);

#endif

const uint32_t SSH_HEAPSIZE = K;
const uint32_t SS_HEAPSIZE = 2 * K;

const uint32_t SSH_CBF_m = 15;
//const uint32_t SSH_CBF_M = ((uint32_t)(107283/pow(K, 0.668)));
const uint32_t SSH_CBF_QLEN = (uint32_t)(1 / phi);

const uint32_t CBF_NCNTR = (30 * SSH_CBF_QLEN);
const uint32_t CBF_NHF = (3);
const uint32_t CBF_NBITS =(12);

#endif
