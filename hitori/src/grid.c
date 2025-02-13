#include "grid.h"
#include "DFS.h"
#include "heuristics.h"
#include "hitori.h"

// fonction pour allouer de l'emplacement mémoire pour une grille
void
grid_allocate(grid_t *g, int size) {
  g->size = size;
  g->grid = malloc(size * sizeof(char *));
  g->color_grid = malloc(size * sizeof(color_t *));
  if (g->grid == NULL) {
    err(EXIT_FAILURE, "grid is null\n");
  }

  for (int i = 0; i < size; i++) {
    g->grid[i] = malloc(size * sizeof(char));
    g->color_grid[i] = malloc(size * sizeof(color_t));
    if (g->grid[i] == NULL) {
      errx(EXIT_FAILURE, "grid is null\n");
    }
    for (int j = 0; j < size; j++) {
      g->grid[i][j] = 0;
      g->color_grid[i][j] = grey;
    }
  }
}

// fonction pour libérer les emplacements mémoire de notre grid
void
grid_free(const grid_t *g) {
  for (int i = 0; i < g->size; i++) {
    free(g->grid[i]);
    free(g->color_grid[i]);
  }
  free(g->color_grid);
  free(g->grid);
  exit(EXIT_SUCCESS);
}

// fonction pour écrire les élements d'une grille (prends en comptes les
// couleurs avec un sous cas si le fichier est pas stdout pour les couleurs)
void
grid_print(grid_t *g, FILE *fd) {
  ;
  if (g == NULL) {
    errx(EXIT_FAILURE, "grid given to print is NULL\n");
  }

  if (fd == NULL) {
    errx(EXIT_FAILURE, "no output file given \n");
  }

  if (fd == stdout) {
    for (int i = 0; i < g->size; i++) {
      for (int j = 0; j < g->size; j++) {
        color_t c = get_color(i, j, g);
        switch (c) {
        case white:
          fprintf(fd, "\033[30;107m %c \033[0m", (g->grid[i][j]));
          break;
        case grey:
          fprintf(fd, "\033[30;100m %c \033[0m", (g->grid[i][j]));
          break;
        case black:
          fprintf(fd, "\033[37;40m %c \033[0m", (g->grid[i][j]));
          break;
        default:
          fprintf(fd, "%c ", (g->grid[i][j]));
          break;
        }
      }
      fprintf(fd, "%c", '\n');
    }
  } else {
    for (int i = 0; i < g->size; i++) {
      for (int j = 0; j < g->size; j++) {
        switch (g->color_grid[i][j]) {
        case white:
          fprintf(fd, "W%c ", (g->grid[i][j]));
          break;
        case grey:
          fprintf(fd, "G%c ", (g->grid[i][j]));
          break;
        case black:
          fprintf(fd, "B%c ", (g->grid[i][j]));
          break;
        default:
          fprintf(fd, "%c ", (g->grid[i][j]));
          break;
        }
      }
      fprintf(fd, "%c", '\n');
    }
  }
}

// fonction pour changer la couleur d'une cellule
void
set_color(int i, int j, grid_t *g, color_t c) {
  if ((i > g->size) || (j > g->size)) {
    errx(EXIT_FAILURE, "the cell doesn't exist\n");
  }
  g->color_grid[i][j] = c;
}

// fonction pour trouver la couleur d'une cellule (en vrai je m'en sers jamais
// j'y pensais pas j'y pensais pas)
color_t
get_color(int i, int j, grid_t *g) {
  if ((i > g->size) || (j > g->size)) {
    errx(EXIT_FAILURE, "the cell doesn't exist\n");
  }
  return g->color_grid[i][j];
}

// fonction pour voir si il y a au moins une celulle grise (en vrai je m'en sers
// jamais j'y pensais pas)
bool
one_grey(grid_t *g) {

  for (int i = 0; i < g->size; i++) {
    for (int j = 0; j < g->size; j++) {
      if (g->color_grid[i][j] == grey) {
        return true;
      }
    }
  }
  return false;
}

// fonction pour voir si notre grille est consistante
bool
is_consistent(grid_t *g) {
  if (consecutive_line(g) || consecutive_row(g) || testwhiteline(g) ||
      testwhiterow(g) || !isapath(g)) {
    return false;
  } else
    return true;
}

// fonction pour voir si notre grille est valide
bool
is_valid(grid_t *g) {
  if (!is_consistent(g) || one_grey(g)) {
    return false;
  } else {
    return true;
  }
}

// fonction qui choisit la meilleure cellule à colorier en blanche ou en noir
// (pour l'instant j'ai mis la première qui apparait parce que j'ai pas d'idée)

void
grid_select_choice(grid_t *g, int *i, int *j) {
  *i = -1;
  *j = -1;
  for (int k = 0; k < g->size; k++) {
    for (int l = 0; l < g->size; l++) {
      if (g->color_grid[k][l] == grey) {
        *i = k;
        *j = l;
      }
    }
  }
}

// fonction qui copie une grille

void
grid_copy(grid_t *gs, grid_t *gd) {
  int size = gs->size;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      gd->grid[i][j] = gs->grid[i][j];
      gd->color_grid[i][j] = gs->color_grid[i][j];
    }
  }
}

// solver de grille avec un mode qui modifie la grille pour la colorier comme il
// faut et un mode qui trouve toute les solutions et qui les affiche toutes
grid_t *
grid_solver(grid_t *grid, mode_t mode) {
  if (mode == MODE_FIRST) {
    heuristicapply(grid);
    if (is_valid(grid)) {

      return grid;

    } else {
      if (!one_grey(grid)) {
        printf("the grid is not resolvable but if I apply the heuristic i get "
               ":\n");
        return (grid);

      } else {
        grid_t *grid1 = malloc(sizeof(grid_t));
        grid_allocate(grid1, grid->size);

        grid_copy(grid, grid1);

        int i;
        int j;
        grid_select_choice(grid1, &i, &j);
        grid1->color_grid[i][j] = black;

        if (is_consistent(grid1)) {
          ;
          return grid_solver(grid1, mode);
        } else {
          grid->color_grid[i][j] = white;
          return grid_solver(grid1, mode);
        }
        grid_print(grid1, stdout);
      }
    }
  } else {   // je zappe le truc de l'option 'o' parce que j'ai rien compris
    heuristicapply(grid);
    static int numero = 0;
    if (is_valid(grid)) {
      numero = numero + 1;
      if (grid != NULL) {
        printf("solution number %d:\n", numero);
        grid_print(grid, stdout);
      }
    } else {
      if (is_consistent(grid)) {
        grid_t *grid1 = malloc(sizeof(grid_t));
        grid_allocate(grid1, grid->size);

        grid_copy(grid, grid1);

        grid_t *grid2 = malloc(sizeof(grid_t));
        grid_allocate(grid2, grid->size);

        grid_copy(grid, grid2);
        int i;
        int j;
        grid_select_choice(grid1, &i, &j);
        grid1->color_grid[i][j] = black;
        grid2->color_grid[i][j] = white;
        grid_solver(grid1, MODE_ALL);
        grid_solver(grid2, MODE_ALL);
      }
    }
    return NULL;
  }
}
