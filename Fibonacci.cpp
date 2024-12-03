#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef vector<vector<int>>matrix;

matrix matrixmult(matrix A , matrix B) {
    return {
            {
                    A[0][0] * B[0][0] + A[0][1] * B[1][0], A[0][0] * B[0][1] + A[0][1] * B[1][1]},
            {
                    A[1][0] * B[0][0] + A[1][1] * B[1][0], A[1][0] * B[0][1] + A[1][1] * B[1][1]}
    };
}

int fibMM(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    matrix M = {{1, 1}, {1, 0}};
    matrix result = {{1, 0}, {0, 1}};
    
    for (int i = 2; i <= n; ++i) {
        result = matrixmult(result, M);
    }

    return result[0][0];
}
int recursiveFib(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return recursiveFib(n - 1) + recursiveFib(n - 2);
}
int iterativefib(int n) {
    int fib[n + 2];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}
int main() {
    //ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cout << "Enter number : ";
    cin >> n;
    cout << n << "th recursive fibonacci term: " << recursiveFib(n) << endl;
    cout << n << "th iterative(dynamic programming) fibonacci term: " << iterativefib(n) << endl;
    cout << n << "th divide and conquer fib term: " << fibMM(n) << endl;
}
