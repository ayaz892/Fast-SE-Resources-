#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 5
#define M 5

int main() {

    // taking input

    int n,m;
    scanf("%d %d ", &n, &m);

    char matrix[N][M];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%c", &matrix[i][j]);
        }
        char temp;
        scanf("%c", &temp);

    }

    // TODO: SOLVE
    
    return 0;
}
