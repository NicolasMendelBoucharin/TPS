#include <error.h>

#include "processing.h"
#include "permutation.h"


const uint16_t round_constants[] = {0x00000000000000f0,
                                    0x00000000000000e1,
                                    0x00000000000000d2,
                                    0x00000000000000c3,
                                    0x00000000000000b4,
                                    0x00000000000000a5,
                                    0x0000000000000096,
                                    0x0000000000000087,
                                    0x0000000000000078,
                                    0x0000000000000069,
                                    0x000000000000005a,
                                    0x000000000000004b,
};


void add_constants (state_t s, int i, int rnd){
    /* TODO */
    return;
}

void sbox(state_t s){
    /* TODO */
    return;
}

void linear_layer(state_t s){
    /* TODO*/

    return;
}

void permutation(state_t s, int r, int nb_rounds){
    /* TODO */
    return;
}
