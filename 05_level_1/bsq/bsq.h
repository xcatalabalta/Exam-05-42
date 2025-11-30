#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

typedef struct s_map {
    int rows;
    int cols;
    char empty;
    char obstacle;
    char full;
    char **grid;
} t_map;

void process_file(char *filename);
void process_stdin(void);
t_map *read_map(FILE *fp);
int parse_header(char *line, t_map *map);
int is_printable(char c);
int read_map_data(FILE *fp, t_map *map);
int solve_bsq(t_map *map);
void print_map(t_map *map);
void free_map(t_map *map);

#endif
