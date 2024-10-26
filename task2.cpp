#include <bits/stdc++.h>
#define ll long long
using namespace std;

template<class t>
int sequentialSearch(const vector<t>list, t target) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i] == target) {
            return i;
        }
    }
    return -1;
}
template<class t>
int recursiveSequentialSearch(vector<t>list, t target,int index=0){
    if(index>=list.size())
        return -1;
    if(list[index]==target)
        return index;
    return recursiveSequentialSearch(list,target,index+1);

}
template<class t>
int recursiveBinarySearch(vector<t>list,t target, int low,int high){
    if(low>high)return -1;
    int mid=low+(high-low)/2;
    if(list[mid]==target)return mid;
    if(target<list[mid])
        return recursiveBinarySearch(list,target,low,mid-1);
    else
        return recursiveBinarySearch(list,target,mid+1,high);

}
template<class t>
int BinarySearch(const vector<t>& list, t target) {
    int low = 0;
    int high = list.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (list[mid] == target) {
            return mid;
        } else if (list[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
int main() {
    //ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    vector<int>list={1,2,3,4};
    cout<<sequentialSearch(list,4)<<endl;
    cout<<recursiveSequentialSearch(list,3)<<endl;
    cout<<recursiveBinarySearch(list,2,0,3)<<endl;
    cout<<BinarySearch(list,3)<<endl;

}
