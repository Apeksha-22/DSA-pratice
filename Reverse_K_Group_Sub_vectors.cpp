#include <bits/stdc++.h>
using namespace std;

void reverseKGroup(vector<int>& vec, int k) {
    int n=vec.size();
    for(int i=0; i+k<=n; i+=k){
        int l=i, r=i+k-1;
        while(l<r) swap(vec[l++], vec[r--]);
    }
}

int main() {
    vector<int> v={1,2,3,4,5,6,7,8,9,10}; 
    reverseKGroup(v,3);
    for(int x:v) cout<<x<<" "<<endl;
    return 0;
}
