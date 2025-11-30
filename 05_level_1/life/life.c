/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 10:15:42 by fcatala-          #+#    #+#             */
/*   Updated: 2025/11/30 11:53:42 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void putchar(int c);
int atoi(const char *str);
ssize_t read(int fd, void *buf, size_t count);
void *malloc(size_t size);
void free(void *ptr);

typedef struct {
    int x;
    int y;
    int pen_down;
} Pen;

void init_board(unsigned char **board, int w, int h)
{
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            board[y][x] = 0;
}

void draw_board(unsigned char **board, int w, int h, Pen *pen)
{
    char cmd;
    while (read(0, &cmd, 1) > 0) {
        if (cmd == 'w' && pen->y > 0) pen->y--;
        else if (cmd == 's' && pen->y < h - 1) pen->y++;
        else if (cmd == 'a' && pen->x > 0) pen->x--;
        else if (cmd == 'd' && pen->x < w - 1) pen->x++;
        else if (cmd == 'x') pen->pen_down = !pen->pen_down;
        
		// The above controls avoid to write or go beyond the boundaries

		/*
		// Protecion in case of beyond boundaries:
        if (pen->pen_down && pen->x >= 0 && pen->x < w && 
            pen->y >= 0 && pen->y < h)
            board[pen->y][pen->x] = 1;
		// Not required
		*/
		if (pen->pen_down)
			board[pen->y][pen->x] = 1;
    }
}

void evolve(unsigned char **board, int w, int h)
{
    unsigned char **new = malloc(h * sizeof(unsigned char *));
    for (int i = 0; i < h; i++)
        new[i] = malloc(w * sizeof(unsigned char));
    
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int n = 0;
            for (int y1 = y - 1; y1 <= y + 1; y1++) {
                for (int x1 = x - 1; x1 <= x + 1; x1++) {
                    if (y1 >= 0 && y1 < h && x1 >= 0 && x1 < w) {
                        if (y1 != y || x1 != x) {
                            if (board[y1][x1]) n++;
                        }
                    }
                }
            }
            new[y][x] = (n == 3 || (n == 2 && board[y][x]));
        }
    }
    
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            board[y][x] = new[y][x];
    
    for (int i = 0; i < h; i++)
        free(new[i]);
    free(new);
}

void show_board(unsigned char **board, int w, int h)
{
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            putchar(board[y][x] ? 'O' : ' ');
        }
        putchar('\n');
    }
}

int main(int argc, char **argv)
{
    if (argc != 4)
        return 1;
    
    int w = atoi(argv[1]);
    int h = atoi(argv[2]);
    int iterations = atoi(argv[3]);
    
    if (w <= 0 || h <= 0 || iterations < 0)
        return 1;
    
    unsigned char **board = malloc(h * sizeof(unsigned char *));
    for (int i = 0; i < h; i++)
        board[i] = malloc(w * sizeof(unsigned char));
    
    init_board(board, w, h);
    
    Pen pen = {0, 0, 0};
    draw_board(board, w, h, &pen);
    
    for (int i = 0; i < iterations; i++)
        evolve(board, w, h);
    
    show_board(board, w, h);
    
    for (int i = 0; i < h; i++)
        free(board[i]);
    free(board);
    
    return 0;
}
