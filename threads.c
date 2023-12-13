#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int matA[MAX][MAX]; 
int matB[MAX][MAX]; 

int matSumResult[MAX][MAX];
int matDiffResult[MAX][MAX]; 
int matProductResult[MAX][MAX]; 

int MAX;

void fillMatrix(int matrix[MAX][MAX]) {
    for(int i = 0; i<MAX; i++) {
        for(int j = 0; j<MAX; j++) {
            matrix[i][j] = rand()%10+1;
        }
    }
}

void printMatrix(int matrix[MAX][MAX]) {
    for(int i = 0; i<MAX; i++) {
        for(int j = 0; j<MAX; j++) {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Fetches the appropriate coordinates from the argument, and sets
// the cell of matSumResult at the coordinates to the sum of the
// values at the coordinates of matA and matB.
void* computeSum(void* args) { // pass in the number of the ith thread
    int *coordinates = (int *)args;
    int row = coordinates[0];
    int col = coordinates[1];

    matSumResult[row][col] = matA[row][col] + matB[row][col];
    free(coordinates); // Free memory allocated for coordinates
    pthread_exit(NULL);
}

// Fetches the appropriate coordinates from the argument, and sets
// the cell of matSumResult at the coordinates to the difference of the
// values at the coordinates of matA and matB.
void* computeDiff(void* args) { // pass in the number of the ith thread
    int *coordinates = (int *)args;
    int row = coordinates[0];
    int col = coordinates[1];

    matDiffResult[row][col] = matA[row][col] - matB[row][col];
    free(coordinates); // Free memory allocated for coordinates
    pthread_exit(NULL);
}

// Fetches the appropriate coordinates from the argument, and sets
// the cell of matSumResult at the coordinates to the inner product
// of matA and matB.
void* computeProduct(void* args) { // pass in the number of the ith thread
    int *coordinates = (int *)args;
    int row = coordinates[0];
    int col = coordinates[1];

    matProductResult[row][col] = 0;
    for (int k = 0; k < MAX; k++) {
        matProductResult[row][col] += matA[row][k] * matB[k][col];
    }
    free(coordinates); // Free memory allocated for coordinates
    pthread_exit(NULL);
}
