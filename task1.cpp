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
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout<<recursiveFib(3);

}
