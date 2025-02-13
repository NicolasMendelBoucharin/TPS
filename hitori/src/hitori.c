#include "hitori.h"
#include "DFS.h"
#include "generate.h"
#include "grid.h"
#include "grid_io.h"
#include "heuristics.h"

enum state { SOLVER, GENERATOR };
struct Varopt {
  bool verbose;
  bool all;
  bool unique;
  int grid_size;
  bool solver_mode;
  FILE *Outputfile;
  char *Inputfile;
  enum state mode;
};

struct Varopt opt = {false, false, false, 4, true, NULL, NULL, SOLVER};

int
main(int argc, char *argv[]) {
  int option;

  while (1) {
    static struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"verbose", no_argument, 0, 'v'},
        {"output", required_argument, 0, 'o'},
        {"all", no_argument, 0, 'a'},
        {"unique", no_argument, 0, 'u'},
        {"generate", optional_argument, 0, 'g'},
        {0, 0, 0, 0}};

    int option_index = 0;
    option = getopt_long(argc, argv, "hvo:aug::", long_options, &option_index);

    if (option == -1)
      break;
    switch (option) {
    case 'h':
      printf("Usage: \t hitori [-a|-o FILE|-v|-h] FILE\n"
             "\t \t hitori -gSIZE [-u|-o FILE|-v|-h]\n"
             "Solve or generate hitori grids of size : 3 to 15\n"
             "-a, --all \t search for all possible solutions\n"
             "-gN, --generate[=N] \t generate a grid of size N*N (default:4)\n"
             "-o FILE, --output \t FILE\n"
             "-u, --unique \t generate a grid with a unique solution\n"
             "-v, --verbose \t verbose output\n"
             "-h, --help \t display this help and exit\n");

      exit(EXIT_SUCCESS);
      break;

    case 'v':
      opt.verbose = true;
      printf("Verbose mode on\n");
      break;

    case 'o':
      // problème d'erreur
      opt.Outputfile = fopen(optarg, "w");
      if (opt.Outputfile == NULL) {
        errx(EXIT_FAILURE, "Something is wrong with the file\n");
      }
      if (optarg == NULL) {
        errx(EXIT_FAILURE, "Something is wrong with the file\n");
      }
      break;

    case 'a':
      opt.all = true;
      break;

    case 'u':
      opt.unique = true;
      break;

    case 'g':
      opt.mode = GENERATOR;
      if (optarg) {
        if (!atoi(optarg)) {
          errx(EXIT_FAILURE, "Need an integer to proceed\n");
        }
        opt.grid_size = atoi(optarg);
        if (opt.grid_size < 3 || opt.grid_size > 15) {
          errx(EXIT_FAILURE, "You have to choose a size between 3 and 15\n");
        }
        break;

      case '?':
        break;

      default:
        errx(EXIT_FAILURE, "Problem with option\n");
        abort();
      }
    }
  }
  if (opt.mode ==
      SOLVER) {   // mode solveur(attention j'ai pas du tout géré les outputs là
                  // et j'ai plus le temps de faire ça mieux)
    char *filename = argv[optind];

    FILE *Inputfile;

    opt.Inputfile = filename;
    if (opt.unique) {
      errx(EXIT_FAILURE,
           "the unique option is not compatible with the SOLVER mode\n");
    }
    if (optind >= argc) {
      errx(EXIT_FAILURE, "i need a grid for the solver mode\n");
    }

    Inputfile = fopen(opt.Inputfile, "r");
    grid_t *hitori_grid = malloc(sizeof(grid_t));
    file_parser(hitori_grid, Inputfile);
    fclose(Inputfile);

    if (opt.all == true) {
      grid_solver(hitori_grid, MODE_ALL);
    }
    if (opt.all == false) {
      hitori_grid = grid_solver(hitori_grid, MODE_FIRST);
      printf("Input grid is consistent : %d/1\n", is_consistent(hitori_grid));
      printf("Input grid is valid : %d/1\n", is_valid(hitori_grid));
      grid_print(hitori_grid, stdout);
      grid_free(hitori_grid);
    }

  } else {   // mode générateur

    if (opt.all) {
      errx(EXIT_FAILURE, "not compatible with the generator option\n");
    }
    if (opt.unique == false) {
      if (opt.Outputfile != NULL) {
        grid_t *hitorigrid = malloc(sizeof(grid_t));
        grid_allocate(hitorigrid, opt.grid_size);
        grid_generate(hitorigrid);
        grid_print(hitorigrid, opt.Outputfile);
      } else {
        grid_t *hitorigrid = malloc(sizeof(grid_t));
        grid_allocate(hitorigrid, (opt.grid_size));
        grid_generate(hitorigrid);
        grid_print(hitorigrid, stdout);
      }
    }
    else {if (opt.Outputfile != NULL) {
        grid_t *hitorigrid = malloc(sizeof(grid_t));
        grid_allocate(hitorigrid, opt.grid_size);
        grid_generatesol(hitorigrid);
        grid_print(hitorigrid, opt.Outputfile);
      } else {
        grid_t *hitorigrid = malloc(sizeof(grid_t));
        grid_allocate(hitorigrid, (opt.grid_size));
        grid_generatesol(hitorigrid);
        grid_print(hitorigrid, stdout);
      }}
  }
  exit(EXIT_SUCCESS);
}
