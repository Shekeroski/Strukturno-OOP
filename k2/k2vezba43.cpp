#include<iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n][m];

    // Reading the matrix elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Creating a new matrix to store the result
    int result[n][m];

    // Processing the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int s = 0;
            int s1 = 0;

            // Main diagonal elements (i == j)
            if (i == j) {
                // Sum elements to the right in the same row
                for (int k = j + 1; k < m; k++) {
                    s += a[i][k];
                }
                // Sum elements above in the same column
                for (int k = i - 1; k >= 0; k--) {
                    s += a[k][j];
                }
                result[i][j] = s;
            }

            // Antidiagonal elements (i + j == n - 1)
            if (i + j == n - 1) {
                // Sum elements to the left in the same row
                for (int k = j - 1; k >= 0; k--) {
                    s1 += a[i][k];
                }
                // Sum elements below in the same column
                for (int k = i + 1; k < n; k++) {
                    s1 += a[k][j];
                }
                if (i == j) {
                    result[i][j] += s1; // Add both sums if the element is on both diagonals
                } else {
                    result[i][j] = s1;
                }
            }

            // If the element is not on any diagonal, keep it unchanged
            if (i != j && i + j != n - 1) {
                result[i][j] = a[i][j];
            }
        }
    }

    // Output the resulting matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
