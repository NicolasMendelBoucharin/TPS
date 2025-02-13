#include "heuristics.h"

// test si deux même chiffres sandwitchent un autre et dans ce cas on le met en
// blanc
bool
sandwiched(grid_t *g) {
  bool result = false;
  for (int i = 0; i < (g->size); i++) {
    for (int j = 1; j < (g->size - 1); j++) {
      if ((g->grid[i][j - 1] == g->grid[i][j + 1]) &&
          (g->color_grid[i][j] == grey)) {
        g->color_grid[i][j] = white;
        result = true;
      }
    }
    for (int j = 1; j < (g->size - 1); j++) {
      if ((g->grid[j - 1][i] == g->grid[j + 1][i]) &&
          (g->color_grid[j][i] == grey)) {
        g->color_grid[j][i] = white;
        result = true;
      }
    }
  }
  return result;
}

// test si deux même chiffre sont côte à côte et dans ce cas si il y en a un
// troisième dans la ligne/colonne on le met en noir
bool
twoconsecutive(grid_t *g) {
  bool result = false;
  for (int i = 0; i < (g->size); i++) {
    for (int j = 0; j < (g->size - 1); j++) {
      if (g->grid[i][j] == g->grid[i][j + 1]) {
        for (int k = 0; k < g->size; k++) {
          if ((g->grid[i][k] == g->grid[i][j]) &&
              (g->color_grid[i][k] == grey) && (k != j) && (k != j + 1)) {
            g->color_grid[i][k] = black;
            result = true;
          }
        }
      }
    }

    for (int j = 0; j < (g->size - 1); j++) {
      if (g->grid[j][i] == g->grid[j + 1][i]) {
        for (int k = 0; k < g->size; k++) {
          if ((g->grid[k][i] == g->grid[j][i]) &&
              (g->color_grid[k][i] == grey) && (k != j) && (k != j + 1)) {
            g->color_grid[k][i] = black;
            result = true;
          }
        }
      }
    }
  }
  return result;
}

// mets en blanc toutes les cellules adjacentes à une noire
bool
blackadjacent(grid_t *g) {
  bool result = false;
  for (int i = 0; i < g->size; i++) {
    for (int j = 0; j < g->size; j++) {
      if (g->color_grid[i][j] == black) {

        if ((i - 1 >= 0)) {
          if (g->color_grid[i - 1][j] == grey) {
            g->color_grid[i - 1][j] = white;
            result = true;
          }
        }

        if ((i + 1 < g->size)) {
          if (g->color_grid[i + 1][j] == grey) {
            g->color_grid[i + 1][j] = white;
            result = true;
          }
        }

        if ((j - 1 >= 0)) {
          if (g->color_grid[i][j - 1] == grey) {
            g->color_grid[i][j - 1] = white;
            result = true;
          }
        }

        if ((j + 1 < g->size)) {
          if (g->color_grid[i][j + 1] == grey) {
            g->color_grid[i][j + 1] = white;
            result = true;
          }
        }
      }
    }
  }

  return result;
}

// si on trouve un chiffre blanc dès qu'il est dans la même ligne/colonne on le
// met en noir

bool
onewhiteotherblack(grid_t *g) {
  bool result = false;
  for (int i = 0; i < g->size; i++) {
    for (int j = 0; j < g->size; j++) {
      if (g->color_grid[i][j] == white) {
        for (int k = 0; k < g->size; k++) {
          if ((k != j) && (g->grid[i][j] == g->grid[i][k]) &&
              (g->color_grid[i][k] == grey)) {
            g->color_grid[i][k] = black;
            result = true;
          }
        }
      }
    }
    for (int j = 0; j < g->size; j++) {
      if (g->color_grid[i][j] == white) {
        for (int k = 0; k < g->size; k++) {
          if ((k != i) && (g->grid[i][j] == g->grid[k][j]) &&
              (g->color_grid[k][j] == grey)) {
            g->color_grid[k][j] = black;
            result = true;
          }
        }
      }
    }
  }
  return result;
}

// on fait le DFS et on voit si en mettant une case grise en noire on perds la
// consistance et dans ce cas on la mets en blanc
bool
heuristicpath(grid_t *g) {
  bool result = false;
  for (int i = 0; i < g->size; i++) {
    for (int j = 0; j < g->size; j++) {
      if (g->color_grid[i][j] == grey) {
        g->color_grid[i][j] = black;
        bool path = isapath(g);
        if (path == false) {
          g->color_grid[i][j] = white;
          result = true;
        } else {
          g->color_grid[i][j] = grey;
        }
      }
    }
  }
  return result;
}

//on applique toute les heuristiques
void
heuristicapply(grid_t *g) {
  bool truc = true;
  while (truc) {
    truc = (sandwiched(g) || onewhiteotherblack(g) || blackadjacent(g) ||
            twoconsecutive(g) || heuristicpath(g));
  }
}
