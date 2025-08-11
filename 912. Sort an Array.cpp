class Solution {
public:
    void merge(vector<int>&arr, int s, int mid, int e){
        int l=s, r=mid+1, idx=0;
        vector<int>temp(e-s+1);
        while(l <= mid && r<=e){
            if(arr[l]<=arr[r]){
                temp[idx] = arr[l];
                l++;
                idx++;
            }else{
                temp[idx] = arr[r];
                r++;
                idx++;
            }
        }
        while(l<=mid){
            temp[idx] = arr[l];
            l++;
            idx++;
        }
        while(r<=e){
            temp[idx] = arr[r];
            r++;
            idx++;
        }
        idx = 0;
        while(s <= e){
            arr[s] = temp[idx];
            idx++;
            s++;
        }
    }
    void mergeSort(vector<int>&nums, int s, int e){
        if(s == e) return;
        int mid = s + (e-s)/2;
        mergeSort(nums, s, mid);
        mergeSort(nums, mid+1, e);
        merge(nums, s, mid, e);
    }
    vector<int> sortArray(vector<int>& nums) {
        int s = 0, end = nums.size()-1;
        mergeSort(nums,0,end);
        return nums;
    }
};