#include <bits/stdc++.h>
#define ll long long
using namespace std;
int recursiveFib(int n){
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return recursiveFib(n-1)+ recursiveFib(n-2);
}
int iterativefib(int n) {
    int fib[n+2];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}
int main() {
    //ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cout << "Enter number : ";
    cin >>n;
    cout<<n<<"th recursive fibonacci terms: "<<recursiveFib(n)<< endl;
    cout << n<<"th iterative(dynamic programming) fibonacci terms: "<<iterativefib(n)<<endl;
}
