#ifndef HEURISTICS_H
#define HEURISTICS_H
#include "grid.h"
#include "DFS.h"

bool sandwiched(grid_t *g);
bool twoconsecutive(grid_t *g);
bool blackadjacent(grid_t *g);
bool onewhiteotherblack(grid_t *g);
bool heuristicpath(grid_t *g);
void heuristicapply(grid_t *g);
#endif /* GRID */