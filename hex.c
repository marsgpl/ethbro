#import "hex.h"

void hex_to_bin(
    const unsigned char *hex,
    unsigned char *bin,
    const uint8_t hex_len
) {
    for (uint8_t i = 0, j = 0; i < hex_len; i += 2, j++) {
        bin[j] = (hex[i] % 32 + 9) % 25 * 16 + (hex[i+1] % 32 + 9) % 25;
    }
}

void bin_to_hex(
    const unsigned char *bin,
    unsigned char *hex,
    const uint8_t bin_len
) {
    unsigned char *out = &hex[0];

    for (uint8_t i = 0; i < bin_len; i++) {
        out += sprintf((char *)out, "%02x", bin[i]);
    }
}
