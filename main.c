#include <stdio.h>
#include <stdlib.h>
#include "cgol.h"

int main(void)
{
    int grid_old[ROW][COLUMN];
    int grid_new[ROW][COLUMN];
    int generations;
    int m, n;

    initialize_grid(grid_old);

    printf("Enter number of generations: ");
    scanf("%d", &generations);

    printf("Enter Cells Alive (-1,-1) to end input (x,y):\n");
    scanf("%d ,%d", &m, &n);
    while (m != -1 && n != -1)
    {
        grid_old[m][n] = LIVE_CELL_CHAR;
        scanf("%d ,%d", &m, &n);
    }
    fflush(stdin);
    print_grid(grid_old);
    getchar();
    system("cls");

    int i;
    for (i = generations; i > 1; i -= 2)
    {
        generate_new_grid(grid_old, grid_new);
        print_grid(grid_new);
        getchar();
        system("cls");
        generate_new_grid(grid_new, grid_old);
        print_grid(grid_old);
        getchar();
        system("cls");
    }
    if (i == 1)
    {
        generate_new_grid(grid_old, grid_new);
        print_grid(grid_new);
    }

    return 0;
}
