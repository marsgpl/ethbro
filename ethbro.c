#import "ethbro.h"

int main() {
    char bin[ETH_PKEY_BIN_LEN];
    char hex[ETH_PKEY_HEX_LEN];

    hex_to_bin(ETH_MAGIC_PKEY, bin, ETH_PKEY_HEX_LEN);
    bin_to_hex(bin, hex, ETH_PKEY_BIN_LEN);

    printf("ref = %.*s\n", ETH_PKEY_HEX_LEN, ETH_MAGIC_PKEY);
    printf("bin = %.*s\n", ETH_PKEY_BIN_LEN, bin);
    printf("hex = %.*s\n", ETH_PKEY_HEX_LEN, hex);

    return 0;
}
