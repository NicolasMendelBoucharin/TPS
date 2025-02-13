#include "DFS.h"

// compte les chiffres non noirs pour notre DFS plus tard
int
numbernonblack(grid_t *g) {
  int compteur = 0;
  for (int i = 0; i < g->size; i++) {
    for (int j = 0; j < g->size; j++) {
      if (get_color(i, j, g) != black) {
        compteur = compteur + 1;
      }
    }
  }
  return compteur;
}

// fonction qui rend true si deux mêmes chiffres sont blanc dans une ligne et
// false sinon
bool
testwhiteline(grid_t *g) {
  for (int i = 0; i < g->size; i++) {
    for (int j = 0; j < g->size; j++) {
      if (g->color_grid[i][j] == white) {
        for (int k = 0; k < g->size; k++) {
          if ((g->grid[i][k] == g->grid[i][j]) &&
              (g->color_grid[i][k] == white) && (j != k)) {
            return true;
          }
        }
      }
    }
  }
  return false;
}

// pareil mais pour une colonne
bool
testwhiterow(grid_t *g) {
  for (int i = 0; i < g->size; i++) {
    for (int j = 0; j < g->size; j++) {
      if (g->color_grid[j][i] == white) {
        for (int k = 0; k < g->size; k++) {
          if ((g->grid[k][i] == g->grid[j][i]) &&
              (g->color_grid[k][i] == white) && (j != k)) {
            return true;
          }
        }
      }
    }
  }
  return false;
}

// fonction qui rend true si deux noirs consécutifs dans une colonne
bool
consecutive_row(grid_t *g) {
  for (int j = 0; j < g->size; j++) {
    for (int i = 1; i < g->size; i++) {
      if ((get_color(i - 1, j, g) == black) && (get_color(i, j, g) == black)) {
        return true;
      }
    }
  }
  return false;
}

// pareil mais pour une ligne
bool
consecutive_line(grid_t *g) {
  for (int j = 0; j < g->size; j++) {
    for (int i = 1; i < g->size; i++) {
      if ((get_color(j, i - 1, g) == black) && (get_color(j, i, g) == black)) {
        return true;
      }
    }
  }
  return false;
}

// fonction allocate mais pour ma nouvelle structure où le seul truc qui importe
// c'est si on est parcouru (vraiment copié collé de l'autre)

void
parcoured_allocate(parcoured_t *g, int size) {
  g->size = size;
  g->parcoured_status_grid = malloc(size * sizeof(parcoured_status *));
  for (int i = 0; i < size; i++) {
    g->parcoured_status_grid[i] = malloc(size * sizeof(parcoured_status));
    for (int j = 0; j < size; j++) {
      g->parcoured_status_grid[i][j] = unparcoured;
    }
  }
}

// pareil mais pour free
void
parcoured_free(parcoured_t *g) {
  for (int i = 0; i < g->size; i++) {
    free(g->parcoured_status_grid[i]);
  }
  free(g->parcoured_status_grid);
  exit(EXIT_SUCCESS);
}

// fonction recursive de parcours en profondeur (on initialisera i et j avec la
// fonction grid_select_choice avant d'appeler le DFS dans notre fonction
// ispath)
//on fait des sous cas pour pas dépasser les bords
void
DFS(int i, int j, grid_t *g, parcoured_t *par) {
  par->parcoured_status_grid[i][j] = parcoured;
  if ((i - 1 >= 0)) {
    if ((g->color_grid[i - 1][j] != black) &&
        (par->parcoured_status_grid[i - 1][j] == unparcoured)) {
      DFS(i - 1, j, g, par);
    }
  }

  if ((i + 1 < g->size)) {
    if ((g->color_grid[i + 1][j] != black) &&
        (par->parcoured_status_grid[i + 1][j] == unparcoured)) {
      DFS(i + 1, j, g, par);
    }
  }

  if ((j - 1 >= 0)) {
    if ((g->color_grid[i][j - 1] != black) &&
        (par->parcoured_status_grid[i][j - 1] == unparcoured)) {
      DFS(i, j - 1, g, par);
    }
  }

  if ((j + 1 < g->size)) {
    if ((g->color_grid[i][j + 1] != black) &&
        (par->parcoured_status_grid[i][j + 1])) {
      DFS(i, j + 1, g, par);
    }
  }
}


// problème si y'a que des noirs mais ça n'arrive jamais
int
firstnonblackline(grid_t *g) {
  for (int i = 0; i < g->size; i++) {
    for (int j = 0; j < g->size; j++) {
      if (g->color_grid[i][j] != black) {
        return i;
      }
    }
  }
  return 0;
}

// problème si y'a que des noirs mais ça n'arrive jamais
int
firstnonblackrow(grid_t *g) {
  for (int i = 0; i < g->size; i++) {
    for (int j = 0; j < g->size; j++) {
      if (g->color_grid[i][j] != black) {
        return j;
      }
    }
  }
  return 0;
}

// fonction pour voir si il y a un chemin qui parcours toutes les cases non
// noires
bool
isapath(grid_t *g) {
  bool result = false;
  int nonblack = numbernonblack(g);
  int size = g->size;
  parcoured_t par;
  parcoured_t *par1 = &par;
  parcoured_allocate(par1, size);
  int i = firstnonblackline(g);
  int j = firstnonblackrow(g);
  DFS(i, j, g, par1);
  int parcoured_count = 0;
  for (int k = 0; k < size; k++) {
    for (int l = 0; l < size; l++) {
      if (par1->parcoured_status_grid[k][l] == parcoured) {
        parcoured_count = parcoured_count + 1;
      }
    }
  }
  if (parcoured_count == nonblack) {
    result = true;
  }
  return result;
}
