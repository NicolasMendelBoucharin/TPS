#include <error.h>

#include "processing.h"
#include "permutation.h"



ciphertext_t ASCON_128_encrypt (const uint64_t K[2], const uint64_t N[2], msg_t A, msg_t P){
    /* TODO */
}

msg_t ASCON_128_decrypt (const uint64_t K[2], const uint64_t N[2], msg_t A, ciphertext_t C){
    /* TODO */
}

int main(){

    uint64_t nonce[2] = {0x72c709d9fbe557d2, 0x330ceb13b45588f4};
    uint64_t key[2] = {0x2de975d881700ec6, 0x5b8e869b4695d832};
    uint64_t P[2] = {0x1234567890abcdef, 0x1234567890abcdef};
    uint64_t A[3] = {0x787878, 0x878787, 0x090909};

    printf("%lu %lu\n", P[0], P[1]);
    msg_t plaintext = {P, 2};
    msg_t associated_data = {A, 3};

    ciphertext_t cipher = ASCON_128_encrypt(key, nonce, associated_data, plaintext);

    ciphertext_t expected_cipher;
    expected_cipher.C.blocks = calloc(2, sizeof(uint64_t));
    expected_cipher.C.nb_blocks = 2;
    expected_cipher.C.blocks[0] = 0x13baf10abb21567e;
    expected_cipher.C.blocks[1] = 0xc56fb73a9b53b451;
    expected_cipher.T[0] = 0x968bee0e7f444d6a;
    expected_cipher.T[1] = 0x9904c411b4c2d8d5;

    // Checking resulting ciphertext & tag 
    if (cipher.C.blocks[0] != expected_cipher.C.blocks[0])
        error(EXIT_FAILURE, 0, "Error during encrpytion: first block of cipher");

    if (cipher.C.blocks[1] != expected_cipher.C.blocks[1])
        error(EXIT_FAILURE, 0, "Error during encrpytion: second block of cipher");

    if (cipher.T[0] != expected_cipher.T[0])
        error(EXIT_FAILURE, 0, "Error during encrpytion: first block of tag");

    if (cipher.T[1] != expected_cipher.T[1])
        error(EXIT_FAILURE, 0, "Error during encrpytion: second block of tag");

    msg_t decrypted_plaintext = ASCON_128_decrypt(key, nonce, associated_data, cipher);
    if (decrypted_plaintext.nb_blocks == 0)
        error(EXIT_FAILURE, 0, "Error during decryption");

    printf("%lu %lu\n", decrypted_plaintext.blocks[0], decrypted_plaintext.blocks[1]);
}