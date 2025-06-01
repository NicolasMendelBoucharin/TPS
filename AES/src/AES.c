#include "AES.h"


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



int testfacile(){
    uint8_t text_du_nist[16] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff};
    uint8_t key_du_nist[16] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f};
    uint8_t test[16];
    uint8_t expended_key[176];
    KeyExpansion(key_du_nist, expended_key);
    cipher_block(text_du_nist, test, expended_key);
    printf("chiffement \n");
    print_text_hexa(test, 16);

    uint8_t test2[16];
    decipher_block(test, test2, expended_key);
    printf("dechiffrement \n");
    print_text_hexa(test2, 16);
    return 0;
}


void aide(){   
    printf("Usage :\t main [-c FILE|-d FILE|-o FILE|-k clé|-t|-h] ...\n");
    printf("-c : chiffre le fichier en entrée \n");
    printf("-d : déchiffre le fichier en entrée \n");
    printf("-o : choix du fichier \n");
    printf("-k : clé à entrée par l'utilisateur pour chiffrer avec celle-ci \n");
    printf("-t : chiffre 100 fois alice.txt\n");
    printf("-h : affiche l'aide \n");
}

int main(int argc, char *argv[]){
    int opt;                              
	int ciph=0;				          
	int deciph=0;                         
	int flag_o=0;                         
	int test=0;                                                                                                              
    FILE* output_file = fopen("ciphered.txt", "wb");  
	FILE* input_file = NULL;   


    


    static struct option long_options[] ={                 
		{"chiffre FILE", required_argument, NULL, 'c'},
		{"dechiffre FILE", required_argument, NULL, 'd'},
		{"output FILE", required_argument, NULL, 'o'},
		{"test", no_argument, NULL, 't'},
		{"help", no_argument, 0,'h'},
		{0,0,0,0}
	};



    while ((opt = getopt_long(argc, argv, "+hd:c:d:o:t",long_options, NULL)) != -1) {        
		switch (opt) {
			
			case 'c':                                                   
				input_file = fopen(optarg,"rb");                        
				if (input_file==NULL){
					fprintf(stderr,"error fichier entree\n");
					exit(EXIT_FAILURE);
				}
				ciph=1;
				break;

			case 'd':                                                   
				input_file = fopen(optarg,"rb");                       
				output_file = fopen("decipher.txt", "wb");
				if (input_file==NULL){
					fprintf(stderr,"error fichier entree\n");
					exit(EXIT_FAILURE);
				}
				deciph=1;
				break;

			case 'o':
				output_file = fopen(optarg,"wb");                        
				flag_o=1;
				if (output_file==NULL){                      
					fprintf(stderr,"error fichier sortie\n");
					exit(EXIT_FAILURE);
				}
				break;
			


			case 't':
				input_file=fopen("alice.sage","rb");
                output_file=fopen("ciphered_alice.txt", "wb");   
                test=1;                    
				break;

			
			case 'h' :
				aide();        
				exit(EXIT_SUCCESS);

			case '?':
				fprintf(stderr, "option inconnue : %s \n", argv[optind-1]);  
				exit(EXIT_FAILURE);
		}
    }
    



	if(flag_o && test){
		printf("Pas besoin de fichier de sortie pour le test\n");
	}





	
	
      
	if(test){                                  
		clock_t start_time , end_time ;          
		double cpu_time;
		start_time=clock();
		for (int i=0 ; i<100 ; i++){
			parser_encrypt(input_file , output_file , defaultkey); 
		}
		end_time=clock();                                                               
		cpu_time= ((double)(end_time - start_time))/CLOCKS_PER_SEC;                     
		printf("Temps pour chiffrer 100 fois alice.txt : %f secondes\n" , cpu_time );  
	

	
    if(ciph){                                          
		parser_encrypt(input_file , output_file , defaultkey);  
    }




	if(deciph){                    
		parser_decrypt(input_file , output_file , defaultkey);  
    }
	

}
}