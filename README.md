# Ethbro

## Init

    mkdir vendor
    cd vendor
    git clone git@github.com:bitcoin-core/secp256k1.git
    cd secp256k1

Then follow instructions: <https://github.com/bitcoin-core/secp256k1#build-steps>

## Build

    make

## Start

    ./ethbro

## Sample output

    example pk = f4a2b939592564feb35ab10a8e04f6f2fe0943579fb3c9c33505298978b74893
    current pk = f4a2b939592564feb35ab10a8e04f6f2fe0943579fb3c9c33505298978b74893
                 EQUAL

    example pub = 04345f1a86ebf24a6dbeff80f6a2a574d46efaa3ad3988de94aa68b695f09db9ddca37439f99548da0a1fe4acf4721a945a599a5d789c18a06b20349e803fdbbe3
    current pub = 04345f1a86ebf24a6dbeff80f6a2a574d46efaa3ad3988de94aa68b695f09db9ddca37439f99548da0a1fe4acf4721a945a599a5d789c18a06b20349e803fdbbe3
                  EQUAL

    example addr = d5e099c71b797516c10ed0f0d895f429c2781142
    current addr = d5e099c71b797516c10ed0f0d895f429c2781142
                   EQUAL
