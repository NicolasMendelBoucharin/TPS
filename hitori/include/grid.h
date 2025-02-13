#ifndef GRID_H
#define GRID_H
#define MAX_GRID_SIZE 15
#include "hitori.h"

typedef enum {black, grey, white} color_t;

typedef struct{
    int size;
    char **grid;
    color_t **color_grid;
} grid_t;

typedef enum {MODE_FIRST, MODE_ALL} mode_t;

void grid_print( grid_t *g, FILE *fd);
void grid_free(const grid_t *g);
void grid_allocate(grid_t *g, int size);
void set_color(int i, int j, grid_t *g, color_t c);
color_t get_color(int i, int j, grid_t *g);
bool is_consistent(grid_t *g);
bool is_valid(grid_t *g);

void grid_select_choice(grid_t *g, int *i, int *j);
void grid_copy(grid_t *gs, grid_t *gd);
grid_t* grid_solver(grid_t *grid, const mode_t mode);


#endif /* GRID */