#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <stdbool.h>
#include <err.h>
#include "cipher.h"

void parser_encrypt(FILE* input_file, FILE* output_file, uint8_t *key);
void parser_decrypt(FILE* input_file, FILE* output_file, uint8_t *key);
#endif /* AES */