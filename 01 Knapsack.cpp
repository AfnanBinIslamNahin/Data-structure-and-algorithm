#include <iostream>
using namespace std;

int knapsack(int W, int weights[], int profit[], int n) {
    int B[n + 1][W + 1];

    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (i == 0 || w == 0) {
                B[i][w] = 0;
            } else if (weights[i] <= w) {
                B[i][w] = max(B[i - 1][w], B[i - 1][w - weights[i]] + profit[i]);
            } else {
                B[i][w] = B[i - 1][w];
            }
        }
    }

    return B[n][W];
}

int main() {
    int W = 50;
    int profit[] = {60,100,120};
    int weights[] = {10,20,30};
    int n = sizeof(weights) / sizeof(weights[0]);

    int maxValue = knapsack(W, weights, profit, n);
    cout << "Maximum value obtainable: " << maxValue << endl;

    return 0;
}
