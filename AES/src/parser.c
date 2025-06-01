#include "parser.h"
#include "AES.h"
#include "cipher.h"

void parser_encrypt(FILE* input_file, FILE* output_file, uint8_t *key){
    uint8_t input[16] =  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    uint8_t output[16] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    long i = 0; //où on en est dans le fichier d'entrée
    int pad = 0;
    int left = 0;

    //taille du fichier d'entrée
    fseek(input_file,0,SEEK_END);
    long input_size = ftell(input_file);
    fseek(input_file,0,SEEK_SET);

    //nouvelle clé etendue
    uint8_t w[176];
    KeyExpansion(key, w); 

    //là pas encore besoin de padding
    //on lit 16 octets à la fois

    while(i + 16 <= input_size){
        fread(input, 1, 16, input_file); 
        cipher_block(input, output, w);
        fwrite(output, 1, 16, output_file); 
        i += 16;
    }

    left = (16 + input_size - i)%16; //on cherche combien il reste d'octets à lire (pad) et on complete avec 0xpad en gros
    pad = 16 - left;
    if(left == 0){
        for(int i = 0; i < 16; i++){
            input[i] = (uint8_t) 0xf;
        }
    }
    else{
        fread(input, 1, left, input_file);
        for(int i = 0; i < pad; i++){
            input[15-i] = (uint8_t) pad;
        }
    }

    cipher_block(input, output, w);
    fwrite(output, 1, 16, output_file);
}

//normalement on a que des trucs de la bonne taille
void parser_decrypt(FILE* input_file, FILE* output_file, uint8_t *key){

    uint8_t input[16] =  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    uint8_t output[16] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    long i = 0;
    
    
    fseek(input_file,0,SEEK_END);
    long input_size = ftell(input_file);
    fseek(input_file,0,SEEK_SET);

    
    uint8_t w[176]; 
    KeyExpansion(key, w);

    while(i + 16 < input_size){
        fread(input, 1, 16, input_file);
        decipher_block(input, output, w); 
        
        fwrite(output, 1, 16, output_file); 
        i += 16;
    }

    fread(input,1,16,input_file);
    decipher_block(input, output, w);
    //on a fait en sorte que le dernier octet nous donne la taille des trucs à enlever donc on les rajoute pas
    fwrite(output, 1, 16-output[15] ,output_file);

}