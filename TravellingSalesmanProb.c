#include <stdio.h>
#include <limits.h>

#define MAX 10

int n;
int cost[MAX][MAX];
int visited[MAX];
int minCost = INT_MAX;
int path[MAX], bestPath[MAX];

// Backtracking function
void tsp(int city, int count, int currentCost) {
    visited[city] = 1;
    path[count - 1] = city;

    // If all cities are visited and there is a return path
    if (count == n && cost[city][0] > 0) {
        int totalCost = currentCost + cost[city][0];

        if (totalCost < minCost) {
            minCost = totalCost;

            for (int i = 0; i < n; i++) {
                bestPath[i] = path[i];
            }
        }
    } else {
        // Try all possible next cities
        for (int i = 0; i < n; i++) {
            if (!visited[i] && cost[city][i] > 0) {
                tsp(i, count + 1, currentCost + cost[city][i]);
            }
        }
    }

    visited[city] = 0; // backtrack
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Start from city 0
    tsp(0, 1, 0);

    if (minCost == INT_MAX) {
        printf("No feasible tour exists.\n");
    } else {
        printf("Minimum Cost: %d\n", minCost);
        printf("Optimal Path: ");

        for (int i = 0; i < n; i++) {
            printf("%d -> ", bestPath[i]);
        }
        printf("0\n"); // return to start
    }

    return 0;
}