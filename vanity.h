#import <stdio.h>
#import <stdint.h>
#import <string.h>
#import <secp256k1.h>

#import "eth.h"
#import "hex.h"
#import "keccak.h"
#import "fill_random.h"

static inline int same(const unsigned char *s1, const unsigned char *s2, size_t len);

unsigned char addr_start[] = { 0xDE, 0xAD };
