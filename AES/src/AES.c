#include "AES.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <getopt.h>
#include <err.h>

enum state { ECB, CBC, OFB, GCM };

struct Varopt {
    bool verbose;
    bool all;
    bool unique;
    int grid_size;
    bool ecb;
    FILE *Outputfile;
    char *Inputfile;
    enum state mode;
};

struct Varopt opt = {false, false, false, 4, true, NULL, NULL, ECB};

int main(int argc, char *argv[]) {
    int option;

    while (1) {
        static struct option long_options[] = {
            {"help", no_argument, 0, 'h'},
            {"verbose", no_argument, 0, 'v'},
            {"output", required_argument, 0, 'o'},
            {"all", no_argument, 0, 'a'},
            {"ecb", optional_argument, 0, 'e'},
            {"cbc", optional_argument, 0, 'c'},
            {"ofb", optional_argument, 0, 'f'},
            {"gcm", optional_argument, 0, 'g'},
            {0, 0, 0, 0}};

        int option_index = 0;
        option = getopt_long(argc, argv, "hvo:aug::", long_options, &option_index);

        if (option == -1)
            break;

        switch (option) {
        case 'h':
            printf("Help message: Usage instructions go here.\n");
            exit(EXIT_SUCCESS);

        case 'v':
            opt.verbose = true;
            printf("Verbose mode on\n");
            break;

        case 'o':
            opt.Outputfile = fopen(optarg, "w");
            if (opt.Outputfile == NULL) {
                errx(EXIT_FAILURE, "Error opening output file\n");
            }
            break;

        case 'a':
            opt.all = true;
            break;

        case 'e':
            opt.mode = ECB;
            break;

        case 'c':
            opt.mode = CBC;
            break;

        case 'f':
            opt.mode = OFB;
            break;

        case 'g':
            opt.mode = GCM;
            break;

        case 'u':
            opt.unique = true;
            break;

        case '?':
        default:
            errx(EXIT_FAILURE, "Invalid option\n");
            break;
        }
    }

    // Check the selected mode
    if (opt.mode == ECB) {  // ECB mode
        printf("mode ECB\n");
    } else {  // Other modes
        printf("mode générateur\n");
    }

    exit(EXIT_SUCCESS);
}