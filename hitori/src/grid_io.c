#include "grid_io.h"
#include "grid.h"
#include "hitori.h"

// J'ai un problème je dois avoir loupé un cas d'erreur je n'ai aucun message
// d'erreur quand j'essaie de parser le syntax_incorrect (ne renvoie juste rien)

char valid_char[] = {'1', '2', '3', '4', '5', '6', '7', '8',
                     '9', 'a', 'b', 'c', 'd', 'e', 'f'};

bool
check_char(const char c) {
  for (int i = 0; i < 15; i++) {
    if (c == valid_char[i]) {
      return true;
    }
  }
  return false;
}

bool
check_char_size(const char c, int size) {
  if (size <= 9) {
    return (c <= '0' + size) && (c >= '1');
  } else {
    return (c <= '9' && c >= '1') || ((c <= 'a' + size - 10) && (c >= 'a'));
  }
}

void
file_parser(grid_t *grid, FILE *file) {
  char line[MAX_GRID_SIZE];
  int charexplored;
  int row_count = 0;

  for (int i = 0; i < Max_Buffer; i++) {

    charexplored = fgetc(file);

    if (charexplored == EOF) {

      errx(EXIT_FAILURE, "The grid is empty \n");
    }

    if (charexplored == '\n') {

      if (row_count != 0) {

        break;
      } else {
        continue;
      }
    }

    if (charexplored == '#') {
      while (charexplored != '\n' && charexplored != EOF) {
        charexplored = fgetc(file);
      }
      if (charexplored == EOF) {
        errx(EXIT_FAILURE, "the grid only have commentary \n");
      }
    }

    else if (check_char(charexplored)) {
      if (row_count == MAX_GRID_SIZE) {
        errx(EXIT_FAILURE, "The grid is too big \n");
      }
      line[row_count] = charexplored;
      row_count++;
    } else if ((charexplored != '\t') && (charexplored != ' ')) {

      errx(EXIT_FAILURE, "At least one character is not valid \n");
    }
  }

  grid_allocate(grid, row_count);

  for (int i = 0; i < row_count; i++) {

    if (!check_char_size(line[i], row_count)) {
      errx(EXIT_FAILURE,
           "No number should be higher then the size of the grid \n");
      grid_free(grid);
    }
    grid->grid[0][i] = line[i];
  }
  // Ici on parcours les lignes d'après la première ligne qui nous servait à
  // regarder la taille

  charexplored = fgetc(file);
  int l = 1;
  int c = 0;

  while (charexplored != EOF) {
    switch (charexplored) {
    case '\t':
      break;
    case ' ':
      break;

    case '\n':
      if (c == 0) {
        break;
      }
      if (c != row_count) {
        printf("ici\n");
        grid_free(grid);
        errx(EXIT_FAILURE, "one row is too long \n");
      }
      l++;
      c = 0;
      break;

    default:
      if (!check_char_size(charexplored, row_count)) {
        grid_free(grid);
        errx(EXIT_FAILURE,
             "At least one number is higher than the size of the grid \n");
      }

      if (l >= row_count) {
        printf("non là\n");
        grid_free(grid);
        errx(EXIT_FAILURE, "one line is too long \n");
      }

      if (c >= row_count) {
        printf("en fait ici\n");
        grid_free(grid);
        errx(EXIT_FAILURE, "one colomn is too long \n");
      }

      grid->grid[l][c] = charexplored;
      c++;
      break;
    }
    charexplored = fgetc(file);
  }
  if (grid->grid[row_count - 1][row_count - 1] == '0') {
    grid_free(grid);
    errx(EXIT_FAILURE, "test\n");
  }
}
