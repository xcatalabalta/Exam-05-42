/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:22:13 by fcatala-          #+#    #+#             */
/*   Updated: 2025/12/11 08:50:26 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct
{
	int x;
	int y;
	int wr;
} Pen;

static void ft_free(char **array, int rows)
{
	if (array == NULL)
	{
		return;
	}
	for (int i = 0; i < rows; i++)
	{
		free(array[i]);
	}
	free(array);
}

static void fill(char **board, int w, int h)//, Pen *pen)
{
	char c;

	int nx = 0;
	int ny = 0;
	int nwr = 0;
	//(void)pen;
	while (read(0, &c, 1))
	{
		/*
		if (c == 'w' && pen->y > 0)
			pen->y--;
		else if (c == 's' && pen->y < h)
			pen->y++;
		else if (c == 'a' && pen->x > 0)
			pen->x--;
		else if (c == 'd' && pen->x < w)
			pen->x++;
		else if (c == 'x')
			pen->wr = !pen->wr;
		if (pen->wr)
			board[pen->y][pen->x] = 1;
		*/
		if (c == 'w' && ny > 0)
			ny--;
		else if (c == 's' && ny < h)
			ny++;
		else if (c == 'a' && nx > 0)
			nx--;
		else if (c == 'd' && nx < w)
			nx++;
		else if (c == 'x')
			nwr = !nwr;
		if (nwr)
			board[ny][nx] = 1;
	}
}

static void show(char **board, int w, int h)
{
	if (!board)
		return;
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			if (board[y][x])
				putchar('O');
			else
				putchar(' ');
		}
		putchar('\n');
	}
}

static int evolve(char **board, int w, int h)
{
	char **evol = malloc(h * sizeof(char *));
	if (!evol)
		return (1);
	for (int i = 0; i < h; i++)
	{
		evol[i] = calloc(w, sizeof(char));
		if (!evol[i])
		{
			ft_free(evol, i);
			return (1);
		}
	}
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			int n = 0;
			for (int y1 = y - 1 ; y1 <= y + 1; y1++)
			{
				for (int x1 = x - 1; x1 <= x + 1; x1++)
				{
					if (y1 >= 0 && y1 < h && x1 >= 0 && x1 < w)
					{
						if (y1 != y || x1 != x)
						{
							if (board[y1][x1])
								n++;
						}
					}
				}
			}
			evol[y][x] = (n == 3 || (n == 2 && board[y][x]));
		}
	}
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			board[y][x] = evol[y][x];
		}
	}
	ft_free(evol, h);
	return (0);
}

int main (int argc, char **argv)
{
	if (argc != 4)
	{
		return (1);
	}
	int w = atoi(argv[1]);
	int h = atoi(argv[2]);
	int iter = atoi(argv[3]);
	int err = 0;
	if (w <= 0 || h <= 0 || iter < 0)
	{
		return (1);
	}
	char **board = malloc(h * sizeof(char *));
	if (!board)
		return (1);
	for (int i = 0; i < h; i++)
	{
		board[i] = calloc(w, sizeof(char));
		if (!board[i])
		{
			ft_free(board, i);
			return (1);
		}
	}
	//Pen pen={0, 0, 0};
	//Pen pen={0};//Enough to initialize
	//fill (board, w, h, &pen);
	fill (board, w, h);
	//show(board, w, h);//To be used as test
	for (int i = 0; i < iter; i++)
	{
		err = evolve(board, w, h);
		if (err)
			break;
	}
	if (!err)
		show(board, w, h);
	ft_free(board, h);
	return (0);
}

