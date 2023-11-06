
#include<stdio.h>
#include<conio.h>
int a, b, u, v, i, j, ne = 1, node, cost[10][10], visited[10] = {0}, min, mincost = 0;

int main() {

    printf("Enter how many node : ");
    scanf("%d", &node);
    printf("Enter the adjacency matrix : \n");
    for (i = 1; i <= node; i++) {
        for (j = 1; j <= node; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    visited[1] = 1;
    printf("\n");

    while (ne < node) {
        for (i = 1, min = 999; i <= node; i++)
            for (j = 1; j <= node; j++)
                if (cost[i][j] < min)
                    if (visited[i] != 0) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
        if (visited[u] == 0 || visited[v] == 0) {
            printf("\n Edge %d : (%d %d) cost : %d", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\nMinimum cost = %d", mincost);
    getch();
}
