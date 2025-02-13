#ifndef DFS_H
#define DFS_H
#include "grid.h"

typedef enum {parcoured, unparcoured} parcoured_status;

typedef struct{
    int size;
    parcoured_status **parcoured_status_grid;
} parcoured_t;



bool consecutive_row(grid_t *g);
bool consecutive_line(grid_t *g);
int numbernonblack(grid_t *g);
bool testwhiteline(grid_t *g);
bool testwhiterow(grid_t *g);

void parcoured_allocate(parcoured_t *g, int size);
void parcoured_free(parcoured_t *g);
void DFS(int i, int j, grid_t *g, parcoured_t *par);
int firstnonblackline(grid_t *g);
int firstnonblackrow(grid_t *g);
bool isapath(grid_t *g);


#endif /* GRID */