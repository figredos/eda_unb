#include <stdio.h>
#include <stdlib.h>

int minButtonPresses(int f, int s, int g, int u, int d) {
    int *visited = (int *)malloc((f + 1) * sizeof(int));
    for (int i = 1; i <= f; i++) {
        visited[i] = 0;
    }

    int *queue = (int *)malloc((f + 1) * sizeof(int));
    int front = 0;
    int rear = 0;

    queue[rear++] = s;
    visited[s] = 1;

    int pushes = 0; // Initialize to 0
    int levelSize = 1; // Number of elements at the current level

    while (front < rear) {
        int nextLevelSize = 0; // Number of elements in the next level

        for (int i = 0; i < levelSize; i++) {
            int current_floor = queue[front++];

            if (current_floor == g) {
                free(visited);
                free(queue);
                return pushes;
            }

            int up_floor = current_floor + u;
            int down_floor = current_floor - d;

            if (up_floor <= f && visited[up_floor] == 0) {
                visited[up_floor] = 1;
                queue[rear++] = up_floor;
                nextLevelSize++;
            }

            if (down_floor >= 1 && visited[down_floor] == 0) {
                visited[down_floor] = 1;
                queue[rear++] = down_floor;
                nextLevelSize++;
            }
        }

        pushes++; // Increment the pushes after processing the current level
        levelSize = nextLevelSize; // Update the level size for the next level
    }

    free(visited);
    free(queue);

    return -1;  // "use the stairs" case
}

int main() {
    int f, s, g, u, d;
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

    int result = minButtonPresses(f, s, g, u, d);

    if (result == -1) {
        printf("use the stairs\n");
    } else {
        printf("%d\n", result);
    }

    return 0;
}
