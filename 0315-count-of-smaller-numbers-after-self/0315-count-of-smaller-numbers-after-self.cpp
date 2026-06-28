class Solution {
public:
    void mergeAndCount(vector<pair<int,int>>& arr,int st,int mid,int end,vector<int> & ans){
        int j=mid+1;
        for(int i=st;i<=mid;i++){
            while(j<=end && arr[i].first>arr[j].first){
                j++;
            }
            ans[arr[i].second]+=j-(mid+1);
        }
        vector<pair<int,int>> temp;
        int i=st;
        j=mid+1;
        while(i<=mid && j<=end){
            if(arr[i].first<=arr[j].first){
                temp.push_back(arr[i++]);
            }
            else{
                temp.push_back(arr[j++]);
            }
        }
        while(i<=mid){
            temp.push_back(arr[i++]);
        }
        while(j<=end){
            temp.push_back(arr[j++]);
        }
        for(int i=st;i<=end;i++){
            arr[i]=temp[i-st];
        }
    }
    void mergeSort(vector<pair<int,int>>& arr,int st,int end,vector<int> & ans){
        if(st<end){
            int mid=st+(end-st)/2;
            mergeSort(arr,st,mid,ans);
            mergeSort(arr,mid+1,end,ans);
            mergeAndCount(arr,st,mid,end,ans);
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        vector<int> ans(n,0);
        mergeSort(arr,0,n-1,ans);
        return ans;
    }
};