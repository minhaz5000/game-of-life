#ifndef CGOL_H
#define CGOL_H

/*Number of Rows in Grid*/
#define ROW 20

/*Number of Columns in Grid*/
#define COLUMN 60

/*Character for Live Cells*/
#define LIVE_CELL_CHAR 'C'

/*Character for Dead Cells*/
#define DEAD_CELL_CHAR '.'

/*Function to check if a Cell is Alive*/
int is_cell_alive(int c);

/*Function to Count Neighbouring Alive Cells*/
int alive_neighbour_cnt(const int arr[][COLUMN], int x, int y);

/*Function to Grid Initialise all element to DEAD_CELL_CHAR*/
void initialize_grid(int arr[][COLUMN]);

/*Print Grid to Screen*/
void print_grid(const int arr[][COLUMN]);

/*New Generation Grid Generate*/
void generate_new_grid(const int grid_1[][COLUMN], int grid_2[][COLUMN]);

#endif
