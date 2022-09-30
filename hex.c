#import "hex.h"

void hex_to_bin(
    const char *hex,
    char *bin,
    const uint8_t hex_len
) {
    for (uint8_t i = 0, j = 0; i < hex_len; i += 2, j++) {
        bin[j] = (hex[i] % 32 + 9) % 25 * 16 + (hex[i+1] % 32 + 9) % 25;
    }
}

void bin_to_hex(
    const char *bin,
    char *hex,
    const uint8_t bin_len
) {
    char *out = &hex[0];

    for (uint8_t i = 0; i < bin_len; i++) {
        out += sprintf(out, "%02x", bin[i]);
    }
}
