#ifndef FLAG_H_
#define FLAG_H_

#define FLAG_D (1u << 0u)
#define FLAG_T (1u << 1u)
#define FLAG_C (1u << 2u)
#define FLAG_P (1u << 3u)
#define FLAG_W (1u << 4u)
#define FLAG_L (1u << 5u)

#define FLAG_EMPTY 0u
#define FLAG_SAFE (FLAG_D  | FLAG_T | FLAG_C)
#define FLAG_AGGRESSIVE (FLAG_P | FLAG_W | FLAG_L)
#define FLAG_ALL (FLAG_SAFE | FLAG_AGGRESSIVE)

#define FLAG_REGISTER(mask) flag_Bits |= mask
#define FLAG_SET(mask) flag_Bits = 0u; FLAG_REGISTER(mask)
#define FLAG_ISSET(mask) flag_Bits & mask

unsigned flag_Bits;

#endif