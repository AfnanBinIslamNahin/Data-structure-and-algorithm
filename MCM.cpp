#include <iostream>
using namespace std;

int main() {
    int B[] = {5, 4, 6, 2, 7};
    int n = 5;
    int m[5][5] = {0};
    int s[5][5] = {0};

    for (int d = 1; d < n - 1; d++) {
        for (int i = 1; i < n - d; i++) {
            int j = i + d;
            int min = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + B[i - 1] * B[k] * B[j];
                if (q < min) {
                    min = q;
                    s[i][j] = k;
                }
            }
            m[i][j] = min;
        }
    }

    cout << "Minimum number of multiplications: " << m[1][n - 1] << endl;
    return 0;
}
