#ifndef CIPER_H
#define CIPER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <stdbool.h>
#include <err.h>
#include <stdint.h>



uint8_t get_sbox_value(uint8_t n);
uint8_t get_inv_sbox_value(uint8_t n);
void sub_bytes(uint8_t state[4][4]);
void inv_sub_bytes(uint8_t state[4][4]);
void shift_row(uint8_t state[4][4]);
void inv_shift_row(uint8_t state[4][4]);
uint8_t foisX(uint8_t a);
uint8_t mul(uint8_t a, uint8_t b);
void mix_column(uint8_t state[4][4]);
void mix_column_inv(uint8_t state[4][4]);
void add_round_key(uint8_t state[4][4], uint8_t* round_key, int round);
void RotWord(uint8_t word[4]);
void subWord(uint8_t word[4]);
void KeyExpansion(uint8_t* key, uint8_t* expanded_key);
void cipher_block(uint8_t* input, uint8_t* output, uint8_t* expanded_key);
void decipher_block(uint8_t* input, uint8_t* output, uint8_t* expanded_key);

#endif /* AES */