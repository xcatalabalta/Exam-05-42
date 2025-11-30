#include "bsq.h"

int main(int argc, char **argv)
{
    if (argc == 1) {
        process_stdin();
    } else {
        for (int i = 1; i < argc; i++) {
            process_file(argv[i]);
            if (i < argc - 1)
                printf("\n");
        }
    }
    return 0;
}

void process_file(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "map error\n");
        return;
    }
    
    t_map *map = read_map(fp);
    fclose(fp);
    
    if (!map) {
        fprintf(stderr, "map error\n");
        return;
    }
    
    if (!solve_bsq(map)) {
        fprintf(stderr, "map error\n");
        free_map(map);
        return;
    }
    
    print_map(map);
    free_map(map);
}

void process_stdin(void)
{
    t_map *map = read_map(stdin);
    
    if (!map) {
        fprintf(stderr, "map error\n");
        return;
    }
    
    if (!solve_bsq(map)) {
        fprintf(stderr, "map error\n");
        free_map(map);
        return;
    }
    
    print_map(map);
    free_map(map);
}

t_map *read_map(FILE *fp)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    
    read = getline(&line, &len, fp);
    if (read <= 0) {
        free(line);
        return NULL;
    }
    
    t_map *map = malloc(sizeof(t_map));
    if (!map) {
        free(line);
        return NULL;
    }
    
    if (!parse_header(line, map)) {
        free(line);
        free(map);
        return NULL;
    }
    free(line);
    
    if (!read_map_data(fp, map)) {
        free_map(map);
        return NULL;
    }
    
    return map;
}

int parse_header(char *line, t_map *map)
{
    int i = 0;
    char *start = line;
    
    while (line[i] && line[i] >= '0' && line[i] <= '9')
        i++;
    
    if (i == 0)
        return 0;
    
    line[i] = '\0';
    map->rows = atoi(start);
    
    if (map->rows <= 0)
        return 0;
    
    i++;
    
    // Skip spaces after the number
    while (line[i] == ' ')
        i++;
    
    if (!line[i])
        return 0;
    
    map->empty = line[i++];
    
    // Skip spaces
    while (line[i] == ' ')
        i++;
    
    if (!line[i])
        return 0;
    
    map->obstacle = line[i++];
    
    // Skip spaces
    while (line[i] == ' ')
        i++;
    
    if (!line[i])
        return 0;
    
    map->full = line[i];
    
    if (map->empty == map->obstacle || map->empty == map->full || 
        map->obstacle == map->full)
        return 0;
    
    if (!is_printable(map->empty) || !is_printable(map->obstacle) || 
        !is_printable(map->full))
        return 0;
    
    return 1;
}

int is_printable(char c)
{
    return c >= 32 && c <= 126;
}

int read_map_data(FILE *fp, t_map *map)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int row = 0;
    
    map->grid = malloc(sizeof(char *) * map->rows);
    if (!map->grid)
        return 0;
    
    map->cols = -1;
    
    while ((read = getline(&line, &len, fp)) > 0 && row < map->rows) {
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';
        else
            read++;
        
        int col_count = read - 1;
        
        if (map->cols == -1) {
            map->cols = col_count;
            if (map->cols <= 0) {
                free(line);
                return 0;
            }
        } else if (col_count != map->cols) {
            free(line);
            return 0;
        }
        
        map->grid[row] = malloc(map->cols + 1);
        if (!map->grid[row]) {
            free(line);
            return 0;
        }
        
        for (int i = 0; i < map->cols; i++) {
            if (line[i] != map->empty && line[i] != map->obstacle) {
                free(line);
                return 0;
            }
            map->grid[row][i] = line[i];
        }
        map->grid[row][map->cols] = '\0';
        row++;
    }
    
    free(line);
    
    if (row != map->rows || map->cols <= 0)
        return 0;
    
    return 1;
}

int solve_bsq(t_map *map)
{
    int **dp = malloc(sizeof(int *) * map->rows);
    if (!dp)
        return 0;
    
    for (int i = 0; i < map->rows; i++) {
        dp[i] = calloc(map->cols, sizeof(int));
        if (!dp[i]) {
            for (int j = 0; j < i; j++)
                free(dp[j]);
            free(dp);
            return 0;
        }
    }
    
    int max_size = 0;
    int max_row = 0;
    int max_col = 0;
    
    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->cols; j++) {
            if (map->grid[i][j] == map->empty) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    int min_val = dp[i-1][j];
                    if (dp[i][j-1] < min_val)
                        min_val = dp[i][j-1];
                    if (dp[i-1][j-1] < min_val)
                        min_val = dp[i-1][j-1];
                    dp[i][j] = min_val + 1;
                }
                
                if (dp[i][j] > max_size) {
                    max_size = dp[i][j];
                    max_row = i;
                    max_col = j;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }
    
    if (max_size > 0) {
        for (int i = max_row - max_size + 1; i <= max_row; i++) {
            for (int j = max_col - max_size + 1; j <= max_col; j++) {
                map->grid[i][j] = map->full;
            }
        }
    }
    
    for (int i = 0; i < map->rows; i++)
        free(dp[i]);
    free(dp);
    
    return 1;
}

void print_map(t_map *map)
{
    for (int i = 0; i < map->rows; i++) {
        printf("%s\n", map->grid[i]);
    }
}

void free_map(t_map *map)
{
    if (map) {
        if (map->grid) {
            for (int i = 0; i < map->rows; i++) {
                if (map->grid[i])
                    free(map->grid[i]);
            }
            free(map->grid);
        }
        free(map);
    }
}
