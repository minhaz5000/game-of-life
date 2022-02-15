#include <stdio.h>
#include "cgol.h"

void initialize_grid(int arr[][COLUMN])
{
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COLUMN; ++j)
        {
            arr[i][j] = DEAD_CELL_CHAR;
        }
    }
}

int is_cell_alive(int c)
{
    return (c == LIVE_CELL_CHAR) ? 1 : 0;
}

int alive_neighbour_cnt(const int arr[][COLUMN], int x, int y)
{
    int count = 0, col, row;

    for (int i = -1; i < 2; ++i)
    {
         for (int j = -1; j < 2; ++j)
        {
            row = (x + i + ROW) % ROW;
            col = (y + j + COLUMN) % COLUMN;

            if (is_cell_alive(arr[row][col]))
            {
                ++count;
            }
        }
    }
    if (arr[x][y] == LIVE_CELL_CHAR)
    {
        --count;
    }

    return count;
}

void generate_new_grid(const int grid_1[][COLUMN], int grid_2[][COLUMN])
{
    int n_count;
    int cell_status;
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COLUMN; ++j)
        {
            n_count = alive_neighbour_cnt(grid_1, i, j);
            cell_status = is_cell_alive(grid_1[i][j]);

            if (!cell_status && n_count == 3)
            {
                    grid_2[i][j] = LIVE_CELL_CHAR;
            }
            else if (cell_status && (n_count < 2 || n_count > 3))
            {
                    grid_2[i][j] = DEAD_CELL_CHAR;
            }
            else
            {
                grid_2[i][j] = grid_1[i][j];
            }
        }
    }
}

void print_grid(const int arr[][COLUMN])
{
    for (int i = 0; i < ROW; ++i)
    {
        printf("%-6d", i);
        for (int j = 0; j < COLUMN; ++j)
        {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}


