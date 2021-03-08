#include <stdio.h>

int knapSackBestValue(int W, int K[][W+1], int weights[], int values[], int n);
void knapSackItemsIncluded(int W, int K[][W+1], int weights[], int values[], int n);


int main() {
//  int wt[] = { 1, 2, 4};
//  int val[] = { 7, 5, 3};
//  int W = 3;
    int wt[] = { 5, 5, 3, 4, 7 };
    int val[] = { 15, 15, 8, 13, 7};
    int W = 20;
    int n = sizeof(val) / sizeof(val[0]);

    int K[n+1][W+1];
    printf("Best Possible Value: %d\n", knapSackBestValue(W, K, wt, val, n));
    knapSackItemsIncluded(W, K, wt, val, n);
  
    return 0;
}
 
int knapSackBestValue(int W, int K[][W+1], int weights[], int values[], int n) {
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            if (i == 0 || j == 0) 
                K[i][j] = 0;
            else {
                // Consider not picking this element
                K[i][j] = K[i-1][j];

                if(
                    j >= weights[i-1] && values[i-1] + K[i-1][j-weights[i-1]] > K[i][j]
                ) {
                    K[i][j] = values[i-1] + K[i-1][j-weights[i-1]];
                }
            }
        }
    }
 
    return K[n][W];
}


void knapSackItemsIncluded(int W, int K[][W+1], int weights[], int values[], int n) {
    int arr[n];
    int ctr = 0;
    int i,j;

    int itemIndex;
    for(i = n; i > 0; i--) {
        if(K[i][W] != K[i-1][W]) {
            itemIndex = i - 1;
            arr[ctr++] = itemIndex;
            W -= weights[itemIndex];
        }
    }

    // Print items included
    printf("Items included (weight, value):\n");
    for(i = ctr-1; i >= 0; i--) {
        printf("Item %d: (%d, %d)\n", arr[i] + 1, weights[arr[i]], values[arr[i]]);
    }
}
