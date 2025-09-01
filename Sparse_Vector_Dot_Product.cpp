#include <bits/stdc++.h>
using namespace std;

long long sparseDotProduct(map<int,int>& v1, map<int,int>& v2) {
    long long ans=0;
    for(auto &p: v1){
        int idx=p.first, val=p.second;
        auto it=v2.find(idx);
        if(it!=v2.end()) ans += 1LL*val*it->second;
    }
    return ans;
}

int main() {
    map<int,int> v1={{0,1},{3,2},{4,3}}, v2={{1,5},{3,4},{4,2}};
    cout << sparseDotProduct(v1,v2) <<endl;
    return 0;
}
