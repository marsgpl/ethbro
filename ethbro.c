#import "ethbro.h"

int main() {
    unsigned char hex[256];
    unsigned char bin[256];

    unsigned char example_pk_bin[ETH_PRIVATE_KEY_BIN_LEN];
    unsigned char example_pub_bin[ETH_PUBLIC_KEY_BIN_LEN];
    unsigned char example_addr_bin[ETH_ADDRESS_BIN_LEN];

    hex_to_bin((const unsigned char *)ETH_PRIVATE_KEY_EXAMPLE, example_pk_bin, ETH_PRIVATE_KEY_HEX_LEN);
    hex_to_bin((const unsigned char *)ETH_PUBLIC_KEY_EXAMPLE, example_pub_bin, ETH_PUBLIC_KEY_HEX_LEN);
    hex_to_bin((const unsigned char *)ETH_ADDRESS_EXAMPLE, example_addr_bin, ETH_ADDRESS_HEX_LEN);

    unsigned char current_pk_bin[ETH_PRIVATE_KEY_BIN_LEN] = {
        0xf4,0xa2,0xb9,0x39,0x59,0x25,0x64,0xfe,0xb3,0x5a,
        0xb1,0x0a,0x8e,0x04,0xf6,0xf2,0xfe,0x09,0x43,0x57,
        0x9f,0xb3,0xc9,0xc3,0x35,0x05,0x29,0x89,0x78,0xb7,
        0x48,0x93
    };
    unsigned char current_pub_bin[ETH_PUBLIC_KEY_BIN_LEN];
    unsigned char current_addr_bin[ETH_ADDRESS_BIN_LEN];

    secp256k1_pubkey pubkey;
    size_t pubkey_len = ETH_PUBLIC_KEY_BIN_LEN;
    secp256k1_context* ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN);
    assert(secp256k1_ec_pubkey_create(ctx, &pubkey, current_pk_bin));
    assert(secp256k1_ec_pubkey_serialize(ctx, current_pub_bin, &pubkey_len, &pubkey, SECP256K1_EC_UNCOMPRESSED));
    secp256k1_context_destroy(ctx);

    keccak(current_pub_bin + 1, ETH_PUBLIC_KEY_BIN_LEN - 1, bin, KECCAK_BIN_LEN);
    memcpy(current_addr_bin, bin + 12, ETH_ADDRESS_BIN_LEN);

    char pk_neq = memcmp(example_pk_bin, current_pk_bin, ETH_PRIVATE_KEY_BIN_LEN);
    char pub_neq = memcmp(example_pub_bin, current_pub_bin, ETH_PUBLIC_KEY_BIN_LEN);
    char addr_neq = memcmp(example_addr_bin, current_addr_bin, ETH_ADDRESS_BIN_LEN);

    bin_to_hex(example_pk_bin, hex, ETH_PRIVATE_KEY_BIN_LEN);
    printf("example pk = %.*s\n", ETH_PRIVATE_KEY_HEX_LEN, hex);
    bin_to_hex(current_pk_bin, hex, ETH_PRIVATE_KEY_BIN_LEN);
    printf("current pk = %.*s\n", ETH_PRIVATE_KEY_HEX_LEN, hex);
    printf("             %s\n\n", pk_neq ? "Not equal" : "EQUAL");

    bin_to_hex(example_pub_bin, hex, ETH_PUBLIC_KEY_BIN_LEN);
    printf("example pub = %.*s\n", ETH_PUBLIC_KEY_HEX_LEN, hex);
    bin_to_hex(current_pub_bin, hex, ETH_PUBLIC_KEY_BIN_LEN);
    printf("current pub = %.*s\n", ETH_PUBLIC_KEY_HEX_LEN, hex);
    printf("              %s\n\n", pub_neq ? "Not equal" : "EQUAL");

    bin_to_hex(example_addr_bin, hex, ETH_ADDRESS_BIN_LEN);
    printf("example addr = %.*s\n", ETH_ADDRESS_HEX_LEN, hex);
    bin_to_hex(current_addr_bin, hex, ETH_ADDRESS_BIN_LEN);
    printf("current addr = %.*s\n", ETH_ADDRESS_HEX_LEN, hex);
    printf("               %s\n\n", addr_neq ? "Not equal" : "EQUAL");

    return 0;
}
