#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <stdbool.h>
#include <err.h>
main(){
typedef union{
int i;
char tab[4];
} t_u;
t_u u;
u.i = '0';
printf("wtf %d\n", u.tab[0]);
}