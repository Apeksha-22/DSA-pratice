#include <bits/stdc++.h>
using namespace std;

vector<char> sortByFrequency(string& s) {
    map<char,int> freq;
    for(char c: s) freq[c]++;
    vector<pair<char,int>> arr;
    for(auto &p: freq) arr.push_back(p);
    sort(arr.begin(), arr.end(), [](auto &a, auto &b){
        if(a.second==b.second) return a.first<b.first;
        return a.second>b.second;
    });
    vector<char> ans;
    for(auto &p: arr) ans.push_back(p.first);
    return ans;
}

int main() {
    string str="programming";
    auto res=sortByFrequency(str);
    for(char c:res) cout<<c<<" ";
    cout<<"\n";
    return 0;
}
