// BRUTE FORCE
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {        
        int n=points.size();
        vector<pair<int,int>>temp(n);
        for(int i=0; i<n; i++){
            int x = points[i][0];
            int y = points[i][1];
            int z = (x*x) + (y*y);
            temp[i]={z,i};
        }
        sort(temp.begin(),temp.end(),[](auto& a, auto& b){
            return a.first < b.first;
        });
        
        vector<vector<int>>res;

        for(int i=0; i<k; i++){
            res.push_back(points[temp[i].second]);
        }
        return res;
    }
};


//Using Quick Select optimize code

class Solution {
public:
    int dist(vector<int>& p){
        return p[0]*p[0] + p[1]*p[1];
    }

    int partion(vector<vector<int>>& points, int l, int r){
        int pvtdist = dist(points[r]); //starting mein last element lege

        int i=l; //enure karne ke liye pivot se chote element left mein ho
        for(int j=l; j<r; j++){
            if(dist(points[j]) <= pvtdist){
                swap(points[i],points[j]);
                //agar if cond. true hai toh small element ko left mein kar dege or i++
                i++;
            }
        }
        swap(points[i],points[r]);//pivot ki correct position
        return i; // pivot ka correct index;

    }

    void QuickSelect(vector<vector<int>>& points, int l, int r, int k){
        if(l>r)return; // base cond.
        int pvtidx = partion(points,l,r);
        if(pvtidx == k) return; 
        // pvtidx agar k ke equal hai iska mtlb hai k smallest distance mil gye hai
        else if(pvtidx < k)//agar k large hai mtlb k smallest element nhi mile
        QuickSelect(points, pvtidx + 1, r, k);
        else // k se zyda element mil gye hai
        QuickSelect(points, l, pvtidx - 1, k);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        QuickSelect(points,0,points.size()-1,k);
        return vector<vector<int>>(points.begin(),points.begin()+k);
    }
};