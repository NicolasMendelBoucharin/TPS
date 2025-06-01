#include "cipher.h"
#include "AES.h"

int Nk= 4;//key length
int Nb=4; //block size
int Nr= 10;//number of rounds

//Sbox du papier
const uint8_t sbox[256] = {
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5,
    0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0,
    0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc,
    0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a,
    0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0,
    0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b,
    0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85,
    0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5,
    0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17,
    0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88,
    0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c,
    0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9,
    0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6,
    0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e,
    0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94,
    0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68,
    0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
};


const uint8_t inv_sbox[256] = {
    0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38,
    0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
    0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87,
    0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
    0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d,
    0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
    0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2,
    0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
    0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16,
    0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
    0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda,
    0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
    0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a,
    0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
    0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02,
    0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
    0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea,
    0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
    0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85,
    0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
    0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89,
    0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
    0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20,
    0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
    0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31,
    0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
    0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d,
    0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
    0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0,
    0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
    0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26,
    0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d
};

const uint8_t galois[4][4] = {
    {0x02, 0x03, 0x01, 0x01},
    {0x01, 0x02, 0x03, 0x01},
    {0x01, 0x01, 0x02, 0x03},
    {0x03, 0x01, 0x01, 0x02}
};


const uint8_t galois_inv[4][4] = {
    {0x0e, 0x0b, 0x0d, 0x09},
    {0x09, 0x0e, 0x0b, 0x0d},
    {0x0d, 0x09, 0x0e, 0x0b},
    {0x0b, 0x0d, 0x09, 0x0e}
};





//fonctions auxilliaires pour être sûr de pas faire de de modif
uint8_t get_sbox_value(uint8_t n) {
    return sbox[n];
}

uint8_t get_inv_sbox_value(uint8_t n) {
    return inv_sbox[n];
}

//on applique à chaque cellule la transformation de la sbox
void sub_bytes(uint8_t state[4][4]) {
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            state[i][j] = get_sbox_value(state[i][j]);
        }
    }
}

//on applique à chaque cellule la transformation de la invsbox
void inv_sub_bytes(uint8_t state[4][4]) {
    for (int i = 0; i < 4; i++) {
        for( int j = 0; j < 4; j++) {
            state[i][j] = get_inv_sbox_value(state[i][j]);
        }
    }
}

//comme dans le papier (j'aurais pu utiliser moins de "temp")
void shift_row(uint8_t state[4][4]){
    uint8_t temp[4][4];
    for (int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            temp[i][j] = state[i][j];
        }
    }

    state[1][0] = temp[1][1];
    state[1][1] = temp[1][2];
    state[1][2] = temp[1][3];
    state[1][3] = temp[1][0];

    state[2][0] = temp[2][2];
    state[2][1] = temp[2][3];
    state[2][2] = temp[2][0];
    state[2][3] = temp[2][1];

    state[3][0] = temp[3][3];
    state[3][1] = temp[3][0];
    state[3][2] = temp[3][1];
    state[3][3] = temp[3][2];
}


void inv_shift_row(uint8_t state[4][4]) {
    uint8_t temp[4][4];
    for (int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            temp[i][j] = state[i][j];
        }
    }   
    
    state[1][0] = temp[1][3];
    state[1][1] = temp[1][0];
    state[1][2] = temp[1][1];
    state[1][3] = temp[1][2];

    state[2][0] = temp[2][2];
    state[2][1] = temp[2][3];
    state[2][2] = temp[2][0];
    state[2][3] = temp[2][1];

    state[3][0] = temp[3][1];
    state[3][1] = temp[3][2];
    state[3][2] = temp[3][3];
    state[3][3] = temp[3][0];
}

//comme dans le TP3 de crypto
uint8_t foisX(uint8_t a) {
    uint8_t result = a << 1; 
    uint8_t poids_fort = ((a>> 7) & 0x01);
    if (poids_fort == 1) {
        result ^= 0x1b; 
    }
    return result;
}

uint8_t mul(uint8_t a , uint8_t b){
    char S=a;
    char res= 0x00;
    
    for (int i = 0; i < 8; i++) {
        if (((b>>i)& 0x01) == 1) {
            res ^= S; 
        }
        S = foisX(S); 
        
    }
    return res;
}

//comme dans le papier
void mix_column(uint8_t state[4][4]) {
    for (int i = 0; i < 4; i++) {
        uint8_t temp0 = state[0][i];
        uint8_t temp1 = state[1][i];
        uint8_t temp2 = state[2][i];
        uint8_t temp3 = state[3][i];

      
        state[0][i]=(uint8_t)(mul(galois[0][0], temp0) ^ mul(galois[0][1], temp1) ^ mul(galois[0][2], temp2) ^ mul(galois[0][3], temp3));
        state[1][i] = (uint8_t)(mul(galois[1][0], temp0) ^ mul(galois[1][1], temp1) ^ mul(galois[1][2], temp2) ^ mul(galois[1][3], temp3));
        state[2][i] = (uint8_t)(mul(galois[2][0], temp0) ^ mul(galois[2][1], temp1) ^ mul(galois[2][2], temp2) ^ mul(galois[2][3], temp3));
        state[3][i] = (uint8_t)(mul(galois[3][0], temp0) ^ mul(galois[3][1], temp1) ^ mul(galois[3][2], temp2) ^ mul(galois[3][3], temp3));
       
    }
    
}


void mix_column_inv(uint8_t state[4][4]) {
    for (int i = 0; i < 4; i++) {
        uint8_t temp0 = state[0][i];
        uint8_t temp1 = state[1][i];
        uint8_t temp2 = state[2][i];
        uint8_t temp3 = state[3][i];

      
        state[0][i]=(uint8_t)(mul(galois_inv[0][0], temp0) ^ mul(galois_inv[0][1], temp1) ^ mul(galois_inv[0][2], temp2) ^ mul(galois_inv[0][3], temp3));
        state[1][i] = (uint8_t)(mul(galois_inv[1][0], temp0) ^ mul(galois_inv[1][1], temp1) ^ mul(galois_inv[1][2], temp2) ^ mul(galois_inv[1][3], temp3));
        state[2][i] = (uint8_t)(mul(galois_inv[2][0], temp0) ^ mul(galois_inv[2][1], temp1) ^ mul(galois_inv[2][2], temp2) ^ mul(galois_inv[2][3], temp3));
        state[3][i] = (uint8_t)(mul(galois_inv[3][0], temp0) ^ mul(galois_inv[3][1], temp1) ^ mul(galois_inv[3][2], temp2) ^ mul(galois_inv[3][3], temp3));
       
    }
}

//je suis vraiment vraiment pas sur de cete fonctoin mais j'ai pas le choix là 
void add_round_key(uint8_t state[4][4], uint8_t *round_key, int round) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            state[i][j] ^= round_key[round * Nb * 4 + i * Nb + j];
        }
    }
}

//on tourne
void RotWord(uint8_t word[4]) {
    uint8_t temp = word[0];
    for (int i = 0; i < 3; i++) {   
        word[i] = word[i + 1];
    }
    word[3] = temp;
    
}

//on fait la Sbox du mot
void subWord(uint8_t word[4]) {
    for (int i = 0; i < 4; i++) {
        word[i] = get_sbox_value(word[i]);
    }
}

uint8_t rcon(int i) {
    uint8_t X=0x02;
    uint8_t res = 0x01;
    if (i == 0) {
        return res;
    } else {
        for (int j = 0; j < i - 1; j++) {
            res = mul(X, res);
        }
    }
    return res;
}

void KeyExpansion(uint8_t* key, uint8_t* expanded_key) {
    
    int rcon_index = 0;
    int wanted_size = (Nb * (Nr + 1)); 
    
    for (int i =0; i<Nk; i++) {
        expanded_key[(i*4)]=key[i*4];
        expanded_key[(i*4)+1]=key[(i*4)+1];
        expanded_key[(i*4)+2]=key[(i*4)+2];
        expanded_key[(i*4)+3]=key[(i*4)+3];
        
    }
    int i= Nk;
    while (i < wanted_size) {
        uint8_t temp[4];
        int k=(i-1)*4;
        temp[0]=expanded_key[k];
        temp[1]=expanded_key[k+1];
        temp[2]=expanded_key[k+2];
        temp[3]=expanded_key[k+3];
        ;
        if(i% Nk ==0){
            rcon_index=i/Nk;
            RotWord(temp);
            subWord(temp);
            temp[0] ^= rcon(rcon_index);
            
        } else if (Nk > 6 && i % Nk == 4) {
            subWord(temp);
        } 
        for (int j = 0; j < 4; j++) {
            expanded_key[i * 4 + j] = expanded_key[(i - Nk) * 4 + j] ^ temp[j];
        }
        i++;
    }
    
    
}


void cipher_block(uint8_t* input, uint8_t* output, uint8_t* expanded_key) {
    uint8_t state[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            state[i][j] = input[i + j * 4];
        }
    }
    
    add_round_key(state, expanded_key, 0);

    for (int round = 1; round < Nr; round++) {
        sub_bytes(state);
        shift_row(state);
        mix_column(state);
        add_round_key(state, expanded_key, round);
    }

    sub_bytes(state);
    shift_row(state);
    add_round_key(state, expanded_key, Nr);

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < Nb; j++){
            output[i + 4*j] = state[i][j];
        }
    }
}

void decipher_block(uint8_t* input, uint8_t* output, uint8_t* expanded_key) {
    uint8_t state[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            state[i][j] = input[i + j * 4];
        }
    }

    add_round_key(state, expanded_key, Nr);
    for(int round = 1; round< Nr; round++){
        inv_shift_row(state);
        inv_sub_bytes(state);
        add_round_key(state, expanded_key, Nr-round);
        mix_column_inv(state);
    }
    inv_shift_row(state);
    inv_sub_bytes(state);
    add_round_key(state, expanded_key, 0);

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < Nb; j++){
            output[i + 4*j] = state[i][j];
        }
    }

}