string Solution::solve(string A) {
    string B = "";
    vector<int>temp(26,0);
    queue<char>q;
    
    for(int i=0; i<A.size(); i++){
        if(temp[A[i] - 'a'] == 0)
        q.push(A[i]);
        temp[A[i] - 'a'] +=1;

        while(!q.empty() && temp[q.front() - 'a'] > 1){
            q.pop();
        }
        if(temp[q.front() - 'a'] == 1) B += q.front();
        else B += '#';
    }
    return B;
}


Question link: https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/
