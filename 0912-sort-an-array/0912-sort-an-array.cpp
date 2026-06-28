class Solution {
public:
void merge(vector<int>& nums,int st,int mid,int end){
    int i=st,j=mid+1;
    vector<int> temp;
    while(i<=mid&&j<=end){
        if(nums[i]<=nums[j]){
            temp.push_back(nums[i]);
            i++;
        }else{
            temp.push_back(nums[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(nums[i]);
            i++;
    }
    while(j<=end){
        temp.push_back(nums[j]);
            j++;
    }
    for(int idx=st;idx<=end;idx++){
        nums[idx]=temp[idx-st];
    }
}
void mergesort(vector<int>& nums,int st,int end){
    if(st<end){
        int mid=st+(end-st)/2;
        mergesort(nums,st,mid);
        mergesort(nums,mid+1,end);
        merge(nums,st,mid,end);
    }
}
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        int st=0,end=n-1;
        mergesort(nums,st,end);
        return nums;
    }
};