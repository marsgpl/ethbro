#import "vanity.h"

int main() {
    unsigned char hex[256];
    unsigned char pk[ETH_PRIVATE_KEY_BIN_LEN];
    unsigned char pub[ETH_PUBLIC_KEY_BIN_LEN];
    unsigned char hash[KECCAK_BIN_LEN];
    unsigned char addr[ETH_ADDRESS_BIN_LEN];

    secp256k1_pubkey pubkey;
    size_t pubkey_len = ETH_PUBLIC_KEY_BIN_LEN;
    secp256k1_context* ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN);
    int r;

    size_t iterations = 0;

    while (1) {
        iterations++;

        fill_random(pk, ETH_PRIVATE_KEY_BIN_LEN);

        r = secp256k1_ec_pubkey_create(ctx, &pubkey, pk);
        if (!r) { printf("oops\n"); break; }

        secp256k1_ec_pubkey_serialize(ctx, pub, &pubkey_len, &pubkey, SECP256K1_EC_UNCOMPRESSED);

        keccak(pub + 1, ETH_PUBLIC_KEY_BIN_LEN - 1, hash, KECCAK_BIN_LEN);

        if (same(hash + 12, addr_start, sizeof addr_start)) {
            bin_to_hex(pk, hex, ETH_PRIVATE_KEY_BIN_LEN);
            printf("private key: 0x%.*s\n", ETH_PRIVATE_KEY_HEX_LEN, hex);

            memcpy(addr, hash + 12, ETH_ADDRESS_BIN_LEN);
            bin_to_hex(addr, hex, ETH_ADDRESS_BIN_LEN);
            printf("address: 0x%.*s\n", ETH_ADDRESS_HEX_LEN, hex);

            break;
        }

        if (iterations % 10000 == 0) {
            printf("iterations: %ld\n", iterations);
        }
    }

    secp256k1_context_destroy(ctx);

    printf("iterations: %ld\n", iterations);

    return 0;
}

static inline int same(const unsigned char *s1, const unsigned char *s2, size_t len) {
    for (int i = 0; i < len; i++) {
        if (s1[i] != s2[i]) {
            return 0;
        }
    }

    return 1;
}
