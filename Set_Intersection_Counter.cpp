#include <bits/stdc++.h>
using namespace std;

int countCommonElements(set<int>& s1, set<int>& s2) {
    int cnt=0;
    for(auto it=s1.begin(); it!=s1.end(); it++){
        if(s2.find(*it)!=s2.end()) cnt++;
    }
    return cnt;
}

int main() {
    set<int> A={1,2,3,4,5};
    set<int> B={4,5,6,7,8};
    cout << countCommonElements(A,B) << "\n";
    return 0;
}
