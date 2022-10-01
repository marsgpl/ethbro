#import <stdint.h>
#import <stdio.h>

static const unsigned char hexes[] = "0123456789abcdef";

void hex_to_bin(const unsigned char *hex, unsigned char *bin, const uint8_t hex_len);
void bin_to_hex(const unsigned char *bin, unsigned char *hex, const uint8_t bin_len);
