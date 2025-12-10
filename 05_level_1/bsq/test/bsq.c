/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:33:26 by fcatala-          #+#    #+#             */
/*   Updated: 2025/12/10 22:36:27 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

typedef struct s_map{
    size_t rows;
    size_t cols;
    char emp, obs, full;
} t_map;

static int ft_err(void) 
{
    fprintf(stderr, "map error\n");
    return -1;
}

static int min3(int a, int b, int c) 
{
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

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

static int solve(FILE *f, t_map *m)
{
    if (fscanf(f, " %zu %c %c %c\n", &m->rows, &m->emp, &m->obs, &m->full) != 4) 
	{
		return -1;
	}
    if (m->rows == 0 || m->emp == m->obs || m->emp == m->full || m->obs == m->full) 
	{
		return -1;
	}
	if (!(ft_isprint(m->emp, m->obs, m->full)))
	{
		return -1;
	}
	int **mat = calloc(m->rows, sizeof(int *));
	if (!mat)
	{
		return -1;
	}
	char *line = NULL;
	size_t cap = 0;
	size_t len = 0;
	int max = 0;
	size_t y_max;
	size_t x_max;
	for (size_t i = 0; i < m->rows; ++i)
	{
		len = getline(&line, &cap, f);
		if (len <= 1)
		{
			free(line);
			free_dp(mat, i);
			return -1;
		}
		if (i == 0)
		{
			m->cols = len - 1;
		}
		else if (m->cols != len -1)
		{
			free(line);
			free_dp(mat, i);
			return -1;
		}
		mat[i] = malloc(m->cols * sizeof(int));
		if (!mat[i])
		{
			free(line);
			free_dp(mat, i);
			return -1;
		}
		for (size_t j = 0; j < len - 1; ++j)
		{
			if (line[j] == m->obs)
			{
				mat[i][j] = 0;
			}
			else if (line[j] == m->emp)
			{
				mat[i][j] = 1;
				if (mat[i][j] > max)
				{
					max = mat[i][j];
					y_max = i;
					x_max = j;
				}
			}
			else
			{
				free(line);
				free_dp(mat, i + 1);
				return -1;
			}
		}
		if (i != 0)
		{
			for (size_t j = 1; j < len -1; ++j)
			{
				
				if (mat[i][j] != 0)
				{
					mat[i][j] = 1 + min3(mat[i -1][j - 1], mat[i][j -1], mat[i -1][j]);
					if (mat[i][j] > max)
					{
						max = mat[i][j];
						y_max = i;
						x_max = j;
					}
				}
			}
		}
	}
	free(line);
	if (max > 0)
	{
		for (size_t yk = 0; yk < (size_t)max; yk++)
		{
			for (size_t xk = 0; xk <(size_t)max; xk++)
			{
				mat[y_max - yk][x_max - xk] = -42;
			}
		}
	}
	for (size_t y = 0; y < m->rows; y++)
	{
		for (size_t x = 0; x < m->cols; x++)
		{
			if (mat[y][x] == -42)
			{
				fprintf(stdout,"%c",m->full); 
			}
			else if (mat[y][x] == 0)
			{
				fprintf(stdout,"%c",m->obs); 
			}
			else
			{
				fprintf(stdout,"%c",m->emp); 
			}
		}
		fprintf(stdout,"\n"); 
	}
    free_dp(mat, m->rows);

	return (0);
}

int main(int argc, char **argv) 
{
	t_map m = {0};
    if (argc <= 1) 
	{
		if(solve(stdin, &m) == 0)
		{
			fprintf(stdout, "\n");
		}
		else
		{
			ft_err();
			return -1;
		}
    } 
	else 
	{
        for (int i = 1; i < argc; ++i) 
		{
            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL) 
			{
                ft_err();
            }
			else 
			{
				if (solve(fp, &m) != 0)
					ft_err();
                fclose(fp);
            }
			fprintf(stdout, "\n");
        }
    }
    return 0;
}
