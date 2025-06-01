#include "AES.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <getopt.h>
#include <err.h>
uint8_t defaultkey[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
uint8_t defaultplaintext[16]={0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34};

void print_text_hexa(uint8_t *input, int TextSize)
{
    printf("Bloc obtenu : \n");
    for (int i = 0; i < TextSize; i++)
    {
        printf("0x%02x \n", input[i]);
    }
}

struct Varopt {
    bool test;
    FILE *Outputfile;
    char *Inputfile;

};

struct Varopt opt = {false, NULL, NULL};

int main(){
//tests
    uint8_t cipher[16];
    uint8_t expended_key[44];
    KeyExpansion(defaultkey, expended_key);
    cipher_block(defaultplaintext, cipher, expended_key);
    printf("chiffement \n");
    print_text_hexa(cipher, 16);

    uint8_t decipher[16];
    decipher_block(cipher, decipher, expended_key);
    printf("dechiffrement \n");
    print_text_hexa(decipher, 16);
    return 0;
   
}