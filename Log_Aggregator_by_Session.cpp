#include <bits/stdc++.h>
using namespace std;

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

int main() {
    vector<pair<int,string>> logs={{1,"userA"},{10,"userB"},{3,"userA"},{12,"userB"},{100,"userA"},{25,"userB"},{105,"userA"}};
    int timeout=5;
    auto ans=aggregateLogs(logs,timeout);
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