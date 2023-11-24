#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void sha1_hash(const char *input, char *output) {
    SHA_CTX sha_ctx;
    unsigned char hash[SHA_DIGEST_LENGTH];

    SHA1_Init(&sha_ctx);
    SHA1_Update(&sha_ctx, input, strlen(input));
    SHA1_Final(hash, &sha_ctx);l?,pl

    for (int i = 0; i < SHA_DIGEST_LENGTH; i++) {
        sprintf(output + 2 * i, "%02x", hash[i]);
    }
    output[2 * SHA_DIGEST_LENGTH] = '\0';
}

int main() {
    char input[] = "Hello, World!";
    char output[2 * SHA_DIGEST_LENGTH + 1];

    sha1_hash(input, output);

    printf("Input: %s\n", input);
    printf("SHA-1 Hash: %s\n", output);

    return 0;
}
