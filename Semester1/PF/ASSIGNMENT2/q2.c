#include <stdio.h>

#define R 5
#define C 5


int main() {
    char grid[R][C] = {0};
    int i;

    for ( i = 0; i < R; i++) {
        scanf("%c %c %c %c %c\n", &grid[i][0], &grid[i][1], &grid[i][2], &grid[i][3], &grid[i][4]);
    }
    printf("YES");
   
}


    



