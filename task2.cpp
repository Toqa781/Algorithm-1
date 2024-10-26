#include <bits/stdc++.h>
#define ll long long
using namespace std;
template<class t>
int recursiveSequentialSearch(vector<t>list, t target,int index=0){
    if(index>=list.size())
        return -1;
    if(list[index]==target)
        return index;
    return recursiveSequentialSearch(list,target,index+1);

}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    vector<int>list={1,2,3,4};
    cout<<recursiveSequentialSearch(list,5);
}
