#include <processing.h>
#include <permutation.h>

state_t set_initial_state (const uint64_t key[2], const uint64_t nonce[2], const uint64_t iv){
    /* TODO
    on prends S=IV||key||nonce
    on fait S<-p^a(S) xor (O^{320-k}||K)
    */
    state_t S = malloc(5 * sizeof(uint64_t));
    S[0] = iv;
    S[1] = key[0];
    S[2] = key[1];
    S[3] = nonce[0];
    S[4] = nonce[1];
    permutation(S,  a);
    S[3] ^= key[0];
    S[4] ^= key[1];
    return S;
    
}

void processing_associate_data(state_t S, msg_t A){
    // je n'ai pas fait les sous cas avec A vide
   for (int i = 0; i < A.nb_blocks; i++){
       S[0] ^= A.blocks[i];
       permutation(S, b);
       
   } 
   S[4] ^= 0x0000000000000001;
   
}

