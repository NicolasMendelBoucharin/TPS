#include <processing.h>


state_t set_initial_state (const uint64_t key[2], const uint64_t nonce[2], const uint64_t IV){
    /* TODO
    on prends S=IV||key||nonce
    on fait S<-p^a(S) xor (O^{320-k}||K)
    */
    
}

state_t processing_associate_data(state_t S, msg_t A){
    /*TODO
    si A > 0
    on fait s blocks de r octets de A||1||0*
    pour i=0 à s - 1
        S <- p^b((S xor A[i])||S_c)
    S <- S xor (0^(319)||1)
    */
}

state_t processing_plaintext(state_t S, msg_t P){
    
}