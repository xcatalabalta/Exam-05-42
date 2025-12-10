/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:33:26 by fcatala-          #+#    #+#             */
/*   Updated: 2025/12/09 18:13:01 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    size_t rows;
    size_t cols;
    char emp, obs, full;
    char **grid; // 2D Array for the map
} t_map;

// Standard cleanup for the map
static void free_map(t_map *m) 
{
    if (!m->grid) 
		return;
    for (size_t i = 0; i < m->rows; ++i) 
	{
        if (m->grid[i]) 
			free(m->grid[i]);
    }
    free(m->grid);
    m->grid = NULL;
}

static int ft_err(void) 
{
    fputs("map error\n", stderr);
    return -1;
}

static int min3(int a, int b, int c) 
{
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Helper to free our temporary DP matrix
static void free_dp(int **dp, size_t rows) 
{
    if (!dp) 
		return;
    for (size_t i = 0; i < rows; ++i) 
	{
        if (dp[i]) 
			free(dp[i]);
    }
    free(dp);
}

static void solve_and_print(t_map *m) 
{
    // 1. ALLOCATE DP MATRIX (Int 2D Array)
    int **dp = malloc(m->rows * sizeof(int *));
    if (!dp) 
		return;

    for (size_t i = 0; i < m->rows; ++i) 
	{
        dp[i] = calloc(m->cols, sizeof(int));
        if (!dp[i]) 
		{
            free_dp(dp, i); // Clean up partial allocation
            return;
        }
    }

    int max_val = 0;
    size_t max_r = 0, max_c = 0;

    // 2. FILL DP MATRIX
    for (size_t r = 0; r < m->rows; ++r) 
	{
        for (size_t c = 0; c < m->cols; ++c) 
		{
            // If obstacle, value is 0
            if (m->grid[r][c] == m->obs) 
			{
                dp[r][c] = 0;
            }
            // If first row or col, max square is 1 (if not obstacle)
            else if (r == 0 || c == 0) 
			{
                dp[r][c] = 1;
            }
            // DP Logic: 1 + min of 3 neighbors
            else 
			{
                dp[r][c] = 1 + min3(dp[r-1][c], dp[r][c-1], dp[r-1][c-1]);
            }

            // Track the winner
            if (dp[r][c] > max_val) 
			{
                max_val = dp[r][c];
                max_r = r;
                max_c = c;
            }
        }
    }

    // 3. FILL MAP (Backwards from best spot)
    for (int i = 0; i < max_val; ++i) 
	{
        for (int j = 0; j < max_val; ++j) 
		{
            m->grid[max_r - i][max_c - j] = m->full;
        }
    }

    // 4. PRINT
    for (size_t r = 0; r < m->rows; ++r) 
	{
        fputs(m->grid[r], stdout);
        fputc('\n', stdout);
    }

    // 5. CLEANUP DP MATRIX
    free_dp(dp, m->rows);
}

static int ft_isprint(char a, char b, char c)
{
	if (a < 32 || a > 126)
		return 0;
	if (b < 32 || b > 126)
		return 0;
	if (c < 32 || c > 126)
		return 0;
	return 1;
}


static int read_map(FILE *f, t_map *m) 
{
    if (fscanf(f, " %zu %c %c %c\n", &m->rows, &m->emp, &m->obs, &m->full) != 4) 
		return -1;
    if (m->rows == 0 || m->emp == m->obs || m->emp == m->full || m->obs == m->full) 
		return -1;
	if (!(ft_isprint(m->emp, m->obs, m->full)))
	{
		return -1;
	}
    m->grid = calloc(m->rows, sizeof(char *));
    if (!m->grid) 
		return -1;

    char *line = NULL;
    size_t cap = 0;
    ssize_t len;

    len = getline(&line, &cap, f);
    if (len <= 1) 
	{ 
		free(line); 
		return -1; 
	}
    m->cols = len - 1;

    m->grid[0] = malloc(m->cols + 1);
    if (!m->grid[0]) 
	{ 
		free(line);
		return -1; 
	}
    for (size_t c = 0; c < m->cols; c++) 
	{
        if (line[c] != m->emp && line[c] != m->obs) 
		{ 
			free(line); 
			return -1; 
		}
        m->grid[0][c] = line[c];
    }
    m->grid[0][m->cols] = '\0';

    for (size_t r = 1; r < m->rows; ++r) 
	{
        len = getline(&line, &cap, f);
        if ((size_t)len != m->cols + 1) 
		{ 
			free(line); 
			return -1; 
		}
        
        m->grid[r] = malloc(m->cols + 1);
        if (!m->grid[r]) 
		{ 
			free(line); 
			return -1; 
		}
        for (size_t c = 0; c < m->cols; c++) 
		{
            if (line[c] != m->emp && line[c] != m->obs) 
			{ 
				free(line); 
				return -1; 
			}
            m->grid[r][c] = line[c];
        }
        m->grid[r][m->cols] = '\0';
    }
    free(line);
    return 0;
}

static int process(FILE *f) 
{
    t_map m = {0};
    if (read_map(f, &m) != 0) 
	{
        free_map(&m);
        return ft_err();
    }
    solve_and_print(&m);
    free_map(&m);
    return 0;
}

int main(int argc, char **argv) 
{
    if (argc <= 1) 
	{
        if (process(stdin) == 0) 
			fputc('\n', stdout);
    } 
	else 
	{
        for (int i = 1; i < argc; ++i) 
		{
            FILE *fp = fopen(argv[i], "r");
            if (!fp) 
			{
                ft_err();
            } 
			else 
			{
                process(fp);
                fclose(fp);
            }
            fputc('\n', stdout);
        }
    }
    return 0;
}
