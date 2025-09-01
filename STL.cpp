#include <bits/stdc++.h>
using namespace std;

// 1. Vector Sub-sequence Checker
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

// 2. Character Frequency Sorter
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

// 3. Set Intersection Counter
int countCommonElements(set<int>& s1, set<int>& s2) {
    int cnt=0;
    for(auto it=s1.begin(); it!=s1.end(); it++){
        if(s2.find(*it)!=s2.end()) cnt++;
    }
    return cnt;
}

// 4. Reverse K-Group Sub-vectors
void reverseKGroup(vector<int>& vec, int k) {
    int n=vec.size();
    for(int i=0; i+k<=n; i+=k){
        int l=i, r=i+k-1;
        while(l<r) swap(vec[l++], vec[r--]);
    }
}

// 5. Sparse Vector Dot Product
long long sparseDotProduct(map<int,int>& v1, map<int,int>& v2) {
    long long ans=0;
    for(auto &p: v1){
        int idx=p.first, val=p.second;
        auto it=v2.find(idx);
        if(it!=v2.end()) ans += 1LL*val*it->second;
    }
    return ans;
}

// 6. Log Aggregator by Session
map<string, vector<vector<int>>> aggregateLogs(vector<pair<int,string>>& logs, int t) {
    sort(logs.begin(), logs.end()); 
    map<string, vector<vector<int>>> res;
    map<string,int> last;
    for(int i=0;i<logs.size();i++){
        int time=logs[i].first;
        string user=logs[i].second;
        if(res[user].empty() || time-last[user]>t){
            res[user].push_back(vector<int>()); 
        }
        res[user].back().push_back(time);
        last[user]=time;
    }
    return res;
}

// ---------------- MAIN ----------------
int main(){
    // 1. Sub-sequence Checker
    vector<int> s1={1,2,3,4,5,6,7}, s2={3,4,5}, s3={3,5};
    cout << "Q1: " << (isSubSequence(s1,s2) ? "true":"false") << "\n"; // true
    cout << "Q1: " << (isSubSequence(s1,s3) ? "true":"false") << "\n"; // false

    // 2. Character Frequency Sorter
    string str1="programming", str2="banana", str3="aabbc";
    auto res1=sortByFrequency(str1);
    auto res2=sortByFrequency(str2);
    auto res3=sortByFrequency(str3);
    cout << "Q2: "; for(char c:res1) cout<<c<<" "; cout<<"\n";
    cout << "Q2: "; for(char c:res2) cout<<c<<" "; cout<<"\n";
    cout << "Q2: "; for(char c:res3) cout<<c<<" "; cout<<"\n";

    // 3. Set Intersection Counter
    set<int> A={1,2,3,4,5}, B={4,5,6,7,8};
    cout << "Q3: " << countCommonElements(A,B) << "\n"; // 2

    // 4. Reverse K-Group Sub-vectors
    vector<int> v={1,2,3,4,5,6,7,8,9,10}; 
    reverseKGroup(v,3);
    cout << "Q4: "; for(int x:v) cout<<x<<" "; cout<<"\n";

    // 5. Sparse Vector Dot Product
    map<int,int> v1={{0,1},{3,2},{4,3}}, v2={{1,5},{3,4},{4,2}};
    cout << "Q5: " << sparseDotProduct(v1,v2) << "\n"; // 14

    // 6. Log Aggregator by Session
    vector<pair<int,string>> logs={{1,"userA"},{10,"userB"},{3,"userA"},{12,"userB"},{100,"userA"},{25,"userB"},{105,"userA"}};
    auto ans=aggregateLogs(logs,5);
    cout << "Q6:\n";
    for(auto &u: ans){
        cout<<u.first<<": ";
        for(auto &sess:u.second){
            cout<<"[";
            for(int i=0;i<sess.size();i++){
                cout<<sess[i]<<(i+1<sess.size()?",":"");
            }
            cout<<"] ";
        }
        cout<<"\n";
    }

    return 0;
}
