#import <stdint.h>
#import <stdio.h>

static const char hexes[] = "0123456789abcdef";

void hex_to_bin(const char *hex, char *bin, const uint8_t hex_len);
void bin_to_hex(const char *bin, char *hex, const uint8_t bin_len);
