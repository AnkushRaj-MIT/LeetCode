class Solution {
public:
    void heapify(vector<int> &nums,int n,int i){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<n && nums[left]>nums[largest]) largest=left;
        if(right<n && nums[right]>nums[largest]) largest=right;
        if(largest!=i){
            swap(nums[largest],nums[i]);
            heapify(nums,n,largest);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=n/2-1;i>=0;i--){
            heapify(nums,n,i);
        }
        while(n>0){
            swap(nums[n-1],nums[0]);
            n--;
            heapify(nums,n,0);
        }
        return nums;
    }
};