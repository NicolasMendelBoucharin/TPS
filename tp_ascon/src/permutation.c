#include <error.h>
#include <processing.h>
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
    s[2] ^= round_constants[12 - rnd +i]; //avec 6 et 12 pas besoin de se casser la tête avec des sous cas
    
}

void sbox(state_t s){
    //J'ai récopié bétement le truc de la partie 7
    s[0] ^= s[4];
    s[4] ^= s[3];
    s[2] ^= s[1];
    uint64_t* t = malloc(2 * sizeof(uint64_t));
    t[0] = s[0] & (~s[4]);
    t[1] = s[2] & (~s[1]);
    s[0] ^= t[1];
    t[1] =s[4] & (~s[3]);
    s[2] ^= t[1];
    t[1] = s[1] & (~s[0]);
    s[4] ^= t[1];
    t[1] = s[3] & (~s[2]);
    s[1] ^= t[1];
    s[3] ^= t[0];
    s[1] ^= s[0];
    s[3] ^= s[2];
    s[0] ^= s[4];
    s[2] = (~s[2]);
    
}

uint64_t rotate_right(uint64_t x, int n){
    //sous fonction pour le >>>
    return (x >> n) | (x << (64 - n));
}

void linear_layer(state_t s){
    
    s[0] = s[0] ^ rotate_right(s[0], 19) ^ rotate_right(s[0], 28);
    s[1] = s[1] ^ rotate_right(s[1], 61) ^ rotate_right(s[1], 39);
    s[2] = s[2] ^ rotate_right(s[2], 1) ^ rotate_right(s[2], 6);
    s[3] = s[3] ^ rotate_right(s[3], 10) ^ rotate_right(s[3], 17);
    s[4] = s[4] ^ rotate_right(s[4], 7) ^ rotate_right(s[4], 41);
    
}

void permutation(state_t s, int nb_rounds){
    //j'ai pas compris à quoi il servait le paramètre r
    for (int i=0; i < nb_rounds; i++){
        add_constants(s,i,nb_rounds);
        sbox(s);
        linear_layer(s);
    }

}
