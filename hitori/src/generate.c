#include "generate.h"
#include "grid.h"

char valid_char1[] = {'1', '2', '3', '4', '5', '6', '7', '8',
                      '9', 'a', 'b', 'c', 'd', 'e', 'f'};
void
grid_generate(grid_t *g) {
  srand(time(NULL));

  for (int i = 0; i < g->size; i++) {
    for (int j = 0; j < g->size; j++) {
      g->grid[i][j] = valid_char1[rand() % (g->size)];
      g->color_grid[i][j] = grey;
    }
  }
}

//en théorie ça marche (en tout cas chi presque surement...) mais pas sûr comme j'ai pas de grid free


void
grid_generatesol(grid_t *g) {
  srand(time(NULL));
  while(!is_valid(grid_solver(g, MODE_FIRST))) {
    for (int i = 0; i < g->size; i++) {
      for (int j = 0; j < g->size; j++) {
        g->grid[i][j] = valid_char1[rand() % (g->size)];
        g->color_grid[i][j] = grey;
      }
    }
  }
  
}

