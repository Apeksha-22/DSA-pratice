#include <bits/stdc++.h>
using namespace std;

bool isSubSequence(vector<int>& s1, vector<int>& s2) {
    int n = s1.size(), m = s2.size();
    for(int i=0; i+m<=n; i++){
        bool ok = true;
        for(int j=0; j<m; j++){
            if(s1[i+j]!=s2[j]){ ok=false; break; }
        }
        if(ok) return true;
    }
    return false;
}

int main() {
    vector<int> s1 = {1,2,3,4,5,6,7};
    vector<int> s2 = {3,4,5};
    cout <<"OUTPUT : " << (isSubSequence(s1,s2) ? "true":"false") << "\n"; 
    return 0;
}
