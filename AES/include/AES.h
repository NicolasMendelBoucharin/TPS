#ifndef AES_H
#define AES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <getopt.h>
#include <stdbool.h>
#include <time.h>
#include <err.h>
#include "cipher.h"
#include "parser.h"

void print_text_hexa(uint8_t *input, int TextSize);

#endif /* AES */