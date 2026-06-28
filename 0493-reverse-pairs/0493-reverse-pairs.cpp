class Solution {
public:
    int ans=0;
    void mergeAndCount(vector<int>& nums,int st,int mid,int end){
        int j=mid+1;
        for(int i=st;i<=mid;i++){
            while(j<=end && (long long) nums[i]>2LL*nums[j]) j++;
            ans+=(j-(mid+1));
        }
        vector<int> temp;
        int i=st;
        j=mid+1;
        while(i<=mid && j<=end){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i++]);
        }
        while(j<=end){
            temp.push_back(nums[j++]);
        }
        for(int i=st;i<=end;i++){
            nums[i]=temp[i-st];
        }
    }
    void mergeSort(vector<int>& nums,int st,int end){
        if(st<end){
            int mid=st+(end-st)/2;
            mergeSort(nums,st,mid);
            mergeSort(nums,mid+1,end);
            mergeAndCount(nums,st,mid,end);
        }
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        mergeSort(nums,0,n-1);
        return ans;;
    }
};